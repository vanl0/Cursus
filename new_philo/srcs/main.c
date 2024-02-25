#include "../header/philo.h"

void    *dead_philo(t_philo *my_philo)
{
    *(my_philo->params.death_report) = my_philo->num;
    printf("%lu | philo: %d has died, last meal: %ld\n", get_time(my_philo->params.t0), my_philo->num, my_philo->last_meal);
    return ((void *) my_philo);
}

void    *philosopher(void *philo)
{
    t_philo    *my_philo;

    my_philo = (t_philo *)philo;
    while(*(my_philo->params.death_report) < 0)
    {
        if ((my_philo->last_meal) && ((get_time(my_philo->params.t0) - my_philo->last_meal) > my_philo->params.time_to_die))
            return(dead_philo(my_philo));
        pthread_mutex_lock(&(my_philo->right->fork));
        if (*(my_philo->params.death_report) >= 0)
            return (philo);
        pthread_mutex_lock(&(my_philo->fork));
        if (*(my_philo->params.death_report) >= 0)
            return (philo);
        printf("%ld | philo: %d is eating\n", get_time(my_philo->params.t0), my_philo->num);
        usleep(my_philo->params.time_to_eat);
        my_philo->last_meal = get_time(my_philo->params.t0);
        pthread_mutex_unlock(&(my_philo->right->fork));
        pthread_mutex_unlock(&(my_philo->fork));
        if (*(my_philo->params.death_report) >= 0)
            return (philo);
        printf("%ld | philo: %d is sleeping\n", get_time(my_philo->params.t0), my_philo->num);
        usleep(my_philo->params.time_to_sleep);
    }
    return (philo);
}

void    *mastermind(void *table_ptr)
{
    t_philo **table;
    int     *death_report;

    table = (t_philo **)table_ptr;
    death_report = (*table)->params.death_report;
    while((*death_report) < 0)
    {
        usleep(1);
    }
    printf("DEP philosopher %d\n", *death_report);
    return (table_ptr);
}

int	main(int argc, char **argv)
{
    t_params    params;
    t_philo     *table;
    pthread_t   master;

    table = NULL;
	if (argc < 5 || argc > 6)
		return (printf("invalid args\n"));
    params = params_init(argv);
    pthread_create(&master, NULL, mastermind, &table);
    create_philo(&table, &params);
    pthread_join(master, NULL);
    close_threads(&params);
    free_table(&table);
    return (0);
}

    //printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n", my_philo->left->num, my_philo->num, my_philo->right->num, get_time(my_philo->params.t0));
