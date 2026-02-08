/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_vals_logic.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:07:10 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:07:11 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_for_all(t_game *game)
{
	if (game->textures.no_path != NULL && game->textures.we_path != NULL
		&& game->textures.so_path != NULL
		&& game->textures.ea_path != NULL && game->textures.F != NULL
		&& game->textures.C != NULL)
		return (true);
	return (false);
}

void	find_id(char *str, t_game *game)
{
	char	*value;

	value = ft_strchr(str, ' ');
	if (!value || !*(value + 1))
		return ((void)printf(
				"Error: Brak wartości dla identyfikatora -> %s\n", str));
	value = ft_strtrim(value + 1, " \n");
	if (!value)
		return ((void)printf("Error: ft_strtrim() zwrócił NULL\n"));
	if (!ft_strncmp(str, "NO", 2))
		game->textures.no_path = value;
	else if (!ft_strncmp(str, "SO", 2))
		game->textures.so_path = value;
	else if (!ft_strncmp(str, "WE", 2))
		game->textures.we_path = value;
	else if (!ft_strncmp(str, "EA", 2))
		game->textures.ea_path = value;
	else if (!ft_strncmp(str, "C", 1))
		game->textures.C = value;
	else if (!ft_strncmp(str, "F", 1))
		game->textures.F = value;
	else
		return ((void)(printf("Error: Nieznany identyfikator -> %s\n", str),
			free(value)));
}

bool	is_map_part(t_game *game, char *str)
{
	int	i;

	if (str[0] == '\n')
		return (false);
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '1')
			i++;
		else
			break ;
	}
	if ((ft_strlen(str) - 1 == (size_t)i) && check_for_all(game))
	{
		printf("returned true\n");
		return (true);
	}
	return (false);
}

bool	is_not_map_format(const char *str)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	while (str[i] == ' ' || str[i] == '0' || str[i] == '1' || str[i] == 'N'
		|| str[i] == 'S' || str[i] == 'W' || str[i] == 'E' || str[i] == '\n')
		i++;
	if ((size_t)i != len)
		return (1);
	return (0);
}

void	fill_map_vals(t_game *game, char *str)
{
	char	*line;
	int		fd_vals;
	bool	map_started;

	map_started = false;
	fd_vals = open(str, O_RDONLY);
	line = get_next_line(fd_vals);
	while (line)
	{
		if (!map_started)
			game->map.lines_tilmap++;
		if (is_only_whitespace(line, map_started))
			;
		else if (!map_started && is_map_part(game, line))
			map_started = true;
		else if (!map_started)
			find_id(line, game);
		free(line);
		line = get_next_line(fd_vals);
	}
	close(fd_vals);
}
