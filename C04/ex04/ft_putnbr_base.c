/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 13:04:37 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/18 17:45:50 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long int	ft_strlen(char *str)
{
	long int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			same_char(char *str, char c, int n)
{
	while (str[n])
	{
		if (str[n] == c)
			return (0);
		n++;
	}
	return (1);
}

int			ft_wowerror(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[n])
	{
		if (same_char(str, str[n], (n + 1)) == 0)
			return (0);
		n++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9')
				&& !(str[i] >= 'a' && str[i] <= 'z')
				&& !(str[i] >= 'A' && str[i] <= 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void		ft_putnbr_base(int nbr, char *base)
{
	long int nb;

	nb = nbr;
	if (ft_wowerror(base) == 1 && ft_strlen(base) > 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb >= ft_strlen(base))
			ft_putnbr_base(nb / ft_strlen(base), base);
		ft_putchar(base[nb % ft_strlen(base)]);
	}
}
