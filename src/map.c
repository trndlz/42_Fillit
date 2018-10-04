/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbehra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 12:36:26 by tbehra            #+#    #+#             */
/*   Updated: 2018/04/16 11:10:32 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		min_map_size(int nhash)
{
	int i;

	i = 0;
	while (i * i < nhash)
		i++;
	return (i);
}

int		get_map_size(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		i++;
	}
}

char	**create_map(int map_size)
{
	int		i;
	char	**map;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char*) * map_size + 1)))
		return (0);
	while (i < map_size)
	{
		if (!(map[i] = ft_strnew(map_size + 1)))
			return (NULL);
		ft_memset(map[i], '.', map_size + 1);
		map[i][map_size] = '\n';
		i++;
	}
	map[i] = NULL;
	return (map);
}
