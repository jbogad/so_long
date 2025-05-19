/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 00:13:06 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/11 00:14:34 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "fcntl.h"
# include "stdio.h"
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*window;

	char	**map;
	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;
	int		moves;
	int		player_on_exit;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectable;
}	t_game;

/*==============validation==================*/
void	check_the_arguments(int argc, char **argv);

/*===============find-player================*/
void	find_player(char **map, int *player_x, int *player_y);

/*===============check-map==================*/
void	check_map(t_game *game, int player_x, int player_y);
int		check_correct_map(char **map, int player_count, int exit_count,
			int collectable_count);
int		is_rectangular(char **map);
int		wall_is_ok(char **map);
int		the_camin_is_ok(char **map, int height, int player_x, int player_y);

/*=============load_map=====================*/
void	load_imgs(t_game *game);

/*=================map======================*/
int		count_lines(const char *file);
void	read_map(t_game *game, const char *file);
void	draw_map(t_game *game, char zone, int x, int y);
void	load_map(t_game *game);

/*============close_window==================*/
int		close_window(t_game *game);

/*==============free========================*/
void	free_map(char **map);

/*============assigned_keys=================*/
int		assigned_keys(int key, t_game *game);

/*=============move_player==================*/
int		move_player(t_game *game, int key);

#endif