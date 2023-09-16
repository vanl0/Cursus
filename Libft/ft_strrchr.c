/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:03:40 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/13 15:31:28 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			ret = (char *) &str[i];
		i++;
	}
	return (ret);
}
