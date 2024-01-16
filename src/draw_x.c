/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:53:06 by jaurasma          #+#    #+#             */
/*   Updated: 2023/03/06 16:56:50 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	x(t_map *map, t_coords *coords)
{
	int	dif;

	dif = 0;
	if (coords->x < map->width -1)
		dif = map->map[coords->y][coords->x + 1] \
		- map->map[coords->y][coords->x];
	return (dif * map->z_scale);
}

void	init_coords_x(t_coords *coords, t_map *map)
{
	coords->y = 0;
	coords->x = 0;
	coords->angle = 1.5;
	map->z_scale = 3;
	coords->x1 = W_W / 2 - (map->height * map->l_l / 2);
	coords->y1 = W_H / 2 - (map->height * map->l_l) + map->map[0][0];
	coords->x2 = coords->x1 + map->l_l;
	coords->y2 = (coords->y1 + map->l_l / coords->angle) - x(map, coords);
}
