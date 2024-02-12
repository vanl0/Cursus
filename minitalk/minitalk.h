

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "./ft_printf/ft_printf.h"
# include "./Libft/libft.h"
# include <unistd.h>

void	send_char(char c, pid_t pid);
void	gotsign(int signal);
#endif