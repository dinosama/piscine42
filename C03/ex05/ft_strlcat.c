/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:19:23 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/14 12:04:48 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int c;
	unsigned int res;

	res = ft_strlen(dest) + ft_strlen(src);
	c = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	if (size < i)
		return (size + ft_strlen(src));
	if (size > 0)
	{
		while (i < (size - 1) && src[c] != '\0')
		{
			dest[i] = src[c];
			i++;
			c++;
		}
		dest[i] = '\0';
	}
	return (res);
}
