/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 18:56:58 by aaapatou          #+#    #+#             */
/*   Updated: 2019/06/25 18:14:33 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define A (str + start)

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*str_checking_sep(char *str, char *charset, int buffer)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (charset[i] != '\0')
	{
		while (c < buffer)
		{
			if (str[c] == charset[i])
				str[c] = '\0';
			c++;
		}
		c = 0;
		i++;
	}
	return (str);
}

int		str_into_strs(char **strs, char *str, int buffer)
{
	int		i;
	int		size;
	int		c;
	int		start;

	i = 0;
	size = 0;
	c = 0;
	while (i < buffer)
	{
		size++;
		if (str[i] == '\0')
			size = 0;
		if (str[i + 1] == '\0' && size != 0)
		{
			ft_strncpy(strs[c] = malloc(sizeof(char) * size + 1), A, size);
			c++;
		}
		i++;
		if (str[i - 1] == '\0' && str[i] != '\0')
			start = i;
	}
	return (c);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		buffer;
	int		words;

	buffer = ft_strlen(str) + 1;
	str = str_checking_sep(str, charset, buffer);
	i = 1;
	words = 0;
	while (i < buffer)
	{
		if (str[i - 1] == '\0' && str[i] != '\0')
			words++;
		i++;
	}
	if (!(strs = malloc(sizeof(char*) * ((words + 2)))))
		return (NULL);
	i = str_into_strs(strs, str, buffer);
	strs[i] = 0;
	return (strs);
}
