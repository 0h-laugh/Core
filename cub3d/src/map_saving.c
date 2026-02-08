/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_saving.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:07:43 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:07:45 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strcpy_2(char *dst, const char *src, int size)
{
	int	i;
	int	sizee;

	i = 0;
	sizee = ft_strlen(src);
	while (i < size)
	{
		if (src[i] == ' ' || i >= sizee || src[i] == '\n')
			dst[i] = 'X';
		else
			dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**allocate_2d_char_array(int rows, int cols)
{
	char	**array;
	int		i;

	array = (char **)malloc(rows * sizeof(char *));
	if (!array)
	{
		write(2, "Memory allocation failed!\n", 26);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < rows)
	{
		array[i] = (char *)malloc(cols * sizeof(char));
		if (!array[i])
		{
			write(2, "Row allocation failed!\n", 24);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (array);
}

void	alloc_map(t_game *game, char *str)
{
	int		fd_map;
	char	*line;
	int		i;

	i = 0;
	game->map.valid_map = allocate_2d_char_array(
			game->map.highest_y, game->map.highest_x + 1);
	fd_map = open(str, O_RDONLY);
	while (i++ < game->map.lines_tilmap)
	{
		line = get_next_line(fd_map);
		free(line);
	}
	i = 0;
	line = get_next_line(fd_map);
	while (line)
	{
		ft_strcpy_2(game->map.valid_map[i++], line, game->map.highest_x);
		free(line);
		line = get_next_line(fd_map);
	}
	close(fd_map);
}
