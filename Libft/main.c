#include "libft.h"

int main (void)
{
	char	data[5];

	//1 - isalpha
	data [0] = 'A';
	data [1] = ' ';
	data [2] =  6 ;
	data [3] = '*';
	data [4] = 'f';
	isalphatest(data);
	//2 - isdigit
	//isalphatest(data);
	//3 - isascii
	data[1] = (char)230;
	isasciitest(data);
	//4 - isalnum
//	isalnumtest(data);
	return (0);
}
