#include "../includes/fdf.h"

void	generate_iso_view(t_map *map)
{
    int		i;
    t_point	*cur;
    float_t	previous_x;
    float_t	previous_y;

    i = 0;
    while (i < map->x_dim * map->y_dim)
    {
        cur = map->point_arr + i;
        previous_x = cur->x;
        previous_y = cur->y;
        cur->x = (previous_x - previous_y) * cos(ISO);
        cur->y = -cur->z + (previous_x + previous_y) * sin(ISO);
        i++;
    }
}

t_point	vec_add(t_point point1, t_point point2)
{
	t_point	sum;

	sum.x = point1.x + point2.x;
	sum.y = point1.y + point2.y;
	sum.z = point1.z + point2.z;
	sum.color = point1.color;
	return (sum);
}

t_point	vec_sub(t_point point1, t_point point2)
{
	t_point	diff;

	diff.x = point1.x - point2.x;
	diff.y = point1.y - point2.y;
	diff.z = point1.z - point2.z;
	diff.color = point1.color;
	return (diff);
}

void	translate(t_map *map, t_point offset)
{
	int		i;
	t_point	*cur;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		cur = map->point_arr + i;
		*cur = vec_add(*cur, offset);
		i++;
	}
}
