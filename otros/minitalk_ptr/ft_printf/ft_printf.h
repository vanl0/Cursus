/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:07:39 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/02 16:08:34 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	put_var(va_list args, char c, int *perr);

int	ft_putchar(char c, int *perr);
int	ft_putstr(char *s, int *perr);
int	ft_putnbr(int nb, int *perr);
int	ft_putunsig(unsigned int nb, int *perr);
int	ft_puthex(unsigned int nb, char c, int *perr);
int	ft_putpoint(unsigned long p, int *perr);
#endif
