/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camin_ok.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:27:00 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/19 12:28:30 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
copy one line of map
*/
char	*cpy_str(const char *str)
{
	size_t	i;
	size_t	len;
	char	*copy;

	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

/*
copy all map
*/
char	**copy_map(char **map, int height)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	while (i < height)
	{
		copy[i] = cpy_str(map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == 'F' || map[y][x] == '1')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	the_camin_is_ok(char **map, int height, int player_x, int player_y)
{
	char	**copy_map_new;
	int		x;
	int		y;

	copy_map_new = copy_map(map, height);
	if (!copy_map_new)
		return (0);
	flood_fill(copy_map_new, player_x, player_y);
	y = 0;
	while (copy_map_new[y])
	{
		x = 0;
		while (copy_map_new[y][x])
		{
			if (copy_map_new[y][x] == 'C' || copy_map_new[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	free_map(copy_map_new);
	return (1);
}
