/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:30:01 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 19:08:58 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_lines(t_map *map)
{
	int		fd;
	char	*new_line;
	int		line;

	line = 0;
	fd = open(map->map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_put_error("Error!\n");
	}
	new_line = get_next_line(fd);
	while (new_line != NULL)
	{
		line++;
		free(new_line);
		new_line = get_next_line(fd);
	}
	close(fd);
	map->n_lines = line;
}

void	ft_save_map(t_map *map)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map->map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_put_error("Error!\nMap is not found\n");
	}
	map->chart = (char **)ft_calloc(sizeof(char *), map->n_lines + 1);
	while (i < map->n_lines)
	{
		map->chart[i] = get_next_line(fd);
		i++;
	}
	map->chart[i] = 0;
	close(fd);
}

void	counter(t_map *map, char c)
{
	if (c == 'P')
		map->n_player += 1;
	else if (c == 'E')
		map->exit++;
	else if (c == 'C')
		map->n_collect++;
	else if (c != '0' && c != '1')
	{
		ft_free_map(map);
		ft_put_error("Error.\nInvalid character on the map\n");
	}
}

int	ft_check_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->n_lines)
	{
		x = 0;
		while (x < map->n_colum)
		{
			if (map->chart[y][x] == 'P')
				ft_player_pos(map, y, x);
			counter(map, map->chart[y][x]);
			x++;
		}
		y++;
	}
	map->an_collect = map->n_collect;
	ft_check_walls(map);
	if (map->n_collect < 1 || map->exit != 1 || map->n_player != 1)
	{
		ft_free_map(map);
		ft_put_error("Error.\nPlayer, exit or collectables are not correct\n");
	}
	return (0);
}
