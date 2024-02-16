#include "./philo.h"

typedef struct s_philo
{
    t_params            params;
    int                 num;
    struct s_philo     *left;
    struct s_philo     *right;
}   t_philo;

t_philo    *add_philo(t_philo **table, t_params params, int num)
{
    t_philo *new_philo;
    t_philo *last_philo;

    new_philo = malloc(sizeof(t_philo));
    new_philo->params = params;
    new_philo->num = num;

    if (!(*table))
    {
        new_philo->left = NULL;
        new_philo->right = NULL;
        *table = new_philo;
        return (new_philo);
    }
    if (!((*table)->left))
    {
        (*table)->left = new_philo;
        last_philo = *table;
    }
    else
        last_philo = (*table)->left;
    last_philo->right = new_philo;
    new_philo->left = last_philo;
    new_philo->right = *table;
    return (new_philo);
}

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

void    free_table(t_philo **table)
{
    t_philo *next;
    t_philo *current;

    current = *table;
    next = current->right;
    free(current);
    current = next;
    while (current != *table)
    {
        next = current->right;
        printf("free: %d\n", current->num);
        free(current);
        current = next;
    }
    *table = NULL;
}
void    *philosopher(void *philo)
{
    t_philo    *my_philo;

    my_philo = (t_philo *)philo;
    printf("Hola, aqui filosofo %d, derecha: %d, izquierda: %d\n", my_philo->num, my_philo->right->num, my_philo->left->num);
    return ((void *) philo);
}

int	main(int argc, char **argv)
{
    t_params    params;
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
    i = 0;
    new_philo = table;
    while (i < params.number_of_philosophers)
    {
        pthread_create(&(params.th[i]), NULL, philosopher, new_philo);
        new_philo = new_philo->right;
        usleep(100);
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
    free_table(&table);
    return (0);
}