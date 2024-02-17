#include "../header/philo.h"


t_params    params_init(char **argv)
{
    t_params params;
    params.number_of_philosophers = ft_atoi(argv[1]);
    /*params.time_to_die = ft_atoi(argv[2]);
    params.time_to_eat = ft_atoi(argv[3]);
    params.time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        params.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    else
        params.number_of_times_each_philosopher_must_eat = 0;
    printf("\n- number_of_philosophers: %d\n", params.number_of_philosophers);
    printf("- time_to_die: %d\n", params.time_to_die);
    printf("- time_to_eat: %d\n", params.time_to_eat);
    printf("- time_to_sleep: %d\n", params.time_to_sleep);
    printf("- number_of_times_each_philosopher_must_eat: %d\n", params.number_of_times_each_philosopher_must_eat);
    printf("\n\n\n");*/
    params.th = malloc((params.number_of_philosophers) * sizeof(pthread_t));
    return (params);
}

void    *philosopher(void *philo)
{
    t_philo    *my_philo;

    my_philo = (t_philo *)philo;
    printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n", my_philo->left->num, my_philo->num, my_philo->right->num, my_philo->time);
    return ((void *) philo);
}

int	main(int argc, char **argv)
{
    t_params    params;
    pthread_t   clock_th;
    int         i;
    t_philo     *table;
    t_philo     *new_philo;

    table = NULL;
    i = 0;
	if (argc > 2)
		return (printf("invalid arg\n"));
    params = params_init(argv);
    while(i < params.number_of_philosophers)
    {
        add_philo(&table, params, i);
        i++;
    }
    pthread_create(&clock_th, NULL, ft_clock, &table);
    i = 0;
    new_philo = table;
    while (i < params.number_of_philosophers)
    {
        pthread_create(&(params.th[i]), NULL, philosopher, new_philo);
        new_philo = new_philo->right;
        i++;
        usleep(10000);
    }
    i = 0;
    while (i < params.number_of_philosophers)
    {
        pthread_join(params.th[i], NULL);
        printf("Philosopher %d terminado\n", i);
        i++;
    }
    //table = NULL;
    free_table(&table);
    pthread_join(clock_th, NULL);
    free(params.th);
    return (0);
}