/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:35:38 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/18 17:39:46 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	increase(int *n, int a)
{
	*n = 10 * *n + a;
}

int		is_digital(char c)
{
	if ((c <= '9') && (c >= '0'))
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int negative;
	int answer;

	answer = 0;
	i = 0;
	negative = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while (is_digital(str[i]))
	{
		increase(&answer, (str[i] - '0'));
		i++;
	}
	if (negative % 2)
		answer = -answer;
	return (answer);
}
