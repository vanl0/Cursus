/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 check_arg.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2024/01/11 11:49:34 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2024/01/11 11:49:38 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	check_arg(t_data **a_stack, char *num)
{
	if (!is_int(num) || check_dup(a_stack))
	{
		free_list(*a_stack);
		return (0);
	}
	return (1);
}

int	check_int(long num, char *str)
{
	int	i;

	i = 0;
	if (num > 2147483647 || num < -2147483648)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || i == 10)
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	is_int(char *str)
{
	long	n;
	int		i;
	int		neg;

	n = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i ++;
	}
	else if (str[i] == '+')
		i ++;
	while (str[i] == '0')
		i ++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = 10 * n + str[i] - '0';
		i ++;
	}
	return (check_int(neg * n, str));
}

int	search_dup(t_data *elem)
{
	int	num;

	num = elem->val;
	elem = elem->next;
	while (elem)
	{
		if (elem->val == num)
			return (1);
		elem = elem->next;
	}
	return (0);
}

int	check_dup(t_data **a_stack)
{
	t_data	*elem;

	elem = *a_stack;
	while (elem)
	{
		if (search_dup(elem))
			return (1);
		elem = elem->next;
	}
	return (0);
}
