/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:03:37 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/16 15:21:22 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			map_available(char **map, t_tetri tetri, int x, int y)
{
	int i;
	int map_size;

	i = 0;
	map_size = get_map_size(map);
	while (i < 4)
	{
		if (y + tetri.coord[i].y >= map_size
				|| x + tetri.coord[i].x >= map_size)
			return (0);
		if (map[y + tetri.coord[i].y][x + tetri.coord[i].x] != '.')
			return (0);
		i++;
	}
	return (1);
}

void		add_tetri(char **map, t_tetri tetri, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		map[y + tetri.coord[i].y][x + tetri.coord[i].x] = 'A' + tetri.id;
}

void		rem_tetri(char **map, t_tetri tetri, int x, int y)
{
	int i;

	i = -1;
	while (++i < 4)
		map[y + tetri.coord[i].y][x + tetri.coord[i].x] = '.';
}

int			place_tetri(int nb_tetri, t_tetri *tetri, char **map, int tetri_id)
{
	int x;
	int y;
	int map_size;

	map_size = get_map_size(map);
	y = -1;
	while (++y < map_size)
	{
		x = -1;
		while (++x < map_size)
		{
			if (map_available(map, tetri[tetri_id], x, y) == 1)
			{
				add_tetri(map, tetri[tetri_id], x, y);
				if (tetri_id == nb_tetri - 1)
					return (1);
				if (place_tetri(nb_tetri, tetri, map, tetri_id + 1))
					return (1);
				else
					rem_tetri(map, tetri[tetri_id], x, y);
			}
		}
	}
	return (0);
}

int			fillit(int nb_tetri, t_tetri *tetri, int map_size)
{
	char **map;

	map = create_map(map_size);
	if (place_tetri(nb_tetri, tetri, map, 0) == 0)
	{
		if (fillit(nb_tetri, tetri, map_size + 1) == 1)
			return (1);
	}
	else
	{
		print_map(map);
		free(map);
		free(tetri);
	}
	return (1);
}
