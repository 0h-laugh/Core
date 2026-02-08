/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:08:01 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:08:01 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_player(t_game *game, float direction)
{
	game->player.pa += direction * ROTATE_SPEED;
}

void	move_player(t_game *game, float move_x, float move_y)
{
	float	new_px;
	float	new_py;
	float	check_y;
	float	check_x;

	new_px = game->player.px + move_x * MOVE_SPEED;
	new_py = game->player.py + move_y * MOVE_SPEED;
	if (move_x > 0)
		check_x = new_px + 0.1f;
	else
		check_x = new_px - 0.1f;
	if (game->map.valid_map[(int)game->player.py][(int)check_x] != '1')
		game->player.px = new_px;
	if (move_y > 0)
		check_y = new_py + 0.1f;
	else
		check_y = new_py - 0.1f;
	if (game->map.valid_map[(int)check_y][(int)game->player.px] != '1')
		game->player.py = new_py;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit(0);
	if (keycode == 65361)
		rotate_player(game, -1);
	else if (keycode == 65363)
		rotate_player(game, 1);
	else if (keycode == 119)
		move_player(game, cos(game->player.pa), sin(game->player.pa));
	else if (keycode == 115)
		move_player(game, -cos(game->player.pa), -sin(game->player.pa));
	else if (keycode == 100)
		move_player(game, -sin(game->player.pa), cos(game->player.pa));
	else if (keycode == 97)
		move_player(game, sin(game->player.pa), -cos(game->player.pa));
	return (0);
}
