/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 16:10:22 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/07 12:51:24 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			get_alt(int alt, int alt_z)
{
	if (alt > 0)
		return (alt + alt_z);
	if (alt < 0)
		return (alt - alt_z);
	return (alt);
}

int			get_value_1(t_i *map, int i, int j, int sc)
{
	int		alt;
	int		tmp;

	alt = get_alt(map->tab[i][j], map->alt);
	tmp = alt;
	map->x = map->begx + i * sc + j * sc;
	map->y = map->begy + i * sc / map->z - (j * sc / map->z2) - alt;
	map->x1 = map->begx + (i + 1) * sc + j * sc;
	alt = get_alt(map->tab[i + 1][j], map->alt);
	map->y1 = map->begy + (i + 1) * sc / map->z - (j * sc / map->z2) - alt;
	if (alt >= 0 && tmp >= 0)
		return (tmp > alt ? tmp : alt);
	return (tmp < alt ? tmp : alt);
}

int			get_value_2(t_i *map, int i, int j, int sc)
{
	int		alt;
	int		tmp;

	alt = get_alt(map->tab[i][j], map->alt);
	tmp = alt;
	map->x = map->begx + i * sc + j * sc;
	map->y = map->begy + i * sc / map->z - (j * sc / map->z2) - alt;
	map->x1 = map->begx + i * sc + (j + 1) * sc;
	alt = get_alt(map->tab[i][j + 1], map->alt);
	map->y1 = map->begy + i * sc / map->z - ((j + 1) * sc / map->z2) - alt;
	if (alt >= 0 && tmp >= 0)
		return (tmp > alt ? tmp : alt);
	return (tmp < alt ? tmp : alt);
}

int			gcolor(int alt)
{
	if (alt < 0)
		return (0x0033FF);
	if (alt < 5 && alt >= 0)
		return (0x336600);
	if (alt < 15 && alt >= 5)
		return (0x999966);
	if (alt >= 15 && alt <= 30)
		return (0x663300);
	return (0xFFFFFF);
}
