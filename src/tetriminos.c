/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:56:12 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/16 15:22:01 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		*str_to_point(char *s)
{
	t_point		*point;
	int			i;
	int			n;

	if (!(point = (t_point*)malloc(sizeof(t_point) * 4)))
		return (NULL);
	i = 0;
	n = 0;
	while (i < 20 && n < 4)
	{
		if (s[i] == '#')
		{
			point[n].x = i % 5;
			point[n].y = i / 5;
			n++;
		}
		i++;
	}
	return (point);
}

int			get_xmin(t_point *coord)
{
	int xmin;
	int i;

	xmin = 100;
	i = 0;
	while (i < 4)
	{
		if (xmin > coord[i].x)
			xmin = coord[i].x;
		i++;
	}
	return (xmin);
}

int			get_ymin(t_point *coord)
{
	int ymin;
	int i;

	ymin = 100;
	i = 0;
	while (i < 4)
	{
		if (ymin > coord[i].y)
			ymin = coord[i].y;
		i++;
	}
	return (ymin);
}

void		move_upper_left(t_point *coord)
{
	int i;
	int xmin;
	int ymin;

	i = 0;
	xmin = get_xmin(coord);
	ymin = get_ymin(coord);
	while (i < 4)
	{
		coord[i].x -= xmin;
		coord[i].y -= ymin;
		i++;
	}
}

t_tetri		*build_tetri(char *s)
{
	int			i;
	int			n;
	t_tetri		*result;

	i = 0;
	n = 0;
	if (!(result = (t_tetri*)malloc(sizeof(t_tetri) * nb_tetri(s))))
		return (NULL);
	while (s[i])
	{
		if (i % 21 == 0)
		{
			if (valid_tetri(&s[i]) && touching_tetris(&s[i]) > 1)
			{
				result[n].coord = str_to_point(&s[i]);
				move_upper_left(result[n].coord);
				result[n].id = n;
				n++;
			}
			else
				ft_error();
		}
		i++;
	}
	return (result);
}
