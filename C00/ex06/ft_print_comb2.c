/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 11:51:26 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/07 10:52:50 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_afficher(int a, int b, int c, int d)
{
	ft_putchar(a + '0');
	ft_putchar(b + '0');
	ft_putchar(' ');
	ft_putchar(c + '0');
	ft_putchar(d + '0');
	if (!(a == 9 && b == 8 && c == 9 && d == 9))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	assignation(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 1;
}

void	ft_engine(int a, int b, int c, int d)
{
	while (a <= 9)
	{
		while (b <= 9)
		{
			while (c <= 9)
			{
				while (d <= 9)
				{
					ft_afficher(a, b, c, d);
					d++;
				}
				c++;
				d = 0;
				if (a == c && b == d)
					d++;
			}
			b++;
			c = a;
			d = b + 1;
		}
		a++;
		b = 0;
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	int		c;
	int		d;

	assignation(&a, &b, &c, &d);
	ft_engine(a, b, c, d);
}
