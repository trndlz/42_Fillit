/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:39:05 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/16 14:16:48 by tbehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Function returns error message if:
**	- Characters are not '#', '\n', '.'
**	- Number of terminos is a multiple of 21 - 1
**	- No '\n' between terminos
**	- No '\n' at the end of each line
**	- Total number of #
*/

void		ft_chck_inp_str(char *s)
{
	int i;
	int tetri;
	int hash;

	i = 0;
	hash = 0;
	if ((ft_strlen(s) + 1) % 21 != 0)
		ft_error();
	tetri = (ft_strlen(s) + 1) / 21;
	while (s[i])
	{
		if (!(s[i] == '.' || s[i] == '#' || s[i] == '\n'))
			ft_error();
		if (s[i] == '#')
			hash++;
		if ((i + 1 - (i / 21)) % 5 == 0 || (i + 1) % 21 == 0)
		{
			if (s[i] != '\n')
				ft_error();
		}
		i++;
	}
	if (tetri * 4 != hash || tetri > 26)
		ft_error();
}

int			nb_tetri(char *s)
{
	return (((ft_strlen(s) + 1) / 21));
}

/*
** Function returns 0 if single tetriminos are not valid.
** Tetrimino considered valid if each # is connected horizontally
** or vertically to another # and if only 4 hash per tetrimino.
*/

int			valid_tetri(char *s)
{
	int i;
	int nhash;
	int nhasht;

	i = 0;
	nhash = 0;
	nhasht = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if (i >= 1 && s[i - 1] == '#')
				nhash++;
			else if (s[i + 1] == '#' || s[i + 5] == '#')
				nhash++;
			else if (i >= 5 && s[i - 5] == '#')
				nhash++;
			nhasht++;
		}
		i++;
	}
	return (nhash == 4 && nhasht == 4);
}

int			touching_tetris(char *s)
{
	int i;
	int ntouch;
	int mintouch;

	i = 0;
	mintouch = 0;
	while (i < 20)
	{
		ntouch = 0;
		if (s[i] == '#')
		{
			if (i >= 1 && s[i - 1] == '#')
				ntouch++;
			if (s[i + 1] == '#')
				ntouch++;
			if (s[i + 5] == '#')
				ntouch++;
			if (i >= 5 && s[i - 5] == '#')
				ntouch++;
		}
		if (ntouch > mintouch)
			mintouch = ntouch;
		i++;
	}
	return (mintouch);
}

char		*ft_file_to_string(int fd)
{
	char	b[BUFS];
	char	*str;
	int		ret;
	int		total;

	total = 0;
	while ((ret = read(fd, &b, BUFS + 1)))
	{
		total += ret;
		b[ret] = '\0';
		if (total == ret)
		{
			if (!(str = (char*)malloc(sizeof(str) * (total + 1))))
				return (0);
			str = ft_strcat(str, b);
		}
		else
			str = ft_strcat(str, b);
	}
	close(fd);
	return (str);
}
