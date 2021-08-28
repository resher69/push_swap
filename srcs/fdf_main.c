/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:13:28 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/07 11:34:32 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			draw_line(int alt, t_i *map, t_win *mlx)
{
	int		err;
	int		e2;

	map->dx = map->x1 - map->x;
	map->dy = ft_abs(map->y1 - map->y);
	map->sx = 1;
	map->sy = map->y < map->y1 ? 1 : -1;
	err = (map->dx > map->dy ? map->dx : -map->dy) / 2;
	while (map->x != map->x1)
	{
		put_color_to_image(alt, mlx, map->x, map->y);
		e2 = err;
		if (e2 > -map->dx)
		{
			err -= map->dy;
			map->x += map->sx;
		}
		if (e2 < map->dy)
		{
			err += map->dx;
			map->y += map->sy;
		}
	}
	return (0);
}

void		put_color_to_image(int alt, t_win *mlx, int x, int y)
{
	int		r_;
	int		g_;
	int		b_;

	if (x >= HEIGHT || y < 0 || y >= WIDTH || x < 0)
		return ;
	mlx->map->color = mlx_get_color_value(mlx->mlx_ptr, gcolor(alt));
	r_ = (mlx->map->color & 0xFF);
	g_ = (mlx->map->color & 0xFF00) >> 8;
	b_ = (mlx->map->color & 0xFF0000) >> 16;
	mlx->mlx_data[y * mlx->map->size + x * mlx->map->bpp / 8] = r_;
	mlx->mlx_data[y * mlx->map->size + x * mlx->map->bpp / 8 + 1] = g_;
	mlx->mlx_data[y * mlx->map->size + x * mlx->map->bpp / 8 + 2] = b_;
}

int			put_point(t_win *mlx, t_i *map)
{
	int		i;
	int		j;

	i = 0;
	while (map->tab[i])
	{
		j = 1;
		while (j - 1 < map->tab[i][0])
		{
			if (map->tab[i + 1] != NULL && j <= map->tab[i + 1][0])
				draw_line(get_value_1(map, i, j, mlx->map->scale), map, mlx);
			if (j - 1 < map->tab[i][0] - 1)
				draw_line(get_value_2(map, i, j, mlx->map->scale), map, mlx);
			j++;
		}
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_win	*mlx;

	if ((mlx = (t_win *)malloc(sizeof(t_win))) == NULL)
		return (0);
	if ((mlx->map = (t_i *)malloc(sizeof(t_i))) == NULL)
		return (0);
	create_lines(check_arg(argc, argv, mlx->map), argv[1], mlx->map);
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, "FDF MASTER");
	init_mlx(mlx, 0);
	create_image(mlx, &mlx->map->bpp, &mlx->map->size, &mlx->map->endian);
	mlx_hook(mlx->mlx_win, 2, 64, key_hook, mlx);
	mlx_hook(mlx->mlx_win, 4, 64, mouse_hook, mlx);
	mlx_loop(mlx->mlx_ptr);
	free_mlx(mlx);
	return (0);
}
