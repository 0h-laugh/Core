/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:07:54 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:07:55 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	directions
	0 - starting point (sends everywhere)
	1 - signal from left
	2 - signal from right
	3 - signal from top
	4 - singal from bottom
*/

bool	is_player_value(char c)
{
	if (c == 'S' || c == 'W' || c == 'N' || c == 'E')
		return (0);
	return (1);
}

bool	x_check(t_game *game, int x, int y)
{
	game->map.valid_map[y][x] = 'x';
	x_check_dirs(game, x, y);
	if (y > 0)
	{
		if (game->map.valid_map[y - 1][x] == 'X')
			x_check(game, x, y - 1);
		else if (game->map.valid_map[y - 1][x] == 'P')
			printf("Player out of map\n");
		else if (game->map.valid_map[y - 1][x] == '0')
			printf("Fatal Error\n");
	}
	if (y < game->map.highest_y - 1)
	{
		if (game->map.valid_map[y + 1][x] == 'X')
			x_check(game, x, y + 1);
		else if (game->map.valid_map[y + 1][x] == 'P')
			printf("Player out of map\n");
		else if (game->map.valid_map[y + 1][x] == '0')
			printf("Fatal Error\n");
	}
	return (1);
}

bool	player_in_map(t_game *game, int pos_x, int pos_y)
{
	if (game->map.valid_map[pos_y][pos_x - 1] == 'X')
		printf("Fatal Error\n");
	if (game->map.valid_map[pos_y][pos_x + 1] == 'X')
		printf("Fatal Error\n");
	if (game->map.valid_map[pos_y - 1][pos_x] == 'X')
		printf("Fatal Error\n");
	if (game->map.valid_map[pos_y + 1][pos_x] == 'X')
		printf("Fatal Error\n");
	return (1);
}

void	check_boundaries_x(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.highest_x)
	{
		if (game->map.valid_map[0][i] == '0')
			printf("error");
		else if (game->map.valid_map[0][i] == 'X')
			x_check(game, i, 0);
		i++;
	}
	i = 0;
	while (i < game->map.highest_x)
	{
		if (game->map.valid_map[game->map.highest_y - 1][i] == '0')
			printf("error");
		else if (game->map.valid_map[game->map.highest_y -1][i] == 'X')
			x_check(game, i, game->map.highest_y - 1);
		i++;
	}
}

void	check_boundaries_y(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.highest_y)
	{
		if (game->map.valid_map[i][0] == '0')
			printf("error");
		else if (game->map.valid_map[i][0] == 'X')
			x_check(game, 0, i);
		i++;
	}
	i = 0;
	while (i < game->map.highest_y)
	{
		if (game->map.valid_map[i][game->map.highest_x - 1] == '0')
			printf("error %i | %i\n", i, game->map.highest_x - 1);
		else if (game->map.valid_map[i][game->map.highest_x - 1] == 'X')
			x_check(game, game->map.highest_x - 1, i);
		i++;
	}
}
