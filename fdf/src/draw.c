#include "../includes/fdf.h"

void	img_pix_put(t_img *img, t_point point)
{
	char	*pixel;
	int		x;
	int		y;

	x = round(point.x);
	y = round(point.y);
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)pixel = point.color;
}

void	draw_map(t_img *img, t_map *map, t_point offset)
{
	int		i;
	t_point	point;
	t_point	neighbour_right;
	t_point	neighbour_down;
	t_point	*cur;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		cur = map->point_arr + i;
		point = vec_add(*cur, offset);
		if (i % map->x_dim != map->x_dim - 1)
		{
			neighbour_right = vec_add(*(cur + 1), offset);
			draw_line(img, point, neighbour_right);
		}
		if (i < map->x_dim * map->y_dim - map->x_dim)
		{
			neighbour_down = vec_add(*(cur + map->x_dim), offset);
			draw_line(img, point, neighbour_down);
		}
		i++;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			img_pix_put(img, (t_point){j, i, 0, color});
			j++;
		}
		i++;
	}
}

t_img	*create_image_buffer(t_data *data)
{
    t_img	*img;

    img = malloc(sizeof(t_img));
    if (!img)
        return (NULL);
    img->mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
    img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
    return (img);
}

void	render_to_window(t_data *data)
{
    t_img	*img;

    img = create_image_buffer(data);
    if (!img)
    {
        write(2, "Error: Could not create image buffer\n", 35);
        return ;
    }
    draw_map(img, data->map, (t_point){0, 0, 0, 0});
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img->mlx_img, 0, 0);
    mlx_destroy_image(data->mlx_ptr, img->mlx_img);
    free(img);
}
