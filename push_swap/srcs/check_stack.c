/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 check.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/12/13 13:21:46 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/12/13 13:22:26 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	sorted(t_data **a_stack)
{
	int		maxval;
	t_data	*elem;

	if (!a_stack || !*a_stack)
		return (0);
	elem = *a_stack;
	maxval = elem->val;
	elem = elem->next;
	while (elem)
	{
		if (elem->val < maxval)
			return (0);
		maxval = elem->val;
		elem = elem->next;
	}
	return (1);
}

void	final_sort(t_data **a_stack)
{
	if (get_min_pos(a_stack) <= get_stack_len(a_stack) / 2)
	{
		while (!sorted(a_stack))
		{
			ra(a_stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (!sorted(a_stack))
		{
			rra(a_stack);
			ft_printf("rra\n");
		}
	}
}

int	get_stack_len(t_data **stack)
{
	int		len;
	t_data	*elem;

	if (!stack || !(*stack))
		return (0);
	len = 0;
	elem = *stack;
	while (elem)
	{
		len++;
		elem = elem->next;
	}
	return (len);
}

int	get_min_pos(t_data **a_stack)
{
	t_data	*elem;
	int		min_val;
	int		min_pos;
	int		pos;

	elem = *a_stack;
	min_val = elem->val;
	min_pos = 0;
	pos = 0;
	while (elem)
	{
		if (elem->val < min_val)
		{
			min_val = elem->val;
			min_pos = pos;
		}
		elem = elem->next;
		pos++;
	}
	return (min_pos);
}
