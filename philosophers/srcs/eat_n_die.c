/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_n_die.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:26:15 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/03/26 15:27:00 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	print_action(t_philo *philo, char *msg)
{
    pthread_mutex_lock(&(philo->val.write_mutex));
	printf("%ld %d %s\n", get_time(philo->val.t0), philo->num, msg);
    pthread_mutex_unlock(&(philo->val.write_mutex));
	return ;
}

void    take_fork(pthread_mutex_t *fork, t_philo *philo)
{
    pthread_mutex_lock(fork);
    print_action(philo, "has taken a fork");
}

void    eat(t_philo *philo)
{
    philo->last_meal = get_time(philo->val.t0);
    print_action(philo, "is eating");
    usleep(philo->val.eat);
    pthread_mutex_unlock(&philo->fork);
    pthread_mutex_unlock(&philo->right->fork);
    print_action(philo, "is sleeping");
    usleep(philo->val.sleep);
    print_action(philo, "is thinking");
}