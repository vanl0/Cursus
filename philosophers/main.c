#include "./philo.h"

t_params    params_init(char **argv)
{
    t_params params;
    params.number_of_philosophers = ft_atoi(argv[1]);
    params.time_to_die = ft_atoi(argv[2]);
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
    printf("\n\n\n");
    params.th = malloc((params.number_of_philosophers) * sizeof(pthread_t));
    return (params);
}

void    *philosopher(void *params)
{
    t_params    *param;

    param = (t_params *)params;
    printf("Hola\n");
    return ((void *) param);
}

int	main(int argc, char **argv)
{
    t_params    params;
    int         i;

    i = 0;
	if (argc < 5 || argc > 6)
		return (printf("invalid arg\n"));
    params = params_init(argv);
    while (i < params.number_of_philosophers)
    {
        pthread_create(&(params.th[i]), NULL, philosopher, &params);
        i++;
    }
    i = 0;
    while (i < params.number_of_philosophers)
    {
        pthread_join(params.th[i], NULL);
        printf("Philosopher %d terminado\n", i);
        i++;
    }
    free(params.th);
    return (0);
}