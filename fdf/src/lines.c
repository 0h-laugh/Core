#include "../includes/fdf.h"

int	draw_line_low(t_img *img, t_point start, t_point end)
{
	int		err;
	int		yi;
	t_point	delta;
	t_point	cur;

	delta = vec_sub(end, start);
	yi = 1;
	if (delta.y < 0)
		yi = -1;
	delta.y = fabsf(delta.y);
	err = 2 * delta.y - delta.x;
	cur = start;
	while (cur.x < end.x)
	{
		img_pix_put(img, cur);
		if (err > 0)
			cur.y += yi;
		if (err > 0)
			err = err + (2 * (delta.y - delta.x));
		else
			err = err + 2 * delta.y;
		cur.color = get_color(cur, start, end, delta);
		cur.x++;
	}
	return (0);
}

int	draw_line_high(t_img *img, t_point start, t_point end)
{
	int		err;
	int		xi;
	t_point	delta;
	t_point	cur;

	delta = vec_sub(end, start);
	xi = 1;
	if (delta.x < 0)
		xi = -1;
	delta.x = fabsf(delta.x);
	err = 2 * delta.x - delta.y;
	cur = start;
	while (cur.y < end.y)
	{
		img_pix_put(img, cur);
		if (err > 0)
			cur.x += xi;
		if (err > 0)
			err = err + (2 * (delta.x - delta.y));
		else
			err = err + 2 * delta.x;
		cur.color = get_color(cur, start, end, delta);
		cur.y++;
	}
	return (0);
}

int	draw_line(t_img *img, t_point start, t_point end)
{
	if (fabsf(end.y - start.y) < fabsf(end.x - start.x))
	{
		if (start.x > end.x)
			return (draw_line_low(img, end, start));
		return (draw_line_low(img, start, end));
	}
	if (start.y > end.y)
		return (draw_line_high(img, end, start));
	return (draw_line_high(img, start, end));
	return (1);
}
