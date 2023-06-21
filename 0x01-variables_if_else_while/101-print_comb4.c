#include <stdio.h>

/**
 * main - Print three nimber combination
 *
 * Return: Always 0 (success)
 */
int main(void)
{
int i = '0';

int j = '0';

int k = '0';

while (i <= '7')
	{
		while (k <= '8')
			{
				while (j <= '9')
					{
						if (i < j && j < k)
								{
									putchar(i);
									putchar(j);
									putchar(k);
										if (!(i == '7' && j == '8' && k == '9'))
									{
										putchar(',');
										putchar(' ');
									}
								}
							k++
					}
				k = '0';
				j++;
			}
		j = '0';
		i++;
	}
putchar('\n');
return (0);
}
