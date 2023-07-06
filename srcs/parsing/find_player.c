
#include "cub3d.h"

static void	ft_set_player(char c, t_player *pos, unsigned int x, unsigned int y)
{
	t_real	*real;
	t_rgb	*color;

	color = malloc(sizeof(t_rgb));
	real = malloc(sizeof(t_real));
	if (!real || !color)
		ft_print_error(MSG_MALLOC_ERR);
	pos->pos_x = x;
	pos->pos_y = y;
	real->x = x + 0.5;
	real->y = y + 0.5;
	color->r = 255;
	color->g = 0;
	color->b = 0;
	pos->color = color;
	pos->real = real;
	pos->dir_x = 0;
	pos->dir_y = 0;
	pos->plane_x = 0;
	pos->plane_y = (float) FOV / 100;
	if (c == 'N')
	{
		pos->facing = M_PI + M_PI_2;
		pos->dir_y = 1;
	}
	else if (c == 'S')
	{
		pos->facing = M_PI_2;
		pos->dir_y = -1;
	}
	else if (c == 'W')
	{
		pos->facing = M_PI;
		pos->dir_x = -1;
	}
	else if (c == 'E')
	{
		pos->facing = 0.0f;
		pos->dir_x = 1;
	}
}

static bool	ft_find_player_ext(char **map, t_player *pos, unsigned int x,
	unsigned int y)
{
	bool			found;

	found = false;
	while (map[y] != NULL)
	{
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'S' || map[y][x] == 'N' || map[y][x] == 'W'
				|| map[y][x] == 'E')
			{
				if (found == true)
					ft_print_error(MSG_TWO_PLAYER_ERR);
				ft_set_player(map[y][x], pos, x, y);
				found = true;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (found);
}

t_player	*ft_find_player(char **map)
{
	t_player		*pos;
	bool			found;

	pos = malloc(sizeof(t_player));
	if (!pos)
		ft_print_error(MSG_MALLOC_ERR);
	found = ft_find_player_ext(map, pos, 0, 0);
	if (found == false)
		ft_print_error(MSG_NO_PLAYER_ERR);
	return (pos);
}
