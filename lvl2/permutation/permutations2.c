#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void sorted(char *s)
{
  char tem;
  for(int i = 0; s[i]; i++)
  {
    for(int j = i + 1; s[j]; j++)
    {
      if (s[i] > s[j])
      {
        tem = s[i];
        s[i] = s[j];
        s[j] = tem;
      }
    }
  }
}

void p(char *s, char *r, int *u, int d, int len)
{
  if (d == len)
  {
    for (int i = 0; i < len; i++)
    {
      write(1, &r[i], 1);
    }
    write(1, "\n", 1);
    return ;
  }
  for (int i = 0; i < len; i++)
  {
    if (u[i])
      continue;
    u[i] = 1;
    r[d] = s[i];
    p(s, r, u, d + 1, len);
    u[i] = 0;
  }
}

int main(int ac, char **av)
{
  if (ac != 2)
    return (1);
  int i = 0;
  while (av[1][i])
    i++;
  int len = i;
  char *r = malloc(len + 1);
  int *u = calloc(len, sizeof(int));
  sorted(av[1]);
  p(av[1], r, u, 0, len);
  free(r);
  free(u);
}