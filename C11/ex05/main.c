/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 21:29:47 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/26 21:29:53 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_error(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac != 4)
		return (0);
	if (ft_strlen(av[2]) != 1 || (av[2][0] != '+' && av[2][0] != '-'
				&& av[2][0] != '*' && av[2][0] != '%' && av[2][0] != '/'))
	{
		ft_putchar('0');
		return (ft_putchar('\n'));
	}
	if (av[2][0] == '/' && ft_atoi(av[3]) == 0)
		return (ft_putstr("Stop : division by zero"));
	if (av[2][0] == '%' && ft_atoi(av[3]) == 0)
		return (ft_putstr("Stop : modulo by zero"));
	return (1);
}

int		lol(char **av, int (**operateur)(int, int))
{
	operateur[2] = multiplication;
	operateur[3] = division;
	operateur[4] = modulo;
	if (av[2][0] == '*')
	{
		ft_putnbr((operateur[2])(ft_atoi(av[1]), ft_atoi(av[3])));
		return (ft_putchar('\n'));
	}
	if (av[2][0] == '/')
	{
		ft_putnbr((operateur[3])(ft_atoi(av[1]), ft_atoi(av[3])));
		return (ft_putchar('\n'));
	}
	if (av[2][0] == '%')
	{
		ft_putnbr((operateur[4])(ft_atoi(av[1]), ft_atoi(av[3])));
		return (ft_putchar('\n'));
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		(*operateur[5])(int, int);

	operateur[0] = addition;
	operateur[1] = soustraction;
	if (!(check_error(ac, av)))
		return (0);
	if (av[2][0] == '+')
	{
		ft_putnbr((operateur[0])(ft_atoi(av[1]), ft_atoi(av[3])));
		return (ft_putchar('\n'));
	}
	if (av[2][0] == '-')
	{
		ft_putnbr((operateur[1])(ft_atoi(av[1]), ft_atoi(av[3])));
		return (ft_putchar('\n'));
	}
	lol(av, operateur);
	return (0);
}
