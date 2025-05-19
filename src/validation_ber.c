/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_ber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 19:26:24 by jaboga-d          #+#    #+#             */
/*   Updated: 2025/05/09 10:43:26 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_the_arguments(int argc, char **argv)
{
	int	len;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return ;
	}
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + len - 4, ".ber", 4) != 0)
	{
		write(1, "invalid map extension\n", 22);
		exit (1);
	}
}
