#include "libft.h"
#include "libtest.h"

void	isalphatest(char data[5])
{
	printf("ft_isalpha:\n");
	char c;
	int res1;
	int	res2;

	for (int i = 0; i < 5; i++)
	{
		c = data[i];
		res1 = isalpha(c);
		res2 = ft_isalpha(c);
		printf("%c -> %i : %i", c, res1, res2);
		int_checker(res1, res2);
	}
	printf("\n");
	return;
}

