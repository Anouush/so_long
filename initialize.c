/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:29:27 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 17:08:41 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_chart(t_map *map)
{
	map->n_colum = 0;
	map->n_lines = 0;
	map->n_player = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->exit = 0;
	map->n_collect = 0;
	map->collected = 0;
}

void	ft_init_moves(t_map *map)
{
	map->move.up.x = 0;
	map->move.up.y = -1;
	map->move.down.x = 0;
	map->move.down.y = +1;
	map->move.right.x = +1;
	map->move.right.y = 0;
	map->move.left.x = -1;
	map->move.left.y = 0;
}

void	ft_init_window(t_map *map)
{
	int	win_w;
	int	win_h;

	win_w = map->n_colum * 64;
	win_h = map->n_lines * 64;
	map->mlx = mlx_init(win_w, win_h, "So long", true);
	if (!map->mlx)
	{
		ft_free_map(map);
		ft_put_error("Error!\nThe window couldn't be opened\n");
	}
}
