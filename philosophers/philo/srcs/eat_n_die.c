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
	if (get_val((long *)&philo->val->death_flg, &philo->val->death_mutex) < 0)
	{
		set_val((long *)&philo->val->death_flg, \
		&philo->val->death_mutex, philo->num);
		usleep(100);
		printf("%ld %d died\n", get_time(philo->val->t0), philo->num);
	}
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right->fork);
}

void	print_action(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(philo->val->write_mutex));
	if (get_val((long *)&philo->val->death_flg, &philo->val->death_mutex) < 0)
		printf("%ld %d %s\n", get_time(philo->val->t0), philo->num, msg);
	pthread_mutex_unlock(&(philo->val->write_mutex));
	return ;
}

void	take_fork(pthread_mutex_t *fork, t_philo *philo)
{
	if ((get_time(philo->val->t0) - get_val(&philo->last_meal, \
	&philo->l_meal_mutex)) >= philo->val->die)
	{
		die(philo);
		return ;
	}
	pthread_mutex_lock(fork);
	print_action(philo, "has taken a fork");
}

void	eat(t_philo *philo)
{
	set_val(&philo->last_meal, &philo->l_meal_mutex, \
	get_time(philo->val->t0));
	print_action(philo, "is eating");
	set_val((long *)&philo->n_meal, &philo->n_meal_mutex, get_val((long *)&philo->n_meal, &philo->n_meal_mutex) + 1);
	usleep(philo->val->eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->right->fork);
	print_action(philo, "is sleeping");
	usleep(philo->val->sleep);
	print_action(philo, "is thinking");
}
