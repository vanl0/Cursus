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

void	*dead_philo(t_philo *my_philo)
{
	*(my_philo->params.death_report) = my_philo->num;
	printf("%lu | philo: %d has died, last meal: %ld\n", get_time(my_philo->params.t0), my_philo->num, my_philo->last_meal);
	return ((void *) my_philo);
}

void	take_fork(t_philo *my_philo, pthread_mutex_t *fork, int flg)
{
	if ((get_time(my_philo->params.t0) - my_philo->last_meal) > my_philo->params.time_to_die)
	{
		dead_philo(my_philo);
		return ;
	}
	pthread_mutex_lock(fork);
	if (!flg)
		print_action(my_philo, "has taken right fork");
	else
		print_action(my_philo, "has taken left fork");
}

void	eat(t_philo *my_philo)
{
	my_philo->last_meal = get_time(my_philo->params.t0);
	print_action(my_philo, "is eating");
	usleep(my_philo->params.time_to_eat);
	print_action(my_philo, "is sleeping");
	pthread_mutex_unlock(&(my_philo->left->fork));
	pthread_mutex_unlock(&(my_philo->fork));
	usleep(my_philo->params.time_to_sleep);
	print_action(my_philo, "is thinking");
}

void	print_action(t_philo *my_philo, char *msg)
{
	if (*(my_philo->params.death_report) < 0)
		printf("%ld | philo : %d %s | last meal: %ld\n", get_time(my_philo->params.t0), my_philo->num, msg, my_philo->last_meal);
	return ;
}
