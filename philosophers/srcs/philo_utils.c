#include "../header/philo.h"

void    *dead_philo(t_philo *my_philo)
{
    *(my_philo->params.death_report) = my_philo->num;
    printf("%lu | philo: %d has died, last meal: %ld\n", get_time(my_philo->params.t0), my_philo->num, my_philo->last_meal);
    return ((void *) my_philo);
}

void    take_fork(t_philo *my_philo, pthread_mutex_t *fork)
{
    if (*(my_philo->params.death_report) < 0)
    {
        pthread_mutex_lock(fork);
        printf("%ld | philo: %d has taken a fork\n", get_time(my_philo->params.t0), my_philo->num);
    }
}

void    eat(t_philo *my_philo)
{
    if (*(my_philo->params.death_report) < 0)
    {
    my_philo->last_meal = get_time(my_philo->params.t0);
    printf("%ld | philo: %d is eating\n", get_time(my_philo->params.t0), my_philo->num);
    usleep(my_philo->params.time_to_eat);
    pthread_mutex_unlock(&(my_philo->right->fork));
    pthread_mutex_unlock(&(my_philo->fork));
    }
}

