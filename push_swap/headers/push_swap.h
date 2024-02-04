/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:55:55 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/01/14 17:46:22 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/ft_printf/ft_printf.h"
# include "../libs/Libft/libft.h"

typedef struct s_data
{
	int				val;
	int				moves;
	int				target;
	int				rb;
	int				rrb;
	int				ra;
	int				rra;
	int				rr;
	int				rrr;
	struct s_data	*next;
}	t_data;

typedef struct s_target
{
	int	target_pos;
	int	pos;
	int	target_set;
}	t_target;

typedef struct s_lis
{
	int	*val;
	int	*lis_len;
	int	*lis_prev;
	int	*lis;
	int	maxlen;
	int	max_i;
	int	len;
}	t_lis;

//DATA------------------------------------
int			add_data(t_data **first, char *num);
void		free_list(t_data *first);
//SMALL_SORT------------------------------
void		sort_three(t_data **a_stack);
void		sort_five(t_data **a_stack, t_data **b_stack, int argc);
//L.I.S-----------------------------------
t_lis		find_lis(t_data **a_stack);
void		lis_pb(t_data **a_stack, t_data **b_stack, t_lis lis);
//CALC_MOVES------------------------------
void		set_moves(t_data **a_stack, t_data **b_stack);
t_target	get_min_target(t_data **a_stack, t_data *b_elem);
void		do_moves(t_data **a_stack, t_data **b_stack);
void		do_r(t_data *elem, t_data **a_stack, t_data **b_stack);
void		do_rr(t_data *elem, t_data **a_stack, t_data **b_stack);
//CHECK-----------------------------------
int			check_arg(t_data **a_stack, char *num);
int			is_int(char *str);
int			check_dup(t_data **a_stack);
int			get_stack_len(t_data **stack);
int			get_min_pos(t_data **a_stack);
int			sorted(t_data **a_stack);
void		final_sort(t_data **a_stack);
//MOVES-----------------------------------
void		sa(t_data **afirst);
void		sb(t_data **bfirst);
void		ss(t_data **afirst, t_data **bfirst);
void		pa(t_data **afirst, t_data **bfirst);
void		pb(t_data **afirst, t_data **bfirst);
void		ra(t_data **afirst);
void		rb(t_data **bfirst);
void		rr(t_data **afirst, t_data **bfirst);
void		rra(t_data **afirst);
void		rrb(t_data **bfirst);
void		rrr(t_data **afirst, t_data **bfirst);
#endif
