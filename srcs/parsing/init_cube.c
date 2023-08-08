
#include "cub3d.h"

/**
 * Initialize the struct t_cube.
 * @param ac, av
 * @return cube
 */
t_cube	*ft_init_cube(int ac, char **av)
{
	int		fd;
	t_cube	*cube;

	fd = ft_check_arguments(ac, av);
	cube = malloc(sizeof(t_cube));
	if (!cube)
		ft_print_error(MSG_MALLOC_ERR);
	*cube = (t_cube){};
	cube->on_mouse = false;
	cube->scene = 1;
	ft_init_mlx(cube);
	ft_set_textures(cube, fd);
	ft_set_map(cube, fd);
	ft_is_map_valid(cube);
	ft_find_max_value(cube);
	cube->player = ft_find_player(cube->map);
	close(fd);
	return (cube);
}
