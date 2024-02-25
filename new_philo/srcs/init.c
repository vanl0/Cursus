#include "../header/philo.h"

t_params    params_init(char **argv)
{
    t_params        params;
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    params.t0 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    params.number_of_philosophers = ft_atoi(argv[1]);
    params.th = malloc((params.number_of_philosophers) * sizeof(pthread_t));

    return (params);
}

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