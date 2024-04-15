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
	//printf("tv_sec %ld\ntv_usec : %d\n", tv.tv_sec, tv.tv_usec);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - t0);
}