/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:30:22 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 19:21:25 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_is_rect(char *line, size_t size)
{
	char	*temp;
	size_t	i;

	temp = ft_strtrim(line, "\n");
	i = ft_strlen(temp);
	if (i == size)
		free (temp);
	else
	{
		ft_put_error("Error!\nMap is not rectangular\n");
	}
}

void	ft_count_colums(t_map *map)
{
	int		fd;
	int		col;
	char	*new_line;

	fd = open(map->map_path, O_RDONLY);
	if (fd == -1)
	{
		ft_put_error("Error!\n");
	}
	new_line = get_next_line(fd);
	if (!new_line)
		ft_put_error("Error!\nThere is no map in the file\n");
	col = ft_strlen(new_line) - 1;
	while (new_line != NULL)
	{
		ft_is_rect(new_line, col);
		free(new_line);
		new_line = get_next_line(fd);
	}
	close(fd);
	map->n_colum = col;
}

int	ft_check_horizontal(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->n_colum)
	{
		if (map->chart[0][x] == '1' && map->chart[map->n_lines - 1][x] == '1')
			x++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_vertical(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->n_lines)
	{
		if (map->chart[y][0] == '1' && map->chart[y][map->n_colum - 1] == '1')
			y++;
		else
			return (0);
	}
	return (1);
}

int	ft_check_walls(t_map *map)
{
	int	ver_wall;
	int	hor_wall;

	hor_wall = ft_check_horizontal(map);
	ver_wall = ft_check_vertical(map);
	if (hor_wall != 1 || ver_wall != 1)
	{
		ft_put_error("Error!\nThe walls are not correct\n");
	}
	return (0);
}
