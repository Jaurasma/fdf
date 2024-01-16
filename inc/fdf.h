/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:06:01 by jaurasma          #+#    #+#             */
/*   Updated: 2023/02/28 19:33:27 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define  FDF_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>

# define W_W 2000
# define W_H 1000

typedef struct s_map
{
	int		width;
	int		height;
	int		l_l;
	int		**map;
	double	z_scale;
	int		x_save;
	int		y_save;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}	t_data;

typedef struct s_win_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	*ptr;
}	t_win_data;

typedef struct s_coords
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	double	angle;
	double	z_scale;
}	t_coords;

typedef struct s_x_save
{
	int	x_save;
	int	y_save;
}	t_x_save;

typedef struct s_draw
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
}	t_draw;

typedef struct s_counter
{
	int		i;
	int		j;
	char	*line;
	char	**temp;
}	t_counter;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_keypress(int keysym, t_win_data *data);
void	map_handler(char **argv, t_map *map);
void	scaler(t_map *map);
int		my_abs(int num);
int		handle_cross(t_win_data *data);
int		x(t_map *map, t_coords *coords);
int		count_y(t_map *map, t_coords *coords);
void	init_coords_x(t_coords *coords, t_map *map);
void	draw_y_lines(t_data *img, t_map *map, t_coords *coords);
void	draw_first_y_lines(t_data *img, \
		t_map *map, t_coords *coords, t_x_save *save);
void	draw_grid(t_data *img, t_map *map, t_coords *coords);
int		color(t_map *map, int x, int y);
void	free_map(t_map *map);
void	save_map(t_map *map, char **argv, t_counter *count);
void	draw_line(t_data *img, t_coords *coords, int color);
void	init_draw(t_draw *draw, t_coords *coords);
void	init_new_round(t_coords *coords, t_x_save *save, t_map *map);
void	exit_without_free(void);
int		count_width(char **temp);
void	free_line_and_exit(char *line);

#endif