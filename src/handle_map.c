/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaurasma <jaurasma@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:15:48 by jaurasma          #+#    #+#             */
/*   Updated: 2023/03/06 18:40:24 by jaurasma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_line_and_exit(char *line)
{
	free(line);
	exit(1);
}

int	count_width(char **temp)
{
	int		i;

	i = 0;
	while (temp[i] != NULL)
	{
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	free(temp);
	return (i);
}

void	map_handler(char **argv, t_map *map)
{
	int			fd;
	t_counter	count;

	count.i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	count.line = get_next_line(fd);
	count.temp = ft_split(count.line, ' ');
	if (!count.temp)
		free_line_and_exit(count.line);
	map->width = count_width(count.temp);
	while (count.line != NULL)
	{
		free(count.line);
		count.line = NULL;
		count.line = get_next_line(fd);
		count.i++;
	}
	map->height = count.i;
	close(fd);
	count.i = 0;
	save_map(map, argv, &count);
}

void	save_map(t_map *map, char **argv, t_counter *count)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit (1);
	map->map = (int **)malloc((sizeof(int *) * map->height));
	if (!map->map)
		return ;
	while (count->i < map->height)
	{
		count->j = 0;
		count->line = get_next_line(fd);
		count->temp = ft_split(count->line, ' ');
		free(count->line);
		map->map[count->i] = (int *)malloc(sizeof(int) * map->width + 1);
		while (count->temp[count->j] != NULL)
		{
			map->map[count->i][count->j] = ft_atoi(count->temp[count->j]);
			free(count->temp[count->j]);
			count->j++;
		}
		free(count->temp);
		count->i++;
	}
	close(fd);
}
