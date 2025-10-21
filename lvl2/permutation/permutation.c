#include <stdio.h>
#include <stdlib.h>

void sorted(char *s)
{
	char tem;
	for (int i = 0; s[i]; i++)
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

void permutation(char *s, char *result, int *used, int dep, int len)
{
	if (dep == len)
	{
		for (int i = 0; i < len; i++)
		{
			write(1, &result[i], 1);
		}
		write(1, "\n", 1);
	}
	for (int i = 0; i < len; i++)
	{
		if (used[i])
			continue ;
		used[i] = 1;
		result[dep] = s[i];
		permutation(s, result, used, dep + 1, len);
		used[i] = 0;
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
	char *result = malloc(len + 1);
	int *used = calloc(len, sizeof(int));
	sorted(av[1]);
	permutation(av[1], result, used, 0, len);
	free(result);
	free(used);
	return (0);
}