/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:57:23 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/25 16:04:18 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void				ft_strcopy(char *src, char *dest)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int			i;

	i = 0;
	if (!(stock = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	while (i < ac)
	{
		if (!(stock[i].str = malloc(sizeof(char) * (ft_strlen(av[i]) + 1))))
			return (NULL);
		if (!(stock[i].copy = malloc(sizeof(char) * (ft_strlen(av[i]) + 1))))
			return (NULL);
		stock[i].str = av[i];
		ft_strcopy(av[i], stock[i].copy);
		stock[i].size = ft_strlen(av[i]);
		i++;
	}
	stock[i].str = 0;
	return (stock);
}
