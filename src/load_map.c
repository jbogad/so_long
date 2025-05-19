/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:03:18 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/09 10:44:31 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_imgs(t_game *game)
{
	int	width;
	int	hight;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm",
			&width, &hight);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm",
			&width, &hight);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm",
			&width, &hight);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"imgs/collectable.xpm", &width, &hight);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm",
			&width, &hight);
	if (!game->img_wall || !game->img_player || !game->img_exit
		|| !game->img_collectable || !game->img_floor)
	{
		write(2, "Error xpm", 9);
		exit(1);
	}
}
