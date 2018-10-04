/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:27:00 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/16 11:07:58 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFS 4096
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_tetri
{
	t_point			*coord;
	int				id;
}					t_tetri;

void				ft_error(void);
void				ft_chck_inp_str(char *s);
int					nb_tetri(char *s);
int					valid_tetri(char *s);
t_point				*str_to_point(char *s);
void				ft_print(t_tetri *tab, char *s);
int					get_xmin(t_point *coord);
int					get_ymin(t_point *coord);
void				move_upper_left(t_point *coord);
t_tetri				*build_tetri(char *s);
char				*ft_file_to_string(int fd);
int					fillit(int nb_tetri, t_tetri *tetri, int map_size);
int					place_tetri(int nb_tetri, t_tetri *tetri,
						char **map, int tetri_id);
int					min_map_size(int nhash);
int					get_map_size(char **map);
void				print_map(char **map);
char				**create_map(int map_size);
int					touching_tetris(char *s);
int					map_available(char **map, t_tetri tetri, int x, int y);
void				add_tetri(char **map, t_tetri tetri, int x, int y);
void				rem_tetri(char **map, t_tetri tetri, int x, int y);
size_t				ft_strlen(const char *str);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *dest, const char *src);
void				ft_putstr(char const *s);
void				*ft_memset(void *str, int c, size_t n);

#endif
