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
	char	*charstr;

	charstr = malloc(2 * sizeof(char));
	charstr[0] = c;
	charstr[1] = 0;
	if (!str)
		return (charstr);
	charjoin = ft_strjoin(str, charstr);
	free(str);
	free(charstr);
	return (charjoin);
}

void	gotsign(int signal)
{
	static int	bit_pos = 0;
	static char	tchar = 0;
	//static char	*string = NULL;

	if (signal == SIGUSR2)
	{
		tchar |= (1 << (7 - bit_pos));
	}

	bit_pos++;
	if (bit_pos == 8 && tchar == '\0')
	{
		//write(1, string, ft_strlen(string));
		//free(string);
		//string = NULL;
		bit_pos = 0;
	}						
	if (bit_pos == 8)
	{
		//string = ft_charjoin(string, tchar);
		write(1, &tchar, 1);
		bit_pos = 0;
		tchar = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = gotsign;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
