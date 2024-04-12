/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 thread_utils.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/02/25 16:27:36 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2024/02/25 16:39:24 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../header/philo.h"

void	start_threads(t_philo **table, t_params *params)
{
	int		i;
	int		j;
	t_philo	*philosopher_i;

	i = 0;
	j = 1;
	philosopher_i = *table;
	while (i < params->number_of_philosophers)
	{
		pthread_create(&(params->th[i]), NULL, philosopher, philosopher_i);
		philosopher_i = philosopher_i->right->right;
		i += 2;
		usleep(10);
	}
	philosopher_i = (*table)->right;
	while (j < params->number_of_philosophers)
	{
		pthread_create(&(params->th[j]), NULL, philosopher, philosopher_i);
		philosopher_i = philosopher_i->right->right;
		j += 2;
		usleep(10);
	}
}

void	close_threads(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->number_of_philosophers)
	{
		pthread_join(params->th[i], NULL);
		//printf("Philosopher %d terminado\n", i);
		i++;
	}
	free(params->th);
	free(params->death_report);
	pthread_mutex_destroy(&params->write);
}

long int	get_time(long int t0)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - t0);
}
