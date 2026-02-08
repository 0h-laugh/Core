/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:08:05 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:08:06 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = game->img.addr + (y * game->img.line_len + x * (
					game->img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_texture_pixel(t_game *game, t_draw *draw)
{
	int				tex_x;
	int				tex_y;
	unsigned int	color;

	tex_y = (int)draw->texture_pos & (draw->texture->height - 1);
	tex_x = game->wall_hit_x * draw->texture->width;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= draw->texture->width)
		tex_x = draw->texture->width - 1;
	color = get_texture_color(draw->texture, tex_x, tex_y);
	put_pixel(game, draw->x, draw->y, color);
	draw->texture_pos += (float)draw->texture->height / draw->wall_height;
}

void	draw_column(t_game *game, t_draw *draw)
{
	draw->y = 0;
	draw->texture_pos = (draw->start - WIN_HEIGHT / 2
			+ draw->wall_height / 2)
		* ((float)draw->texture->height / draw->wall_height);
	while (draw->y < WIN_HEIGHT)
	{
		if (draw->y < draw->start)
			put_pixel(game, draw->x, draw->y, game->textures.ceeling_color);
		else if (draw->y >= draw->start && draw->y < draw->end)
			draw_texture_pixel(game, draw);
		else
			put_pixel(game, draw->x, draw->y, game->textures.floor_color);
		draw->y++;
	}
}

void	calculate_wall_distance(t_ray_data *data,
	float *perp_wall_dist, int *line_height, float *wall_x)
{
	if (data->side == 0)
		*perp_wall_dist = (data->map_x - data->game->player.px
				+ (1 - data->step_x) / 2) / data->ray_dir_x;
	else
		*perp_wall_dist = (data->map_y - data->game->player.py
				+ (1 - data->step_y) / 2) / data->ray_dir_y;
	*line_height = (int)(WIN_HEIGHT / (*perp_wall_dist + 0.0001));
	if (data->side == 0)
		*wall_x = data->game->player.py + (*perp_wall_dist) * data->ray_dir_y;
	else
		*wall_x = data->game->player.px + (*perp_wall_dist) * data->ray_dir_x;
	*wall_x -= floorf(*wall_x);
}

int	get_texture_side(t_ray_data *data)
{
	int	texture_side;

	if (data->side == 0)
	{
		if (data->ray_dir_x > 0)
			texture_side = 2;
		else
			texture_side = 3;
	}
	else
	{
		if (data->ray_dir_y > 0)
			texture_side = 1;
		else
			texture_side = 0;
	}
	return (texture_side);
}
