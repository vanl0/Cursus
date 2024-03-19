#include "../header/philo.h"

void    *dead_philo(t_philo *my_philo)
{
    *(my_philo->params.death_report) = my_philo->num;
    printf("%lu | philo: %d has died, last meal: %ld\n", get_time(my_philo->params.t0), my_philo->num, my_philo->last_meal);
    return ((void *) my_philo);
}

void    take_fork(t_philo *my_philo, pthread_mutex_t *fork)
{
        pthread_mutex_lock(fork);
        print_action(my_philo, "has taken a fork");
}

void    eat(t_philo *my_philo)
{
    my_philo->last_meal = get_time(my_philo->params.t0);
    print_action(my_philo, "is eating");
    usleep(my_philo->params.time_to_eat);
    pthread_mutex_unlock(&(my_philo->right->fork));
    pthread_mutex_unlock(&(my_philo->fork));
}

void    print_action(t_philo *my_philo, char *msg)
{
    if (*(my_philo->params.death_report) < 0)
        printf("%ld | philo : %d %s\n", get_time(my_philo->params.t0), my_philo->num, msg);
    return;
}