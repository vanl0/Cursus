/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:52:35 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/01/11 12:52:38 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void    sort_three(t_data **a_stack)
{
    t_data *elem;

    elem = *a_stack;
    if (elem->val > elem->next->val)
    {
        if (elem->val < elem->next->next->val)
        {
            sa(a_stack);
            ft_printf("sa\n");
        }
        else
        {
            
        }
    }

}