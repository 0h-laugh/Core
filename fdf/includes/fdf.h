/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaf <olaf@student.1337.ma>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:37:58 by olaf              #+#    #+#             */
/*   Updated: 2024/09/29 15:39:42 by olaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"

# define WIN_W	1280
# define WIN_H	720

# define BBLUE	0x0099FFFF
# define GREY	0x00888888
# define WHITE	0x00FFFFFF
# define BLACK	0x00000000

# define GROUND_COLOR	GREY
# define LOW_COLOR	BBLUE
# define HIGH_COLOR	WHITE

# define ISO	0.6154

typedef struct s_point
{
	float_t		x;
	float_t		y;
	float_t		z;
	int			color;
}			t_point;

typedef struct s_map
{
	t_point	*point_arr;
	int		x_dim;
	int		y_dim;
	int		space;
	int		min_height;
	int		max_height;
}			t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
	char	**parsed_file;
}			t_data;

//File handling
int     parse_file(t_data *data, char *filename);
char    *get_file(int fd, t_data *data);
int     count_cols(char *s);
int     lines_consistent(int cols, t_data *data);
void    append_line_to_file(char **line, char **file);
void    replace_newline(unsigned int i, char *s);
void    free_str_arr(char **str_arr);

//Map handling
t_map   *generate_map(t_data *data);
void    fill_map(t_data *data, t_map *map);
void    set_point_colors(t_map *map);
void    set_height_range(t_map *map, t_point *cur);

//Color handling
int     get_height_gradient_color(t_point cur, t_point start, t_point end);
int     get_color(t_point cur, t_point start, t_point end, t_point delta);
int     calc_color_channel(int start, int end, float_t percentage);
float_t get_percentage(int start, int end, int cur);

//View
void    generate_iso_view(t_map *map);
void    translate(t_map *map, t_point offset);
t_point vec_add(t_point point1, t_point point2);
t_point	vec_sub(t_point point1, t_point point2);

//Mlx
int     start_mlx(t_data *data);
int     loop_hook(t_data *data);
int     close_app(t_data *data);
int     key_hook1(int keysym, t_data *data);
void    render_background(t_img *img, int color);
void    draw_map(t_img *img, t_map *map, t_point offset);
void    img_pix_put(t_img *img, t_point point);
t_img	*create_image_buffer(t_data *data);
void    render_instructions(t_data *data, int color);
void	render_to_window(t_data *data);
int     draw_line_low(t_img *img, t_point start, t_point end);
int     draw_line_high(t_img *img, t_point start, t_point end);
int     draw_line(t_img *img, t_point start, t_point end);

#endif
