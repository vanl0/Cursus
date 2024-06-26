/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:07:08 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/04/24 20:05:35 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/philo.h"

void	*philosopher(void	*void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (philo->val->death_flg < 0)
	{
		take_fork(&philo->fork, philo);
		take_fork(&philo->right->fork, philo);
		eat(philo);
	}
	return (NULL);
}

int	meals_ctrl(t_philo *table)
{
	t_philo	*philo_i;
	int		max_meals;
	int		i;

	if (table->val->max_meals)
	{
		philo_i = table;
		max_meals = table->val->max_meals;
		i = 0;
		while (i < table->val->n_philo)
		{
			if (get_val((long *)&philo_i->n_meal, \
			&philo_i->n_meal_mutex) < max_meals)
				return (0);
			philo_i = philo_i->right;
			i++;
		}
		pthread_mutex_lock(&philo_i->val->death_mutex);
		philo_i->val->death_flg = 0;
		pthread_mutex_unlock(&philo_i->val->death_mutex);
	}
	else
		return (0);
	return (1);
}

int	hunger_ctrl(t_philo	*table)
{
	t_philo	*philo_i;
	int		dth_time;
	long	t0;
	int		i;

	philo_i = table;
	dth_time = table->val->die;
	t0 = table->val->t0;
	i = 0;
	while (i < table->val->n_philo)
	{
		if ((get_time(t0) - \
		get_val(&philo_i->last_meal, &philo_i->l_meal_mutex)) >= dth_time)
		{
			die(philo_i);
			return (1);
		}
		philo_i = philo_i->right;
		i++;
	}
	return (0);
}

void	*death_ctrl(void	*void_params)
{
	t_params	*params;

	params = (t_params *)void_params;
	while ((get_val((long *)&params->val->death_flg, \
		&params->val->death_mutex) < 0) \
		&& !meals_ctrl(params->table) && !hunger_ctrl(params->table))
		usleep(10);
	close_threads(*params->val);
	return (NULL);
}
