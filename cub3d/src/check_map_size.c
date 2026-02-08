/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:06:59 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:07:00 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_x_and_y(t_game *game, char *str, int i)
{
	char	*line;
	int		fd_sizes;
	int		temp;

	fd_sizes = open(str, O_RDONLY);
	while (i++ < game->map.lines_tilmap)
	{
		line = get_next_line(fd_sizes);
		free(line);
	}
	line = get_next_line(fd_sizes);
	if (!line)
		printf("Error No Map");
	temp = ft_strlen(line) - 1;
	while (1)
	{
		if (!line)
			break ;
		game->map.highest_y++;
		if (game->map.highest_x < temp)
			game->map.highest_x = temp;
		free(line);
		line = get_next_line(fd_sizes);
	}
	close(fd_sizes);
}
