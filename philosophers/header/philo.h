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
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
}   t_params;

typedef struct s_philo
{
    t_params            params;
    int                 num;
    long int           time;
    struct s_philo     *left;
    struct s_philo     *right;
}   t_philo;

//UTILS-----------------------
int         ft_atoi(const char *str);
void    *ft_clock(void *table_ptr);
void    set_time(t_philo **table, long int time);
//TABLE-----------------------
t_philo    *add_philo(t_philo **table, t_params params, int num);
void        free_table(t_philo **table);

#endif
