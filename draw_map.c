/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:29:08 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 19:35:23 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_img(t_map *map, mlx_image_t **img, char *path)
{
	mlx_texture_t	*text;

	text = mlx_load_png(path);
	if (text == NULL)
	{
		mlx_close_window(map->mlx);
		ft_free_map(map);
	}
	else
	{
		*img = mlx_texture_to_image(map->mlx, text);
		mlx_delete_texture(text);
	}
}

void	ft_save_images(t_map *map)
{
	ft_check_img(map, &map->wimg, "./images/wall.png");
	ft_check_img(map, &map->bimg, "./images/back.png");
	ft_check_img(map, &map->pimg, "./images/player.png");
	ft_check_img(map, &map->eimg, "./images/exit.png");
	ft_check_img(map, &map->cimg, "./images/collect.png");
	ft_check_img(map, &map->oeimg, "./images/oexit.png");
}

static void	ft_background(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	ft_save_images(map);
	while (y < map->n_lines)
	{
		x = 0;
		while (x < map->n_colum)
		{
			mlx_image_to_window(map->mlx, map->bimg, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_draw_map(t_map *map)
{
	int	y;
	int	x;

	ft_background(map);
	y = 0;
	while (y < map->n_lines)
	{
		x = 0;
		while (x < map->n_colum)
		{
			if (map->chart[y][x] == '1')
				mlx_image_to_window(map->mlx, map->wimg, x * 64, y * 64);
			else if (map->chart[y][x] == 'P')
				mlx_image_to_window(map->mlx, map->pimg, x * 64, y * 64);
			else if (map->chart[y][x] == 'E')
				mlx_image_to_window(map->mlx, map->eimg, x * 64, y * 64);
			else if (map->chart[y][x] == 'C')
				mlx_image_to_window(map->mlx, map->cimg, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
