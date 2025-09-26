#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>


# define MAX_CANDIDATES 2

bool is_solution(int *a, int *nums, int n, int target)
{
  int i = 0;
  int res = 0;

  while(i < n)
  {
    if (a[i])
      res += nums[i];
    i++;
  }
  if (res == target)
    return (true);
  return (false);
}

void print_solution(int *a, int *nums, int n)
{
  int i;

  i = 0;
  while (i < n)
  {
    if (a[i])
      printf("%d", nums[i]);
    i++;
  }
  printf("\n");
}

void build_candidate(int *c, int *nc)
{
  c[0] = 1;
  c[1] = 0;
  *nc = 2;
}

void make_move(int *a, int k, int value)
{
  a[k] = value;
}

void unmake_move(int *a, int k, int value)
{
  (void)a;
  (void)k;
  (void)value;
}

void powerset(int *a, int *nums, int k, int n, int target)
{
  int candidates[2];
  int nc;
  int i;

  if (k == n)
  {
    if (is_solution(a, nums, n, target))
      print_solution(a, nums, n);
    return ;
  }
  else
  {
    build_candidate(candidates, &nc);
    i = -1;
    while(++i < nc)
    {
      make_move(a, k, candidates[i]);
      powerset(a, nums, k + 1, n, target);
      unmake_move(a, k, candidates[i]);
    }
  }
}

int main(int ac, char **av)
{
  int *a;
  int *nums;
  int n;
  int target;
  int i;
  int k;

  if (ac == 1)
    return (1);
  n = ac -2;
  target = atoi(av[1]);
  a = calloc(n, sizeof(int));
  if (!nums)
    return (free(a), 1);
  i = -1;
  k = 0;
  while (++i < n)
    nums[i] = atoi(av[i + 2]);
  powerset(a, nums, k, n, target);
  return (free(a), free(nums), 0);
}