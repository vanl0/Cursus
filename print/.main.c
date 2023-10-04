#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int a;
    int b;
    printf("\n---------------TEXTO---------------\n");
     a =  ft_printf("\001\002\007\v\010\f\r\n");
    printf("\n-----------------------------------\n");
     b =  printf("\001\002\007\v\010\f\r\n");
    printf("\n-----------------------------------\n");
    printf("ft: %i  og: %i\n\n", a, b);
    /*printf("\n------------PUNTEROS---------------\n");
    int *pa = NULL;
     a =  ft_printf("%p", pa);
    printf("\n-----------------------------------\n");
     b =  printf("%p", pa);
    printf("\n-----------------------------------\n");
    printf("ft: %i  og: %i\n\n", a, b);

    printf("\n-----------HEXADECIMAL-------------\n");
    int x = INT_MIN;
    a =  ft_printf("%x", x);
    printf("\n-----------------------------------\n");
    b =  printf("%x", x);
    printf("\n-----------------------------------\n");
    printf("ft: %i  og: %i\n\n", a, b);
    
    printf("\n-------------STRING----------------\n");
    char *s = (char *)NULL;
    a =  ft_printf("%s", s);
    printf("\n-----------------------------------\n");
    b =  printf("%s", s);
    printf("\n-----------------------------------\n");
    printf("ft: %i  og: %i\n\n", a, b);

   printf("\n---------------INT------------------\n");
    int z = -10;
    long int lz = (long int)z;
    a =  ft_printf("%d", z);
    printf("\n-----------------------------------\n");
    b =  printf("%d", z);
    printf("\n-----------------------------------\n");
    printf("ft: %i  og: %i\n\n", a, b);*/
}
