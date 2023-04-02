/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:19:48 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 19:43:49 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_player_pos(t_map *map, int y, int x)
{
	map->player.y = y;
	map->player.x = x;
}

void	ft_check_name(char *name, t_map *map)
{
	int		fd;
	char	*path;
	int		len;

	len = (ft_strlen(name));
	if (ft_strncmp(name + (len - 4), ".ber", 4) == 0)
	{
		path = ft_strjoin("./maps/", name);
		fd = open(path, O_RDONLY);
		if (fd == -1)
		{
			free(path);
			ft_put_error("Error\nMap not found.");
		}
		else
		{
			map->map_path = ft_strdup(path);
			free(path);
		}
		close(fd);
	}
	else
		ft_put_error("Error\nWrong name for the map\n");
}

void	ft_creat_map(t_map *map)
{
	ft_new_chart(map);
	ft_count_lines(map);
	ft_count_colums(map);
	ft_save_map(map);
	ft_check_map(map);
	ft_check_path(map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		ft_check_name(argv[1], &map);
		ft_creat_map(&map);
		ft_init_window(&map);
		ft_draw_map(&map);
		ft_init_moves(&map);
		mlx_key_hook(map.mlx, &my_key_hook, &map);
		mlx_loop(map.mlx);
		mlx_terminate(map.mlx);
	}
	else
	{
		ft_put_error("Error!\nThe number of arguments is not correct\n");
	}
	exit(EXIT_FAILURE);
	return (0);
}
