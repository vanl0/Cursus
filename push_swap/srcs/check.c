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

void	sort(t_data **a_stack)
{
	while (!sorted(a_stack))
	{
		ra(a_stack);
		printf("ra\n");
	}
} 
int get_stack_len(t_data **stack)
{
	int len;
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
