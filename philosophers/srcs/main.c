#include "../header/philo.h"

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


t_params    params_init(char **argv)
{
    t_params    params;
    params.number_of_philosophers = ft_atoi(argv[1]);
    params.th = malloc((params.number_of_philosophers) * sizeof(pthread_t));
    params.time = malloc(sizeof(long int));
    params.alive = malloc(sizeof(int));
    *(params.time) = 0;
    *(params.alive) = 1;
    return (params);
}

void    *philosopher(void *philo)
{
    t_philo    *my_philo;
    int         alive;
    int         fork;

    fork = 1;
    alive = 1;
    my_philo = (t_philo *)philo;
    printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n",\
     my_philo->left->num, my_philo->num, my_philo->right->num, *(my_philo->time));
    while (*(my_philo->alive))
	{

    }
    return ((void *) philo);
}

int	main(int argc, char **argv)
{
    t_params    params;
    pthread_t   clock_th;
    t_philo     *table;

    table = NULL;
	if (argc > 2)
		return (printf("invalid arg\n"));
    params = params_init(argv);
    pthread_create(&clock_th, NULL, ft_clock, params.time);
    pthread_detach(clock_th);
    create_philo(&table, &params);
    close_threads(&params);
    free_table(&table);
    free(params.time);
    return (0);
}