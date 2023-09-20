#include "libft.h"

void	isasciitest(char data[5])
{
	printf("ft_isascii:\n");
	char c;
	int res1;
	int	res2;

	for (int i = 0; i < 5; i++)
	{
		c = data[i];
		res1 = isascii(c);
		res2 = ft_isascii(c);
		printf("%c -> %i : %i", c, res1, res2);
		int_checker(res1, res2);
	}
	printf("\n");
	return;
}

	



