/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:06:42 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:06:44 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	run_dda(t_ray_data *data)
{
	while (!data->hit)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->game->map.valid_map[data->map_y][data->map_x] == '1')
			data->hit = 1;
	}
}

void	init_side_dist(t_ray_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->game->player.px - data->map_x)
			* data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->game->player.px)
			* data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->game->player.py - data->map_y)
			* data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->game->player.py)
			* data->delta_dist_y;
	}
}

void	finish_ray(t_ray_data *data, int x)
{
	float	perp_wall_dist;
	int		line_height;
	float	wall_x;
	int		texture_side;

	calculate_wall_distance(data, &perp_wall_dist, &line_height, &wall_x);
	data->game->wall_hit_x = wall_x;
	texture_side = get_texture_side(data);
	draw_vertical_line(data->game, x, line_height, texture_side);
}

void	cast_single_ray(t_game *game, float ray_angle, int x)
{
	t_ray_data	data;

	data.game = game;
	data.ray_angle = ray_angle;
	data.ray_dir_x = cosf(data.ray_angle);
	data.ray_dir_y = sinf(data.ray_angle);
	data.map_x = (int)game->player.px;
	data.map_y = (int)game->player.py;
	data.delta_dist_x = fabsf(1 / data.ray_dir_x);
	data.delta_dist_y = fabsf(1 / data.ray_dir_y);
	data.hit = 0;
	data.side = -1;
	init_side_dist(&data);
	run_dda(&data);
	finish_ray(&data, x);
}

void	cast_rays(t_game *game)
{
	float	ray_angle;
	int		x;

	ray_angle = game->player.pa - (FOV / 2);
	x = 0;
	while (x < NUM_RAYS)
	{
		cast_single_ray(game, ray_angle, x);
		ray_angle += FOV / NUM_RAYS;
		x++;
	}
}
