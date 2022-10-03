/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:57:29 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/11 17:51:17 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int		ft_char_is_alphanum(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		while (ft_char_is_alphanum(str[i]) && str[i] != '\0')
		{
			if ((str[i] >= 'a' && str[i] <= 'z') && c == 0)
			{
				str[i] = str[i] - 32;
			}
			c++;
			i++;
		}
		c = 0;
		i++;
	}
	return (str);
}
