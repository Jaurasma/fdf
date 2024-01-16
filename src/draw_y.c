/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:53:12 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/28 19:26:55 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	count_y(t_map *map, t_coords *coords)
{
	int	dif;

	dif = 0;
	if (coords->y < map->height - 1)
		dif = map->map[coords->y + 1][coords->x] \
		- map->map[coords->y][coords->x];
	return (dif * map->z_scale);
}

void	draw_y_lines(t_data *img, t_map *map, t_coords *coords)
{
	t_coords	y_coord;

	y_coord.x1 = coords->x1;
	y_coord.y1 = coords->y1;
	y_coord.x2 = y_coord.x1 - map->l_l;
	y_coord.y2 = (y_coord.y1 + map->l_l) - count_y(map, coords);
	draw_line(img, &y_coord, color(map, coords->y, coords->x));
}

void	draw_first_y_lines(t_data *img, t_map *map, t_coords *coords, \
t_x_save *save)
{	
	t_coords	y_coord;

	y_coord.x1 = coords->x1;
	y_coord.y1 = coords->y1;
	y_coord.x2 = y_coord.x1 - map->l_l;
	y_coord.y2 = (y_coord.y1 + map->l_l) - count_y(map, coords);
	draw_line(img, &y_coord, color(map, coords->y, coords->x));
	save->x_save = y_coord.x2;
	save->y_save = y_coord.y2;
}
