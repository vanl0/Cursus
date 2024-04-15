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

void print_t_val(t_val val) {
    printf("n_philo: %d\n", val.n_philo);
    printf("die: %d\n", val.die);
    printf("eat: %d\n", val.eat);
    printf("sleep: %d\n", val.sleep);
    printf("max_meals: %d\n", val.max_meals);
    printf("t0: %ld\n", val.t0);
}

void	print_list(t_philo *first)
{
	t_philo *philo_i;
	
	printf("philo %d, right: %d\n", first->num, first->right->num);
	if (first->right == first)
		return ;
	philo_i = first->right;
	while(philo_i != first)
	{
		printf("philo %d, right: %d\n", philo_i->num, philo_i->right->num);
		philo_i = philo_i->right;
	}
	return;
}

t_val	set_val(int ac, char **av)
{
	t_val	val;

	val.n_philo = ft_atoi(av[1]);
	val.die = ft_atoi(av[2]);
	val.eat = ft_atoi(av[3]);
	val.sleep = ft_atoi(av[4]);
	if (ac > 5)
		val.max_meals = ft_atoi(av[5]);
	else
		val.max_meals = 0;
	val.t0 = get_time(0);
	return (val);
}

int main(int ac, char **av)
{
	t_params	params;

	if (ac < 5 || ac > 6)
		return (printf("Error\n"));
	params.val = set_val(ac, av);
	set_table(&params.table, params.val);
	
	//print_list(params.table);

	
	return (0);
}