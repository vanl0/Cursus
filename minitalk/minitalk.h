/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:59:02 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/02/15 12:59:08 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "./ft_printf/ft_printf.h"
# include "./Libft/libft.h"
# include <unistd.h>

void	send_char(char c, pid_t pid);
void	gotsign(int signal, siginfo_t *info, void *context);
#endif
