/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:54:05 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/16 11:06:29 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*cpy;

	i = 0;
	cpy = (char *)str;
	while (i < n)
	{
		cpy[i] = c;
		i++;
	}
	return (cpy);
}

void		ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

char		*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		dest_size;

	i = 0;
	dest_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[i])
	{
		dest[dest_size] = src[i];
		dest_size++;
		i++;
	}
	dest[dest_size] = '\0';
	return (dest);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strnew(size_t size)
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str = ft_memset(str, '\0', size + 1);
	return (str);
}
