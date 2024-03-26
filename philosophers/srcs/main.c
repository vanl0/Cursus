/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:23:36 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/03/26 15:25:58 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

void	*philosopher(void *philo)
{
	t_philo	*my_philo;

	my_philo = (t_philo *)philo;
	//printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n", my_philo->left->num, my_philo->num, my_philo->right->num, get_time(my_philo->params.t0));
	while (*(my_philo->params.death_report) < 0)
	{
		take_fork(my_philo, &my_philo->fork, 0);
		take_fork(my_philo, &my_philo->left->fork, 1);
		eat(my_philo);
	}
	return (NULL);
}

void	*death_ctrl(void *params_void)
{
	t_params	*params;

	params = (t_params *)params_void;
	while (*(params->death_report) < 0)
		usleep(1);
	printf("%ld | R.I.P Philosopher %d\n", get_time(params->t0), *(params->death_report));
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		*table;
	pthread_t	control;

	table = NULL;
	if (argc < 5 || argc > 6)
		return (printf("invalid args\n"));
	params = params_init(argv);
	create_table(&table, &params);
	pthread_create(&control, NULL, death_ctrl, (void *)(&params));
	start_threads(&table, &params);
	close_threads(&params);
	pthread_join(control, NULL);
	return (0);
}

//printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n", my_philo->left->num, my_philo->num, my_philo->right->num, get_time(my_philo->params.t0));
