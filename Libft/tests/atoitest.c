#include "libtest.h"

void	atoitest(char *data[5])
{
	printf("ft_atoi:\n");
	char *num;
	int res1;
	int	res2;

	for (int i = 0; i < 5; i++)
	{
		num = data[i];
		res1 = atoi(num);
		res2 = ft_atoi(num);
		printf("%s -> %i : %i", num, res1, res2);
		int_checker(res1, res2);
	}
	printf("\n");
	return;
}
