/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 small_sort.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/01/11 12:52:35 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2024/01/11 12:52:38 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sort_abc(t_data **a_stack, int a, int b, int c)
{
	if ((a > b && b < c && a < c) || (a > b && b > c && a > c) \
	|| (a < b && b > c && a < c))
	{
		sa(a_stack);
		ft_printf("sa\n");
	}
	if (a > b && b < c && a > c)
	{
		ra(a_stack);
		ft_printf("ra\n");
	}
	if (a < b && b > c && a > c)
	{
		rra(a_stack);
		ft_printf("rra\n");
	}
}

void	sort_three(t_data **a_stack)
{
	t_data	*elem;
	int		a;
	int		b;
	int		c;

	elem = *a_stack;
	while (!sorted(a_stack))
	{
		a = elem->val;
		b = elem->next->val;
		c = elem->next->next->val;
		sort_abc(a_stack, a, b, c);
	}
}

void	sort_five(t_data **a_stack, t_data **b_stack, int argc)
{
	while (argc > 4)
	{
		pb(a_stack, b_stack);
		ft_printf("pb\n");
		argc--;
	}
	sort_three(a_stack);
}
