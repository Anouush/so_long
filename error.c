/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:31:32 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 13:06:56 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	ft_exit_door(t_map *map)
{
	if (map->an_collect == 0)
	{
		ft_printf("Congrats! You´ve done it in %d steps!\n", map->n_steps);
		ft_game_over(map);
	}
	else
		ft_printf("%d items left to collect.\n", map->an_collect);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i <= map->n_lines)
	{
		free(map->chart[i]);
		i++;
	}
}

void	ft_game_over(t_map *map)
{
	mlx_terminate(map->mlx);
	ft_free_map(map);
	exit(EXIT_SUCCESS);
}
