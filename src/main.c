/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:39:41 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/14 13:09:54 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		player_x;
	int		player_y;

	check_the_arguments(argc, argv);
	game.mlx = mlx_init();
	game.moves = 0;
	read_map(&game, argv[1]);
	find_player(game.map, &player_x, &player_y);
	game.player_on_exit = 0;
	game.player_x = player_x;
	game.player_y = player_y;
	check_map(&game, player_x, player_y);
	game.window = mlx_new_window(game.mlx, game.map_width * 64, game.map_height
			* 64, "so_long");
	load_imgs(&game);
	load_map(&game);
	mlx_hook(game.window, 17, 0, close_window, &game);
	mlx_key_hook(game.window, assigned_keys, &game);
	mlx_loop(game.mlx);
	free_map(game.map);
	return (0);
}
