/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:22:35 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/02/25 16:25:22 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

/*Inicialización de parametros, argumentos, malloc del control de muertos, malloc del array de threads
inicializacion del origen del tiempo t0*/
t_params	params_init(char **argv)
{
	t_params		params;
	struct timeval	tv;

	params.number_of_philosophers = ft_atoi(argv[1]);
	params.time_to_die = ft_atoi(argv[2]);
	params.time_to_eat = ft_atoi(argv[3]) * 1000;
	params.time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		params.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		params.number_of_times_each_philosopher_must_eat = 0;
	params.th = malloc((params.number_of_philosophers) * sizeof(pthread_t));
	params.death_report = malloc(sizeof(int));
	*(params.death_report) = -1;
	gettimeofday(&tv, NULL);
	params.t0 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (params);
}

	/*params.time_to_die = ft_atoi(argv[2]);
	params.time_to_eat = ft_atoi(argv[3]);
	params.time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		params.number_of_times_each_philosopher_must_eat = 0;
	printf("\n- number_of_philosophers: %d\n", params.number_of_philosophers);
	printf("- time_to_die: %d\n", params.time_to_die);
	printf("- time_to_eat: %d\n", params.time_to_eat);
	printf("- time_to_sleep: %d\n", params.time_to_sleep);
	printf("- number_of_times_each_philosopher_must_eat: %d\n", params.number_of_times_each_philosopher_must_eat);
	printf("\n\n\n");*/
