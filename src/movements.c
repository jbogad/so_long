/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:59:49 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/19 09:47:00 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	collect_counter(char **map)
{
	int	y;
	int	x;
	int	collect_counter;

	collect_counter = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				collect_counter++;
			x++;
		}
		y++;
	}
	return (collect_counter);
}

void	handle_player_tile(t_game *game, char next_tile, int collect)
{
	if (next_tile == 'E' && collect != 0)
	{
		if (game->player_on_exit)
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->player_on_exit = 1;
	}
	else
	{
		if (game->player_on_exit)
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->player_on_exit = 0;
		if (next_tile == 'E' && collect == 0)
			close_window(game);
	}
}

int	update_position(t_game *game, int key, int *x_update, int *y_update)
{
	*x_update = game->player_x;
	*y_update = game->player_y;
	if (key == 65362 || key == 'w')
		(*y_update)--;
	else if (key == 65364 || key == 's')
		(*y_update)++;
	else if (key == 65361 || key == 'a')
		(*x_update)--;
	else if (key == 65363 || key == 'd')
		(*x_update)++;
	if (*x_update < 0 || *y_update < 0 || *y_update >= game->map_height
		|| *x_update >= game->map_width)
		return (0);
	if (game->map[*y_update][*x_update] == '1')
		return (0);
	return (1);
}

int	move_player(t_game *game, int key)
{
	int		x_update;
	int		y_update;
	int		collected;
	char	next_pos;

	collected = collect_counter(game->map);
	if (!update_position(game, key, &x_update, &y_update))
		return (0);
	next_pos = game->map[y_update][x_update];
	handle_player_tile(game, next_pos, collected);
	game->map[y_update][x_update] = 'P';
	game->player_x = x_update;
	game->player_y = y_update;
	game->moves++;
	printf("%d\n", game->moves);
	load_map(game);
	return (0);
}
