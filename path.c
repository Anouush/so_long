/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:26:09 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 17:50:25 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_copy(char **copy)
{
	int	i;

	i = 0;
	if (!copy)
		return ;
	while (copy[i])
		free(copy[i++]);
	free(copy);
}

char	**ft_map_cpy(t_map *map)
{
	char	**copy;
	int		y;

	y = 0;
	copy = (char **)ft_calloc(sizeof(char *), (map->n_lines + 1));
	while (y < map->n_lines)
	{
		copy[y] = ft_substr(map->chart[y], 0, ft_strlen(map->chart[y]));
		y++;
	}
	return (copy);
}

void	ft_fill_map(char **copy, int y, int x)
{
	if (copy[y][x + 1] == '0' || copy[y][x + 1] == 'E' || copy[y][x + 1] == 'C')
	{
		copy[y][x + 1] = 'f';
		ft_fill_map(copy, y, x + 1);
	}
	if (copy[y][x - 1] == '0' || copy[y][x - 1] == 'E' || copy[y][x - 1] == 'C')
	{
		copy[y][x - 1] = 'f';
		ft_fill_map(copy, y, x - 1);
	}
	if (copy[y + 1][x] == '0' || copy[y + 1][x] == 'E' || copy[y + 1][x] == 'C')
	{
		copy[y + 1][x] = 'f';
		ft_fill_map(copy, y + 1, x);
	}
	if (copy[y - 1][x] == '0' || copy[y - 1][x] == 'E' || copy[y - 1][x] == 'C')
	{
		copy[y - 1][x] = 'f';
		ft_fill_map(copy, y - 1, x);
	}
}

void	ft_check_path(t_map *map)
{
	char	**copy_map;
	int		y;
	int		x;
	int		flag;
	int		coins;

	flag = 0;
	coins = 0;
	copy_map = ft_map_cpy(map);
	ft_fill_map(copy_map, map->player.y, map->player.x);
	y = -1;
	while (++y < map->n_lines)
	{
		x = -1;
		while (++x < map->n_colum)
		{
			if (map->chart[y][x] == 'E' && copy_map[y][x] == 'f')
				flag = 1;
			else if (map->chart[y][x] == 'C' && copy_map[y][x] == 'f')
				coins++;
		}
	}
	ft_free_copy(copy_map);
	if (flag == 0 || coins != map->n_collect)
		ft_put_error("There is no a valid path in the map\n");
}
