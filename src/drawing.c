/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:48:21 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/28 19:44:32 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	scaler(t_map *map)
{
	int	i;

	i = 0;
	while (map->height * i < W_H && map->width * i < W_W)
		i++;
	if (i > 1)
		map->l_l = i / 2;
	else
		map->l_l = 1;
}

int	my_abs(int num)
{
	if (num >= 0)
		return (num);
	else
		return (num * -1);
}

void	init_draw(t_draw *draw, t_coords *coords)
{
	draw->x1 = coords->x1;
	draw->y1 = coords->y1;
	draw->x2 = coords->x2;
	draw->y2 = coords->y2;
	draw->dx = my_abs(draw->x2 - draw->x1);
	draw->dy = my_abs(draw->y2 - draw->y1);
	draw->err = draw->dx - draw->dy;
	draw->sx = -1;
	draw->sy = -1;
	if (draw->x1 < draw->x2)
		draw->sx = 1;
	if (draw->y1 < draw->y2)
		draw->sy = 1;
}

void	draw_line(t_data *img, t_coords *coords, int color)
{
	t_draw		draw;

	init_draw(&draw, coords);
	while (1)
	{
		if ((draw.x1 > 0 && draw.y1 > 0) && (draw.x1 < W_W && draw.y1 < W_H))
			my_mlx_pixel_put(img, draw.x1, draw.y1, color);
		if (draw.x1 == draw.x2 && draw.y1 == draw.y2)
			break ;
		draw.e2 = 2 * draw.err;
		if (draw.e2 > -draw.dy)
		{
			draw.err -= draw.dy;
			draw.x1 += draw.sx;
		}
		if (draw.e2 < draw.dx)
		{
			draw.err += draw.dx;
			draw.y1 += draw.sy;
		}
	}
}
