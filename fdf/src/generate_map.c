#include "../includes/fdf.h"

void	set_height_range(t_map *map, t_point *cur)
{
	if (cur->z < map->min_height)
		map->min_height = cur->z;
	if (cur->z > map->max_height)
		map->max_height = cur->z;
}

void	set_point_colors(t_map *map)
{
	t_point	ground;
	t_point	max;
	t_point	min;
	t_point	*cur;
	int		i;

	ground = (t_point){0, 0, 0, GROUND_COLOR};
	max = (t_point){0, 0, map->max_height, HIGH_COLOR};
	min = (t_point){0, 0, map->min_height, LOW_COLOR};
	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		cur = map->point_arr + i;
		if (cur->z > 0)
			cur->color = get_height_gradient_color(*cur, ground, max);
		if (cur->z <= 0)
			cur->color = get_height_gradient_color(*cur, ground, min);
		i++;
	}
}

void	fill_map(t_data *data, t_map *map)
{
	int		i;
	int		j;
	t_point	*cur;
	t_point	point;

	point.z = 0;
	point.y = -map->space * map->y_dim / 2;
	i = 0;
	while (i < map->y_dim)
	{
		point.x = -map->space * map->x_dim / 2;
		j = 0;
		while (j < map->x_dim)
		{	
			cur = map->point_arr + (i * map->x_dim) + j;
			*cur = point;
			cur->z = ft_atoi(data->parsed_file[i * map->x_dim + j]);
			set_height_range(map, cur);
			cur->color = GROUND_COLOR;
			point.x += map->space;
			j++;
		}
		point.y += map->space;
		i++;
	}
}

t_map	*generate_map(t_data *data)
{
	t_map	*map;

	map = data->map;
	map->min_height = 0;
	map->max_height = 0;
	map->point_arr = malloc(map->x_dim * map->y_dim * sizeof(t_point));
	if (map->point_arr == NULL)
		return (NULL);
	map->space = 10;
	fill_map(data, map);
	set_point_colors(map);
	return (map);
}
