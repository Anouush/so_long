/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:48:13 by angalsty          #+#    #+#             */
/*   Updated: 2023/03/08 17:48:50 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_pos
{
	int	y;
	int	x;
}			t_pos;

typedef struct s_moves
{
	t_pos	up;
	t_pos	down;
	t_pos	right;
	t_pos	left;

}			t_moves;

typedef struct s_map
{
	char		**chart;
	int			n_colum;
	int			n_lines;
	int			n_player;
	int			n_collect;
	int			an_collect;
	int			exit;
	t_pos		player;
	int			collected;
	char		*map_path;
	mlx_t		*mlx;
	mlx_image_t	*wimg;
	mlx_image_t	*bimg;
	mlx_image_t	*eimg;
	mlx_image_t	*oeimg;
	mlx_image_t	*pimg;
	mlx_image_t	*cimg;
	t_moves		move;
	int			n_steps;
}			t_map;

void	t_creat_map(t_map *map);
void	ft_check_name(char *name, t_map *map);
void	ft_player_pos(t_map *map, int x, int y);

void	ft_is_rect(char *line, size_t size);
void	ft_count_lines(t_map *map);
void	ft_count_colums(t_map *map);
int		ft_check_horizontal(t_map *map);
int		ft_check_vertical(t_map *map);
int		ft_check_walls(t_map *map);

void	ft_save_map(t_map *map);
void	counter(t_map *map, char c);
int		ft_check_map(t_map *map);

char	**ft_map_cpy(t_map *map);
void	ft_fill_map(char **copy, int y, int x);
void	ft_check_path(t_map *map);

void	ft_free_map(t_map *map);
void	ft_exit_door(t_map *map);
void	ft_game_over(t_map *map);
void	ft_put_error(char *str);

void	ft_new_chart(t_map *map);
void	ft_init_window(t_map *map);
void	ft_init_moves(t_map *map);

void	ft_draw_map(t_map *map);
void	ft_save_images(t_map *map);

void	moves(t_map *map, t_pos *move);
void	my_key_hook(mlx_key_data_t keydata, void *param);

#endif 
