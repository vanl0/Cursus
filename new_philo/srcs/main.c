#include "../header/philo.h"

void    *dead_philo(void *philo)
{
    t_philo *my_philo;

    my_philo = (t_philo *)philo;
    printf("%lu | philo: %d has died, last measl: %ld\n", get_time(my_philo->params.t0), my_philo->num, get_time(my_philo->params.t0) - my_philo->last_meal);
    return ((void *) philo);
}

void    *philosopher(void *philo)
{
    t_philo    *my_philo;

    my_philo = (t_philo *)philo;
    //printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n", my_philo->left->num, my_philo->num, my_philo->right->num, get_time(my_philo->params.t0));
    while(my_philo->alive)
    {
        if ((my_philo->last_meal) && (get_time(my_philo->params.t0) - my_philo->last_meal) > 500)
            return(dead_philo(philo));
        pthread_mutex_lock(&(my_philo->right->fork));
        pthread_mutex_lock(&(my_philo->fork));
        printf("%ld | philo: %d is eating\n", get_time(my_philo->params.t0), my_philo->num);
        usleep(10000);
        my_philo->last_meal = get_time(my_philo->params.t0);
        pthread_mutex_unlock(&(my_philo->right->fork));
        pthread_mutex_unlock(&(my_philo->fork));
        printf("%ld | philo: %d is sleeping\n", get_time(my_philo->params.t0), my_philo->num);
        usleep(10000);
    }
    return (philo);
}

int	main(int argc, char **argv)
{
    t_params    params;
    t_philo     *table;

    table = NULL;
	if (argc > 2)
		return (printf("invalid arg\n"));
    params = params_init(argv);
    create_philo(&table, &params);
    close_threads(&params);
    free_table(&table);
    return (0);
}