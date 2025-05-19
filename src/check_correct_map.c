/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_correct_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:15:43 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/09 10:23:45 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_correct_map(char **map, int player_count, int exit_count,
		int collectable_count)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				player_count++;
			else if (map[y][x] == 'E')
				exit_count++;
			else if (map[y][x] == 'C')
				collectable_count++;
			if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C'
				&& map[y][x] != '1' && map[y][x] != '0')
				return (0);
			x++;
		}
		y++;
	}
	if (player_count != 1 || exit_count != 1 || collectable_count < 1)
		return (0);
	return (1);
}

int	is_rectangular(char **map)
{
	int	y;
	int	x;
	int	first_line;

	if (!map || !map[0])
		return (0);
	first_line = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (y == 0)
				first_line++;
			x++;
		}
		if (first_line != x)
			return (0);
		y++;
	}
	return (1);
}

int	wall_is_ok(char **map)
{
	int	y;
	int	x;
	int	width;
	int	height;

	width = ft_strlen(map[0]);
	height = 0;
	while (map[height])
		height++;
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[height - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}
