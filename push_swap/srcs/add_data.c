/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 add_data.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/12/13 13:20:49 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/12/13 13:21:28 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_data	*data_init(void)
{
	t_data	*new_elem;

	new_elem = (t_data *)malloc(sizeof(t_data));
	new_elem->rb = 0;
	new_elem->rrb = 0;
	new_elem->ra = 0;
	new_elem->rra = 0;
	new_elem->rr = 0;
	new_elem->rrr = 0;
	new_elem->target = 0;
	new_elem->next = NULL;
	return (new_elem);
}

int	add_data(t_data **a_stack, char *num)
{
	t_data	*elem;
	t_data	*new_elem;

	new_elem = data_init();
	new_elem->val = ft_atoi(num);
	elem = *a_stack;
	if (!elem)
		*a_stack = new_elem;
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = new_elem;
	}
	return (check_arg(a_stack, num));
}

void	free_list(t_data *first)
{
	t_data	*temp;

	temp = first;
	while (first)
	{
		temp = first;
		first = first->next;
		free(temp);
	}
}
