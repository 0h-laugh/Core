#include "../includes/fdf.h"

int	key_hook1(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_app(data);
	return (0);
}

int	close_app(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->map->point_arr);
	free(data->map);
	free(data->mlx_ptr);
	free_str_arr(data->parsed_file);
	exit(0);
	return (0);
}

int	loop_hook(t_data *data)
{
	t_map	*map;
	t_point	offset;

	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLACK);
	map = data->map;
	offset.x = WIN_W / 2;
	offset.y = WIN_H / 2;
	offset.z = 0;
	draw_map(&data->img, map, offset);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

int	start_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		write(2, "Failed to set up connection with X server\n", 42);
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "FdF");
	if (data->win_ptr == NULL)
		write(2, "Failed to open new window\n", 26);
	if (data->win_ptr == NULL)
		return (1);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, close_app, data);
	mlx_hook(data->win_ptr, KeyPress, 1, key_hook1, data);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	return (0);
}
