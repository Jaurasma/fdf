/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:45:58 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/28 14:59:37 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_map(t_map *map)
{
	int	y;

	y = map->height -1;
	while (y >= 0)
	{
		free(map->map[y]);
		y--;
	}
	free(map->map);
}

int	handle_keypress(int keysym, t_win_data *data)
{
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		exit (0);
	}
	return (0);
}

int	handle_cross(t_win_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	exit (0);
	return (0);
}

int	color(t_map *map, int y, int x)
{
	if (map->map[y][x] < 3)
		return (0xC9B311);
	else if (map->map[y][x] < 6)
		return (0xDF855A);
	else if (map->map[y][x] < 13)
		return (0xB2497F);
	else if (map->map[y][x] < 18)
		return (0x7F1B9F);
	else
		return (0x270f8f);
}

void	exit_without_free(void)
{
	ft_printf("\033[0;31mHow to use: ./fdf [map name]\n");
	exit (1);
}
