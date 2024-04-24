/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:52:58 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/04/18 16:53:39 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

t_philo	*set_philo(t_val val, int i)
{
	t_philo	*philo_i;

	philo_i = malloc(sizeof(t_philo));
	philo_i->num = i;
	philo_i->val = val;
	philo_i->last_meal = 0;
	philo_i->n_meal = 0;
	pthread_mutex_init(&(philo_i->fork), NULL);
	return (philo_i);
}

t_philo	*add_philo(t_philo **table, t_val val, int i)
{
	t_philo	*philo_new;
	t_philo	*philo_i;

	philo_new = set_philo(val, i);
	philo_i = *table;
	if (!(*table))
	{
		philo_new->right = philo_new;
		*table = philo_new;
		return (*table);
	}
	while (philo_i->right != *table)
		philo_i = philo_i->right;
	philo_new->right = *table;
	philo_i->right = philo_new;
	return (*table);
}

void	set_table(t_philo **table, t_val val)
{
	int	i;

	i = 0;
	while (i < val.n_philo)
	{
		add_philo(table, val, i);
		i++;
	}
}

void	free_table(t_philo *table)
{
	t_philo	*philo_i;
	t_philo	*philo_free;

	philo_free = table->right;
	philo_i = table->right->right;
	while (philo_free != table)
	{
		pthread_mutex_destroy(&philo_free->fork);
		free(philo_free);
		philo_free = philo_i;
		philo_i = philo_i->right;
	}
	free(table);
	return ;
}
