/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:14:58 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/23 15:49:08 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (dest[i])
		i++;
	while (src[c])
	{
		dest[i] = src[c];
		i++;
		c++;
	}
	dest[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (i < size)
	{
		c = c + ft_strlen(strs[i]);
		i++;
	}
	if (size == 0)
		return (dest = malloc(sizeof(char) * 1));
	dest = malloc(sizeof(char) * ((c + (size - 1) * ft_strlen(sep)) + 1));
	i = 0;
	dest[i] = '\0';
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
