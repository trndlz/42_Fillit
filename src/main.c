/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:39:05 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/16 11:24:50 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int ac, char **av)
{
	int			fd;
	char		*str;
	int			n_tetri;
	t_tetri		*tetri;

	str = NULL;
	if (ac != 2)
	{
		ft_putstr("usage: fillit sample_file\n");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	str = ft_file_to_string(fd);
	if (!str)
		ft_error();
	ft_chck_inp_str(str);
	tetri = build_tetri(str);
	n_tetri = nb_tetri(str);
	fillit(n_tetri, tetri, min_map_size(4 * n_tetri));
	free(str);
	return (0);
}
