/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:17:27 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/09 10:43:13 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_map(t_game *game, char zone, int x, int y)
{
	if (zone == '1')
		mlx_put_image_to_window(game->mlx, game->window, game->img_wall,
			x * 64, y * 64);
	else if (zone == '0')
		mlx_put_image_to_window(game->mlx, game->window, game->img_floor,
			x * 64, y * 64);
	else if (zone == 'P')
		mlx_put_image_to_window(game->mlx, game->window, game->img_player,
			x * 64, y * 64);
	else if (zone == 'C')
		mlx_put_image_to_window(game->mlx, game->window, game->img_collectable,
			x * 64, y * 64);
	else if (zone == 'E')
		mlx_put_image_to_window(game->mlx, game->window, game->img_exit,
			x * 64, y * 64);
}

void	load_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			draw_map (game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	count_lines(const char *file)
{
	int		fd;
	char	*line;
	int		counter;

	fd = open(file, O_RDONLY);
	counter = 0;
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free (line);
		counter++;
		line = get_next_line(fd);
	}
	close (fd);
	return (counter);
}

void	read_map(t_game *game, const char *file)
{
	int		fd;
	char	*line;
	int		i;

	game->map_height = count_lines(file);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	game->map_width = ft_strlen(game->map[0]);
	close(fd);
}
