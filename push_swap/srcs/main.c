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

int	main(int argc, char **argv)
{
	int			i;
	t_data	*a_stack;
	t_data	*b_stack;

	i = 1;
	if (argc < 3)
	{
		ft_printf("Error\n");
		return (1);
	}
	a_stack = NULL;
	b_stack = NULL;
	while (i < argc)
	{
		add_data(&a_stack, argv[i]);
		i++;
	}
	//pb(&a_stack, &b_stack);
	//print_simple(a_stack, b_stack);
	//print_parallel_lists(a_stack, b_stack);
	lis_pb(&a_stack, &b_stack, find_lis(&a_stack));
	//print_simple(a_stack, b_stack);
	while(b_stack)
	{
		set_moves(&a_stack, &b_stack);
		do_moves(&a_stack, &b_stack);
		//printf("\n");
	}
	sort(&a_stack);
	//print_simple(a_stack, b_stack);
	//print_parallel_lists(a_stack, b_stack);
	free_list(a_stack);
	free_list(b_stack);
	return (0);
}
