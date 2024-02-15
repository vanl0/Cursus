/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 server.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/12/01 12:05:24 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/12/01 12:53:32 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */
#include "minitalk.h"

char	*ft_charjoin(char *str, char c)
{
	char	*charjoin;
	int		len;
	int		i;

	i = 0;
	if (!str)
	{
		charjoin = malloc(2 * sizeof(char));
		charjoin[0] = c;
		charjoin[1] = 0;
		return (charjoin);
	}
	len = ft_strlen(str);
	charjoin = malloc((len + 2) * sizeof(char));
	while (i < len)
	{
		charjoin[i] = str[i];
		i++;
	}
	charjoin[i] = c;
	charjoin[i + 1] = '\0';
	free(str);
	return (charjoin);
}

void	gotsign(int signal, siginfo_t *info, void *context)
{
	static int	bit_pos = 0;
	static char	tchar = 0;
	static char	*string = NULL;

	context = NULL;
	if (signal == SIGUSR2)
		tchar |= (1 << (7 - bit_pos));
	bit_pos++;
	if (bit_pos == 8 && tchar == '\0')
	{
		write(1, string, ft_strlen(string));
		free(string);
		string = NULL;
		bit_pos = 0;
		kill(info->si_pid, SIGUSR1);
	}
	if (bit_pos == 8)
	{
		string = ft_charjoin(string, tchar);
		bit_pos = 0;
		tchar = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &gotsign;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
