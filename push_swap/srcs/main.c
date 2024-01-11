/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 main.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/12/28 09:41:54 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/12/28 09:41:54 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort(t_data **a_stack, t_data **b_stack)
{
	while (*b_stack)
	{
		set_moves(a_stack, b_stack);
		do_moves(a_stack, b_stack);
	}
	final_sort(a_stack);
}

int	main(int argc, char **argv)
{
	int			i;
	t_data		*a_stack;
	t_data		*b_stack;

	i = 1;
	a_stack = NULL;
	b_stack = NULL;
	if (argc < 3)
		return (ft_printf("Error\n"));
	while (i < argc)
	{
		if (!add_data(&a_stack, argv[i]))
			return (ft_printf("Error\n"));
		i++;
	}
	if (sorted(&a_stack))
	{
		free_list(a_stack);
		return (0);
	}
	lis_pb(&a_stack, &b_stack, find_lis(&a_stack));
	sort(&a_stack, &b_stack);
	free_list(a_stack);
	return (0);
}
