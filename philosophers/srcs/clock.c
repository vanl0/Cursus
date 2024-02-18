#include "../header/philo.h"

void    *ft_clock(void *counter)
{
    long int        *timer;
    struct timeval  tv;
    long int        t0;
    long int        t;

    timer = (long int *)counter;
    *timer = 0;
    gettimeofday(&tv, NULL);
    t0 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    while (1)
    {
        gettimeofday(&tv, NULL);
        t = tv.tv_sec * 1000 + tv.tv_usec / 1000 - t0;
        *timer = t;
        printf("t: %ld, %p\n", *timer, timer);
        usleep(1000);
    }
    return (counter);
}