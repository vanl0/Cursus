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
		params.number_of_times_each_philosopher_must_eat = -1;
	
	params.th = malloc((params.number_of_philosophers) * sizeof(pthread_t));
	params.death_report = malloc(sizeof(int));
	*(params.death_report) = -1;
	gettimeofday(&tv, NULL);
	params.t0 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_init(&params.write, NULL);
	return (params);
}

void	*philosopher(void *philo)
{
	t_philo	*my_philo;

	my_philo = (t_philo *)philo;
	//printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n", my_philo->left->num, my_philo->num, my_philo->right->num, get_time(my_philo->params.t0));
	while (*(my_philo->params.death_report) < 0)
	{
		take_fork(my_philo, &my_philo->fork);
		take_fork(my_philo, &my_philo->left->fork);
		eat(my_philo);
	}
	return (NULL);
}

int		check_n_meals(t_philo *my_philo)
{
	int	n_meals;
	int	n_philo;
	int	i;

	n_meals = my_philo->params.number_of_times_each_philosopher_must_eat;
	n_philo = my_philo->params.number_of_philosophers;
	i = 0;
	while (i < n_philo)
	{
		if (my_philo->n_meals >= n_meals)
			return (1);
		my_philo = my_philo->right;
		i++;
	}
	return (0);
}

void	*death_ctrl(void *table)
{
	t_philo	*my_philo;
	int		meals_flg;

	meals_flg = 0;
	my_philo = (t_philo *)table;
	while (*(my_philo->params.death_report) < 0 && !meals_flg)
	{
		if (*(my_philo->params.death_report) >= 0)
			printf("%d %d died\n", (int)get_time(my_philo->params.t0), *(my_philo->params.death_report));
		if (my_philo->params.number_of_times_each_philosopher_must_eat)
			meals_flg = check_n_meals(my_philo);
	}
	//write(1,"a", 1);
	*(my_philo->params.death_report) = 0;
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		*table;
	pthread_t	control;

	table = NULL;
	if ((argc < 5 || argc > 6) || (argv[5] && ft_atoi(argv[5]) < 1))
		return (printf("invalid args\n"));
	params = params_init(argv);
	//table = malloc(sizeof(t_philo *));
	create_table(&table, &params);
	pthread_create(&control, NULL, death_ctrl, (void *)(&params));
	start_threads(&table, &params);
	close_threads(&params);
	pthread_join(control, NULL);
    free_table(&table);
	return (0);
}

//printf("izquierda: %d | philo %d | derecha: %d | tiempo %ld\n", my_philo->left->num, my_philo->num, my_philo->right->num, get_time(my_philo->params.t0));
