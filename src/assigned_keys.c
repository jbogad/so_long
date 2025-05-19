/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigned_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 10:51:44 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/11 00:09:56 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	assigned_keys(int key, t_game *game)
{
	if (key == 65307)
		close_window(game);
	else if (key == 65361 || key == 65362 || key == 65363
		|| key == 65364 || key == 'w' || key == 'a'
		|| key == 's' || key == 'd')
		move_player(game, key);
	return (0);
}
