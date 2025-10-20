#include <stdio.h>
#include <stdlib.h>

int is_val(char *s)
{
    int open = 0;
    int close = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(')
            open++;
        else if (s[i] == ')')
        {
            if (open > 0)
                open--;
            else
                close++;
        }
    }
    return open + close;
}

void rip(char *s, int m_fix, int n_fix, int pos)
{
    if (m_fix == n_fix && !is_val(s))
    {
        puts(s);
        return ;
    }
    for (int i = pos; s[i]; i++)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            int c = s[i];
            s[i] = ' ';
            rip(s, m_fix, n_fix + 1, pos);
            s[i] = c;
        }
    }
}

int main(int ac, char **av)
{
    int m_fix = is_val(av[1]);
    rip(av[1], m_fix, 0, 0);
}
