/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:13:56 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/07 12:51:33 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <mlx.h>

# define HEIGHT 1920
# define WIDTH 1080

typedef struct		s_i
{
	int				**tab;
	int				fd;
	int				lines;
	int				len;
	int				z;
	int				z2;
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				sx;
	int				sy;
	int				dx;
	int				dy;
	int				begx;
	int				begy;
	int				alt;
	int				scale;
	int				endian;
	int				bpp;
	int				size;
	unsigned int	color;
}					t_i;

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*mlx_win;
	char			*mlx_data;
	void			*mlx_img;
	t_i				*map;
}					t_win;

void				free_mlx(t_win *mlx);
int					get_value_1(t_i *map, int i, int j, int sc);
int					get_value_2(t_i *map, int i, int j, int sc);
void				create_image(t_win *mlx, int *bpp, int *size, int *endian);
int					gcolor(int alt);
void				init_first_mlx(t_win *mlx);
void				put_color_to_image(int alt, t_win *mlx, int x, int y);
int					init_mlx(t_win *mlx, int mode);
int					key_hook(int keycode, t_win *mlx);
int					mouse_hook(int button, int x, int y, t_win *mlx);
int					get_alt(int alt, int alt_z);
int					put_point(t_win *mlx, t_i *map);
int					*create_line(char *line);
void				create_lines(int i, char *av, t_i *map);
int					check_arg(int ac, char **av, t_i *map);
void				print_error(char *error);
int					get_len(char *line);
void				free_tab(int **tab, int len);
int					motion_hook(int x, int y, t_win *mlx);
#endif
