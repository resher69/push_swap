/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 10:19:14 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/07 12:53:04 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			init_mlx(t_win *mlx, int mode)
{
	if (mode == 0)
	{
		mlx->map->begx = WIDTH / 4;
		mlx->map->begy = HEIGHT / 4;
		mlx->map->scale = 10;
		mlx->map->alt = 0;
		mlx->map->z = 2;
		mlx->map->z2 = 2;
		return (0);
	}
	mlx_clear_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_image(mlx->mlx_ptr, mlx->mlx_img);
	create_image(mlx, &mlx->map->bpp, &mlx->map->size, &mlx->map->endian);
	return (0);
}

void		free_mlx(t_win *mlx)
{
	ft_free_tab((void **)mlx->map->tab);
	free(mlx->map);
	free(mlx);
	exit(EXIT_SUCCESS);
}

void		create_image(t_win *mlx, int *bpp, int *size, int *endian)
{
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, HEIGHT, WIDTH);
	mlx->mlx_data = mlx_get_data_addr(mlx->mlx_img, bpp, size, endian);
	put_point(mlx, mlx->map);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->mlx_img, 0, 0);
}
