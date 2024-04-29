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

long int	get_time(long int t0)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - t0);
}

void	start_threads(t_philo *table, t_params *params)
{
	t_philo	*philo;
	int		i;
	int		j;

	philo = table;
	i = 0;
	j = 1;
	while (i < params->val->n_philo)
	{
		pthread_create(&(params->val->th[i]), NULL, philosopher, philo);
		philo = philo->right->right;
		i += 2;
		usleep(100);
	}
	philo = table->right;
	while (j < params->val->n_philo)
	{
		pthread_create(&(params->val->th[j]), NULL, philosopher, philo);
		philo = philo->right->right;
		j += 2;
		usleep(100);
	}
}

void	close_threads(t_val val)
{
	int	i;

	i = 0;
	while (i < val.n_philo)
	{
		pthread_join(val.th[i], NULL);
		i++;
	}
	return ;
}
