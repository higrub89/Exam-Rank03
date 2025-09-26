#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int ac, char **av)
{
  char buffer[1024];
  ssize_t len;
  ssize_t i;
  int j;

  if (ac != 2 || av[1][0] == '\0')
    return (1);
  while ((len = read(0, buffer, 1024)) > 0)
  {
    if (len < 0)
    {
      perror("Error");
      return (1);
    }
    buffer[len] = '\0';
    i = 0;
    while (i < len)
    {
      j = 0;
      while (av[1][j] != '\0' && buffer[i + j] == av[1][j])
        j++;
      if (av[1][j] == '\0')
      {
        while (j > 0)
        {
          printf("*");
          j--;
        }
        i += strlen(av[1]);
      }
      else
      {
        printf("%c", buffer[i]);
        i++;
      }
    }
  }
  return (0);
}