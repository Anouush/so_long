/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:16:15 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 17:16:56 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_n_door(t_map *map)
{
	map->an_collect--;
	if (map->an_collect == 0)
	{
		map->eimg->instances[0].enabled = false;
		mlx_image_to_window(map->mlx, map->oeimg,
			map->eimg->instances[0].x, map->eimg->instances[0].y);
	}
}

static void	ft_check_collect(t_map *map, t_pos *player)
{
	char	temp;
	int		i;

	temp = map->chart[player->y][player->x];
	if (temp == 'C')
	{
		ft_n_door(map);
		ft_printf("%d items left to collect.\n", map->an_collect);
		map->chart[player->y][player->x] = '0';
		i = 0;
		while (i < map->n_collect)
		{
			if (map->cimg->instances[i].y == map->pimg->instances[0].y
				&& map->cimg->instances[i].x == map->pimg->instances[0].x)
				map->cimg->instances[i].enabled = false;
			i++;
		}
	}
	else if (temp == 'E')
	{
		ft_exit_door(map);
	}
}

static int	ft_check_position(t_map *map, t_pos *go)
{
	int	x;
	int	y;

	y = map->player.y + go->y;
	x = map->player.x + go->x;
	if (map->chart[y][x] == '1')
		return (0);
	else
		return (1);
}

void	moves(t_map *map, t_pos *go)
{
	if (ft_check_position(map, go))
	{
		map->player.x += go->x;
		map->player.y += go->y;
		map->pimg->instances[0].x = map->player.x * 64;
		map->pimg->instances[0].y = map->player.y * 64;
		map->n_steps++;
		ft_printf("Player steps: %d\n", map->n_steps);
		ft_check_collect(map, &map->player);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;
	t_moves	*move;

	map = param;
	move = &map->move;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		moves(map, &move->up);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		moves(map, &move->down);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		moves(map, &move->right);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		moves(map, &move->left);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_game_over(map);
}
