#include "../libft.h"

int	isalphatest(char a1, char a2, char a3, char a4, char a5, char a6)
{
	int 	res;
	char	c;
	printf("ft_isalnum:\n");

	c = a1;
	res = ft_isalnum(c);
    printf("%c -> og: %i  ft: %i", a1, isalnum(c), ft_isalnum(c));
    if (c == res)
        printf("    YES :)\n");
    else
        printf("     NO :(\n");

	c = a2; 
	res = ft_isalnum(c);
    printf("%c -> og: %i  ft: %i", a1, isalnum(c), ft_isalnum(c));
    if (c == res)
        printf("    YES :)\n");
    else
        printf("     NO :(\n");

	c = a3; 
	res = ft_isalnum(c);
    printf("%c -> og: %i  ft: %i", a1, isalnum(c), ft_isalnum(c));
    if (c == res)
        printf("    YES :)\n");
    else
        printf("     NO :(\n");

	c = a4; 
	res = ft_isalnum(c);
    printf("%c -> og: %i  ft: %i", a1, isalnum(c), ft_isalnum(c));
    if (c == res)
        printf("    YES :)\n");
    else
        printf("     NO :(\n");

	c = a5; 
	res = ft_isalnum(c);
    printf("%c -> og: %i  ft: %i", a1, isalnum(c), ft_isalnum(c));
    if (c == res)
        printf("    YES :)\n");
    else
        printf("     NO :(\n");

	c = a6; 
	res = ft_isalnum(c);
    printf("%c -> og: %i  ft: %i", a1, isalnum(c), ft_isalnum(c));
    if (c == res)
        printf("    YES :)\n");
    else
        printf("     NO :(\n");
	
	
	printf("\n");
	return (0);
}
