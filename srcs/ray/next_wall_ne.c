#include "cub3d.h"

static t_wall_values	ft_init_values(t_real pos, float rad)
{
	t_wall_values	wall_val;

	wall_val.of7.y = 0;
	wall_val.dir = (2 * M_PI) - rad;
	wall_val.distance.y = pos.y - (int)pos.y;
	wall_val.distance.x = (int)pos.x + 1 - pos.x;
	if (wall_val.distance.y == 0)
	{
		wall_val.of7.y = 1;
		wall_val.distance.y = 1;
	}
	wall_val.hypo.y = floor(
			1000000 * (wall_val.distance.y / sin(wall_val.dir))) / 1000000;
	wall_val.hypo.x = floor(
			1000000 * (wall_val.distance.x / cos(wall_val.dir))) / 1000000;
	return (wall_val);
}

t_real	ft_next_wall_ne(float rad, t_real pos, char **map)
{
	t_wall_values	w;

	w = ft_init_values(pos, rad);
	if (w.hypo.y == w.hypo.x)
	{
		w.wall.y = pos.y - (w.distance.y * tan(w.dir));
		w.wall.x = pos.x + (w.distance.x / tan(w.dir));
		if (map[(int)(pos.y - 1 - w.of7.y)][(int)pos.x + 1] != '1')
			w.wall = ft_next_wall_ne(rad, w.wall, map);
	}
	else if (w.hypo.y < w.hypo.x)
	{
		w.wall.y = pos.y - w.distance.y;
		w.wall.x = pos.x + (w.distance.y / tan(w.dir));
		if (map[(int)(pos.y - 1 - w.of7.y)][(int)pos.x] != '1')
			w.wall = ft_next_wall_ne(rad, w.wall, map);
	}
	else
	{
		w.wall.y = pos.y - (w.distance.x * tan(w.dir));
		w.wall.x = pos.x + w.distance.x;
		if (map[(int)(pos.y - w.of7.y)][(int)pos.x + 1] != '1')
			w.wall = ft_next_wall_ne(rad, w.wall, map);
	}
	return (w.wall);
}