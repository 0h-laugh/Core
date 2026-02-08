/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:07:28 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:07:29 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start_game(t_game *game)
{
	game->textures.no_path = NULL;
	game->textures.so_path = NULL;
	game->textures.we_path = NULL;
	game->textures.ea_path = NULL;
	game->textures.F = NULL;
	game->textures.C = NULL;
	game->map.highest_x = 0;
	game->map.highest_y = 0;
	game->map.lines_tilmap = -1;
	game->player.is_player = 0;
}

void	start_texture(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game->img.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	load_textures(game);
	game->player.pa = 0;
}

void	draw_vertical_line(t_game *game, int x, int height, int side)
{
	t_draw	draw;

	draw.x = x;
	draw.wall_height = height;
	draw.start = (WIN_HEIGHT / 2) - (height / 2);
	draw.end = (WIN_HEIGHT / 2) + (height / 2);
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= WIN_HEIGHT)
		draw.end = WIN_HEIGHT - 1;
	if (side == 0)
		draw.texture = &game->textures.NO;
	else if (side == 1)
		draw.texture = &game->textures.SO;
	else if (side == 2)
		draw.texture = &game->textures.EA;
	else
		draw.texture = &game->textures.WE;
	draw_column(game, &draw);
}

int	update(t_game *game)
{
	cast_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error: Valid input: ./cub3d map_name.cub");
		return (0);
	}
	check_args(argv[1]);
	start_game(&game);
	fill_map_vals(&game, argv[1]);
	printf("map val:%s", game.textures.no_path);
	start_texture(&game);
	check_x_and_y(&game, argv[1], 0);
	alloc_map(&game, argv[1]);
	color_convert(&game);
	map_check(&game);
	mlx_loop_hook(game.mlx, update, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx);
	return (0);
}
