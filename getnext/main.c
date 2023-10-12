#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *s;

    s = get_next_line(fd);
    printf("s:%s\n", s);
    free(s);
    s = get_next_line(fd);
    printf("s:%s\n", s);
    free(s);
    
   /*printf("0: %c\n", s[0]);
    printf("1: %c\n", s[1]);
    printf("2: %c\n", s[2]);
    printf("3: %c\n", s[3]);
    printf("4: %c\n", s[4]);
    printf("5: %c\n", s[5]);
    printf("6: %c\n", s[6]);
    printf("7: %s\n", s[7]);*/

    //s = get_next_line(fd);
    //printf("2:\n%s\n", s);
    
    free(s);
    close(fd);
    return (0);
}