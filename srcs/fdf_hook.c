/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 11:58:20 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/07 12:52:51 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			key_hook(int keycode, t_win *mlx)
{
	if (keycode == 53)
		free_mlx(mlx);
	else if (keycode == 123)
		mlx->map->begx = mlx->map->begx - 30;
	else if (keycode == 124)
		mlx->map->begx = mlx->map->begx + 30;
	else if (keycode == 125)
		mlx->map->begy = mlx->map->begy + 30;
	else if (keycode == 126)
		mlx->map->begy = mlx->map->begy - 30;
	else if (keycode == 0)
		mlx->map->scale = mlx->map->scale + 1;
	else if (keycode == 2)
		mlx->map->scale += mlx->map->scale > 1 ? -1 : 0;
	else if (keycode == 37)
		mlx->map->z += mlx->map->z < 20 ? 1 : 0;
	else if (keycode == 40)
		mlx->map->z += mlx->map->z > 1 ? -1 : 0;
	else if (keycode == 31)
		mlx->map->z2 += mlx->map->z2 < 20 ? 1 : 0;
	else if (keycode == 34)
		mlx->map->z2 += mlx->map->z2 > 1 ? -1 : 0;
	else if (keycode == 15)
		init_mlx(mlx, 0);
	return (init_mlx(mlx, -1));
}

int			mouse_hook(int button, int x, int y, t_win *mlx)
{
	(void)x;
	(void)y;
	if (button == 5)
		mlx->map->alt = mlx->map->alt + 2;
	if (button == 4)
		mlx->map->alt = mlx->map->alt - 2;
	init_mlx(mlx, -1);
	return (0);
}
