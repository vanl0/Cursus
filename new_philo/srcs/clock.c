#include "../header/philo.h"

long int    get_time(long int t0)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - t0);
}