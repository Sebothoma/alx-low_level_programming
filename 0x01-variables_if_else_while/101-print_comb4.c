#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Print three nimber combination
 *
 * Return: Always 0 (success)
 */
int main(void)
{
int d = '0';
int p = '0';
int q = '0';

while (d <= '7')
{
while (p <= '8')
{
while (q <= '9')
{
if (d < p && p < q)
{
putchar(d);
putchar(p);
putchar(q);
if (!(d == '7' && p == '8' && q == '9'))
{
putchar(',');
putchar(' ');
}
}
q++
}
q = '0';
p++;
}
p = '0';
d++;
}
putchar('\n');
return (0);
}
