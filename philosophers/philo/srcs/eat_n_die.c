/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 eat_n_die.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/03/26 15:26:15 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2024/04/18 16:55:40 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../header/philo.h"

void	die(t_philo *philo)
{
	pthread_mutex_lock(&philo->val.death_mutex);
	if (*philo->val.death_flg < 0)
	{
		*philo->val.death_flg = philo->num;
		usleep(100);
		printf("%ld %d died\n", get_time(philo->val.t0), philo->num);
	}
	pthread_mutex_unlock(&philo->val.death_mutex);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right->fork);
}

void	print_action(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->val.death_mutex);
	pthread_mutex_lock(&(philo->val.write_mutex));
	if (*philo->val.death_flg < 0)
		printf("%ld %d %s\n", get_time(philo->val.t0), philo->num, msg);
	pthread_mutex_unlock(&philo->val.death_mutex);
	pthread_mutex_unlock(&(philo->val.write_mutex));
	return ;
}

void	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	if ((get_time(philo->val.t0) - philo->last_meal) >= philo->val.die)
	{
		die(philo);
		return ;
	}
	pthread_mutex_lock(fork);
	print_action(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	philo->last_meal = get_time(philo->val.t0);
	print_action(philo, "is eating");
	philo->last_meal = get_time(philo->val.t0);
	philo->n_meal++;
	usleep(philo->val.eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right->fork);
	print_action(philo, "is sleeping");
	usleep(philo->val.sleep);
	print_action(philo, "is thinking");
}
