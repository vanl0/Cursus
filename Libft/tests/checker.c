#include "../libft.h"

int	char_checker(char res1, char res2)
{
	if (res1 == res2)
	{
		printf("	YES  :)\n");
		return (0);
	}
	else
	{
		printf("	NO   :(\n");
		return (1);
	}
}

int int_checker(int res1, int res2)
{
    if (res1 == res2)
    {
        printf("    YES  :)\n");
        return (0);
    }
    else
    {
        printf("    NO   :(\n");
        return (1);
    }
}	
