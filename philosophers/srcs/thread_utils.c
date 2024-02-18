#include "../header/philo.h"

void    create_philo(t_philo **table, t_params *params)
{
    int     i;
    t_philo *philosopher_i;
    printf("1\n");

    i = 0;
    while(i < params->number_of_philosophers)
    {
        add_philo(table, *params, i);
        i++;
    }
    i = 0;
    philosopher_i = *table;
    while (i < params->number_of_philosophers)
    {
        pthread_create(&(params->th[i]), NULL, philosopher, philosopher_i);
        philosopher_i = philosopher_i->right;
        usleep(1000);
        i++;
    }
}

void    close_threads(t_params *params)
{
    int i;

    i = 0;
    while (i < params->number_of_philosophers)
    {
        pthread_join(params->th[i], NULL);
        printf("Philosopher %d terminado\n", i);
        i++;
    }
    free(params->th);
}