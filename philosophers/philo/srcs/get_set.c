/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:14:38 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/04/29 11:14:40 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

int	get_val(long int *val, pthread_mutex_t *lock)
{
	int	res;

	pthread_mutex_lock(lock);
	res = *val;
	pthread_mutex_unlock(lock);
	return (res);
}

void	set_val(long int *val, pthread_mutex_t *lock, int new_val)
{
	pthread_mutex_lock(lock);
	*val = new_val;
	pthread_mutex_unlock(lock);
	return ;
}
