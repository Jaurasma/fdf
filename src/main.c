/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:21:35 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/28 14:57:31 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_new_round(t_coords *coords, t_x_save *save, t_map *map)
{
	coords->x = 0;
	coords->x1 = save->x_save;
	coords->y1 = save->y_save;
	coords->x2 = coords->x1 + map->l_l;
	coords->y2 = (coords->y1 + map->l_l / coords->angle) - x(map, coords);
}

void	draw_grid(t_data *img, t_map *map, t_coords *coords)
{
	t_x_save	save;

	while (coords->y < map->height)
	{
		while (coords->x < map->width - 1)
		{
			draw_line(img, coords, color(map, coords->y, coords->x));
			if (coords->x == 0 && coords->y != map->height -1)
				draw_first_y_lines(img, map, coords, &save);
			coords->x++;
			coords->x1 = coords->x2;
			coords->y1 = coords->y2;
			if (coords->x > 0 && coords->y != map->height -1)
				draw_y_lines(img, map, coords);
			coords->x2 = coords->x1 + map->l_l;
			coords->y2 = coords->y1 + map->l_l / coords->angle - x(map, coords);
		}
		coords->y++;
		if (coords->y == map->height)
		{
			free_map(map);
			break ;
		}
		init_new_round(coords, &save, map);
	}
}

int	main(int argc, char **argv)
{
	t_win_data	window;
	t_data		img;
	t_map		map;
	t_coords	coords;

	if (argc != 2)
		exit_without_free();
	map.width = 0;
	map.height = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, W_W, W_H, "fdf");
	img.img = mlx_new_image(window.mlx_ptr, W_W, W_H);
	window.ptr = img.img;
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.l_len, &img.endian);
	map_handler(argv, &map);
	scaler(&map);
	init_coords_x(&coords, &map);
	draw_grid(&img, &map, &coords);
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img.img, 0, 0);
	mlx_key_hook(window.win_ptr, handle_keypress, &window);
	mlx_hook(window.win_ptr, 17, 0, handle_cross, window.mlx_ptr);
	mlx_loop(window.mlx_ptr);
	return (0);
}
