/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:27:36 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/02/25 16:39:24 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	start_threads(t_philo **table, t_params *params) 
{
	int		i;
	t_philo	*philosopher_i;

	i = 0;
	philosopher_i = *table;
	while (i < params->number_of_philosophers)
	{
		pthread_create(&(params->th[i]), NULL, philosopher, philosopher_i);
		philosopher_i = philosopher_i->right;
		i++;
		usleep(1);
	}
}

void	create_philo(t_philo **table, t_params *params)
{
	create_table(table, params);
	start_threads(table, params);
}

void	close_threads(t_params *params)
{
	int i;

	i = 0;
	while (i < params->number_of_philosophers)
	{
		pthread_join(params->th[i], NULL);
		printf("Philosopher %d terminado\n", i);
		i++;
	}
	free(params->th);
    free(params->death_report);
}
