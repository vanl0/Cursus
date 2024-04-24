/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:07:08 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/04/18 17:07:10 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../header/philo.h"

void	*philosopher(void	*void_philo)
{
	t_philo	*philo;

	philo = (t_philo *)void_philo;
	while (*philo->val.death_flg < 0)
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

	if (table->val.max_meals)
	{
		philo_i = table;
		max_meals = table->val.max_meals;
		i = 0;
		while (i < table->val.n_philo)
		{
			if (philo_i->n_meal < max_meals)
				return (0);
			philo_i = philo_i->right;
			i++;
		}
		pthread_mutex_lock(&philo_i->val.death_mutex);
		*philo_i->val.death_flg = 0;
		pthread_mutex_unlock(&philo_i->val.death_mutex);
	}
	else
		return (0);
	return (1);
}

int	hunger_ctrl(t_philo	*table)
{
	t_philo	*philo_i;
	int		dth_time;
	long 	t0;
	int		i;

	//printf("HOLAAAAAA\n");
	philo_i = table;
	dth_time = table->val.die;
	t0 = table->val.t0;
	i = 0;
	while (i < table->val.n_philo)
	{
		if ((get_time(t0) - philo_i->last_meal) >= dth_time)
		{
			die(philo_i);
			//printf("die\n");
			return(1);
		}
		// printf("%d\n", i );
		philo_i = philo_i->right;
		i++;
	}
	return (0);
}

void	*death_ctrl(void	*void_params)
{
	t_params	*params;

	params = (t_params *)void_params;
	//printf("HOLAAAAAA\n");
	while ((*params->val.death_flg < 0) && !meals_ctrl(params->table) && !hunger_ctrl(params->table) )
		usleep(10);
	close_threads(params->val);
	return (NULL);
}
