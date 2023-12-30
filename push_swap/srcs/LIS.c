/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:55:49 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/26 20:00:47 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	*get_val(t_data **a_stack, int len)
{
	int		*val;
	t_data	*elem;
	int		i;

	val = malloc(len * sizeof(int));
	elem = *a_stack;
	i = 0;
	while (elem)
	{
		val[i] = elem->val;
		i++;
		elem = elem->next;
	}
	return (val);
}

void	lis_init(t_data **a_stack, t_lis *lis)
{
	int	i;

	lis->len = get_stack_len(a_stack);
	lis->lis_len = malloc(lis->len * sizeof(int));
	lis->lis_prev = malloc(lis->len * sizeof(int));
	lis->val = get_val(a_stack, lis->len);
	i = 0;
	while (i < lis->len)
	{
		lis->lis_len[i] = 1;
		lis->lis_prev[i] = -1;
		i++;
	}
}

void	find_max(t_lis *lis)
{
	int	i;

	lis->max_i = 0;
	lis->maxlen = lis->lis_len[0];
	i = 0;
	while (i < lis->len)
	{
		if (lis->lis_len[i] > lis->maxlen)
		{
			lis->maxlen = lis->lis_len[i];
			lis->max_i = i;
		}
		i++;
	}
	lis->lis = malloc(lis->maxlen * sizeof(int));
}

void	set_lis(t_lis *lis)
{
	int	k;
	int	j;

	k = lis->maxlen - 1;
	j = lis->max_i;
	while (k >= 0)
	{
		lis->lis[k] = lis->val[j];
		j = lis->lis_prev[j];
		k--;
	}
	free(lis->lis_len);
	free(lis->lis_prev);
	free(lis->val);
}

t_lis	find_lis(t_data **a_stack)
{
	t_lis	lis;
	int		i;
	int		j;

	lis_init(a_stack, &lis);
	i = 0;
	j = 1;
	while (j < lis.len)
	{
		while (i < j)
		{
			if (lis.val[j] > lis.val[i] && lis.lis_len[j] < lis.lis_len[i] + 1)
			{
				lis.lis_len[j] = lis.lis_len[i] + 1;
				lis.lis_prev[j] = i;
			}
			i++;
		}
		j++;
		i = 0;
	}
	find_max(&lis);
	set_lis(&lis);
	/*printf("L.I.S: ");
	for (int i = 0; i < lis.maxlen; i++)
	{
		printf("%d ", lis.lis[i]);
	}
	printf("\n");*/
	return (lis);
}

/*	for (int i = 0; i < lis.maxlen; i++)
	{
		printf("%d ", lis.lis[i]);
	}*/
