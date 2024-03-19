/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 12:57:43 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/01/16 13:03:10 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct  s_params
{
    pthread_t   *th;
    int         number_of_philosophers;
    int         time_to_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         number_of_times_each_philosopher_must_eat;
    long int    t0;
    int         *death_report;
}   t_params;

typedef struct s_philo
{
    t_params            params;
    int                 num;
    pthread_mutex_t     fork;
    long int            last_meal;
    int                 n_meals;
    struct s_philo     *left;
    struct s_philo     *right;
}   t_philo;

//UTILS
int         ft_atoi(char *str);
void        create_table(t_philo **table, t_params *params);
void	    start_threads(t_philo **table, t_params *params);
void        create_philo(t_philo **table, t_params *params);
t_philo    *add_philo(t_philo **table, t_params params, int num);
void        close_threads(t_params *params);
void        free_table(t_philo **table);
void        print_action(t_philo *my_philo, char *msg);
//PHILO
void        *dead_philo(t_philo *my_philo);
void        take_fork(t_philo *my_philo, pthread_mutex_t *fork);
void        eat(t_philo *my_philo);
void        check_n_meals(t_philo **table);

//TIME
long int    get_time(long int t0);
//INIT
t_params    params_init(char **argv);

void        *philosopher(void *philo);
#endif
