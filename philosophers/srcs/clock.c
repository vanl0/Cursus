#include "../header/philo.h"

void    set_time(t_philo **table, long int time)
{
    t_philo *current;

    current = *table;
    current->time = time;
    current = current->right;
    while (current != (*table))
    {
        current->time = time;
        current = current->right;
    }
}

void    *ft_clock(void *table_ptr)
{
    t_philo **table;
    struct timeval  tv;
    long int        t0;
    long int        t;

    table = (t_philo **)table_ptr;
    gettimeofday(&tv, NULL);
    t0 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    while (*table)
    {
        gettimeofday(&tv, NULL);
        t = tv.tv_sec * 1000 + tv.tv_usec / 1000 - t0;
        set_time(table, t);
        usleep(100);
        //printf("t: %ld\n", t);
    }
    return (table_ptr);
}