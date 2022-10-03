/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:22:17 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/18 20:13:13 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		i;
	int		k;

	i = 1;
	k = nb;
	if (nb < 0)
		return (0);
	if (!nb)
		return (1);
	while (i < k)
	{
		nb = nb * i;
		i++;
	}
	return (nb);
}
