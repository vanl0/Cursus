/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 LIS_pb.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/12/28 09:43:38 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/12/28 09:43:38 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	lis_pb(t_data **a_stack, t_data **b_stack, t_lis lis)
{
	int		i;
	int		first;
	int		read;

	i = 0;
	first = lis.lis[0];
	read = 0;
	while (!((*a_stack)->val == first && read))
	{
		if ((*a_stack)->val == first)
			read = 1;
		if ((*a_stack)->val == lis.lis[i])
		{
			ra(a_stack);
			ft_printf("ra\n");
			i++;
		}
		else
		{
			pb(a_stack, b_stack);
			ft_printf("pb\n");
		}
	}
	free(lis.lis);
}
