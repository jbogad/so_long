/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:28:40 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/09 10:24:23 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map(t_game *game, int player_x, int player_y)
{
	if (check_correct_map(game->map, 0, 0, 0) == 0)
	{
		ft_putstr_fd("ERROR, map incorrect\n", 2);
		free_map(game->map);
		exit(1);
	}
	if (is_rectangular(game->map) == 0)
	{
		ft_putstr_fd("Map no rectangular\n", 2);
		free_map(game->map);
		exit(1);
	}
	if (wall_is_ok(game->map) == 0)
	{
		ft_putstr_fd("map Wall is invalid\n", 2);
		free_map(game->map);
		exit(1);
	}
	if (the_camin_is_ok(game->map, game->map_height, player_x, player_y) == 0)
	{
		ft_putstr_fd("Map hasn't got a valid road\n", 2);
		free_map(game->map);
		exit(1);
	}
}
