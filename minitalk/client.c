/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:20:23 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/01 12:59:19 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <studio.h>

void	send_char(char	**argv)
{


int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("PID and MSG needed\n");
		return (0);
	}
	return (1);
}
