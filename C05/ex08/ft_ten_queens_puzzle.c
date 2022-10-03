/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 18:44:52 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/18 18:01:10 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		check_minus(char *str)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int		check_solution(char *str, int x, char valeur)
{
	int		c;

	c = -1;
	while (c++ < 10)
		if (valeur == str[c])
			return (0);
	str[x] = valeur;
	if (check_minus(str))
		return (1);
	x = 0;
	c = 1;
	while (x < 9)
	{
		while (c <= 9 - x)
		{
			if ((str[x] - str[x + c]) == c || (str[x] - str[x + c]) == -c)
				return (0);
			if ((str[x] - str[x - c]) == c || (str[x] - str[x - c]) == -c)
				return (0);
			c++;
		}
		c = 1;
		x++;
	}
	return (1);
}

int		solve(char *str, int x)
{
	char	valeur;

	valeur = '0';
	if (x <= 9)
	{
		while (valeur <= '9')
		{
			if (check_solution(str, x, valeur))
			{
				str[x] = valeur;
				if (solve(str, x + 1))
					return (1);
			}
			valeur++;
		}
		str[x] = '-';
		return (0);
	}
	ft_putstr(str);
	write(1, "\n", 1);
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	char	str[11];
	int		i;

	i = 0;
	while (i < 10)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	solve(str, 0);
	return (724);
}
