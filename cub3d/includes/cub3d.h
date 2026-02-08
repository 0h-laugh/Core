/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojastrze <ojastrze@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 16:05:51 by ojastrze          #+#    #+#             */
/*   Updated: 2026/02/08 16:05:55 by ojastrze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define FOV 1.0471975512
# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.05
# define NUM_RAYS WIN_WIDTH
# define TILE_SIZE 1

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*F;
	char	*C;
	int		floor_color;
	int		ceeling_color;
	t_img	NO;
	t_img	SO;
	t_img	WE;
	t_img	EA;
}	t_texture;

typedef struct s_map
{
	char	**valid_map;
	int		lines_tilmap;
	int		highest_x;
	int		highest_y;
	int		current_row;
}	t_map;

typedef struct s_player
{
	int		is_player;
	float	px;
	float	py;
	float	pa;
}	t_player;

typedef struct s_draw
{
	int		x;
	int		y;
	int		start;
	int		end;
	int		wall_height;
	float	texture_pos;
	t_img	*texture;
}	t_draw;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	float		wall_hit_x;
	t_img		img;
	t_texture	textures;
	t_map		map;
	t_player	player;
}	t_game;

typedef struct s_ray_data
{
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	float	side_dist_x;
	float	side_dist_y;
	int		hit;
	int		side;
	float	ray_angle;
	t_game	*game;
}	t_ray_data;

//casting_rays.c
void			run_dda(t_ray_data *data);
void			init_side_dist(t_ray_data *data);
void			finish_ray(t_ray_data *data, int x);
void			cast_single_ray(t_game *game, float ray_angle, int x);
void			cast_rays(t_game *game);

//ray_utils.c
void			put_pixel(t_game *game, int x, int y, int color);
void			draw_texture_pixel(t_game *game, t_draw *draw);
void			draw_column(t_game *game, t_draw *draw);
void			calculate_wall_distance(t_ray_data *data,
					float *perp_wall_dist, int *line_height, float *wall_x);
int				get_texture_side(t_ray_data *data);

//check_args.c
int				check_args(char *map_name);

//check_map_size.c
void			check_x_and_y(t_game *game, char *str, int i);

//colors_convert.c
int				convert(char *str);
void			color_convert(t_game *game);

//fill_map_vals_utils.c
char			*ft_strcpy(char *dst, const char *src);
int				ft_isspace(char c);
int				is_only_whitespace(const char *str, bool map_status);

//fill_map_vals_logic.c
bool			check_for_all(t_game *game);
void			find_id(char *str, t_game *game);
bool			is_map_part(t_game *game, char *str);
bool			is_not_map_format(const char *str);
void			fill_map_vals(t_game *game, char *str);

//load_textures.c
void			load_texture(void *mlx, t_img *texture, char *path);
void			load_textures(t_game *game);
unsigned int	get_texture_color(t_img *texture, int x, int y);

//main.c
void			start_game(t_game *game);
void			start_texture(t_game *game);
void			draw_vertical_line(t_game *game, int x, int height, int side);
int				main(int argc, char **argv);

//map_flood_check.c
bool			zero_flood_check(t_game *game, int j, int i);
void			zero_check(t_game *game);
void			map_check(t_game *game);
bool			x_check_dirs(t_game *game, int x, int y);

//map_saving.c
char			*ft_strcpy_2(char *dst, const char *src, int size);
char			**allocate_2d_char_array(int rows, int cols);
void			alloc_map(t_game *game, char *str);

//mapping_check.c
bool			is_player_value(char c);
bool			x_check(t_game *game, int x, int y);
bool			player_in_map(t_game *game, int pos_x, int pos_y);
void			check_boundaries_x(t_game *game);
void			check_boundaries_y(t_game *game);

//player_control.c
void			rotate_player(t_game *game, float direction);
void			move_player(t_game *game, float move_x, float move_y);
int				key_press(int keycode, t_game *game);

#endif
