#include "../header/philo.h"

t_philo    *add_philo(t_philo **table, t_params params, int num)
{
    t_philo *new_philo;
    t_philo *last_philo;

    new_philo = malloc(sizeof(t_philo));
    new_philo->params = params;
    new_philo->num = num;
    pthread_mutex_init(&(new_philo->fork), NULL);
    new_philo->last_meal = 0;
    new_philo->alive = 1;
    if (!(*table))
    {
        new_philo->left = NULL;
        new_philo->right = NULL;
        *table = new_philo;
        return (new_philo);
    }
    if (!((*table)->left))
        last_philo = *table;
    else
        last_philo = (*table)->left;
    last_philo->right = new_philo;
    new_philo->left = last_philo;
    new_philo->right = *table;
    (*table)->left = new_philo;
    return (new_philo);
}

void    free_table(t_philo **table)
{
    t_philo *next;
    t_philo *current;

    current = *table;
    next = current->right;
    printf("free: %d\n", current->num);
    pthread_mutex_destroy(&(current->fork));
    free(current);
    current = next;
    while (current != *table)
    {
        next = current->right;
        printf("free: %d\n", current->num);
        pthread_mutex_destroy(&(current->fork));
        free(current);
        current = next;
    }
    *table = NULL;
}