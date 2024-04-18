/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:23:36 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/04/18 16:52:15 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

t_val	set_val(int ac, char **av)
{
	t_val	val;

	val.n_philo = ft_atoi(av[1]);
	val.die = ft_atoi(av[2]);
	val.eat = ft_atoi(av[3]) * 1000;
	val.sleep = ft_atoi(av[4]) * 1000;
	if (ac > 5)
		val.max_meals = ft_atoi(av[5]);
	else
		val.max_meals = 0;
	val.t0 = get_time(0);
	pthread_mutex_init(&val.write_mutex, NULL);
	pthread_mutex_init(&val.death_mutex, NULL);
	val.th = malloc(val.n_philo * sizeof(pthread_t));
	val.death_flg = malloc(sizeof(int));
	*val.death_flg = -1;
	return (val);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
		return (printf("4(5) arguments needed\n"));
	while (i < ac)
	{
		if (ft_atoi(av[i]) <= 0)
			return (printf("Invalid arguments\n"));
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_params	params;

	if (check_arg(ac, av))
		return (1);
	params.val = set_val(ac, av);
	params.table = NULL;
	set_table(&params.table, params.val);
	start_threads(params.table, &params);
	close_threads(params.val);
	free_table(params.table);
	pthread_mutex_destroy(&params.val.write_mutex);
	free(params.val.death_flg);
	return (0);
}
