#include "so_long.h"

void	ft_render_others(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			if (data->map->allmap[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->collectible, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->chr->down, j * 32, i * 32);
		}
	}
}

void	ft_update_map(t_data *data, int keycode)
{
	int	i;
	int	j;

	i = data->chr->position_i;
	j = data->chr->position_j;
	if (data->map->allmap[data->chr->position_i][data->chr->position_j] == 'E')
	{
		if (data->map->c_cnt == 0)
		{
			ft_error("You win!");
			ft_close(data);
		}
		else
			ft_error("You need to collect all collectibles");
	}
	if (keycode == 0)
		ft_left(data, i, j);
	else if (keycode == 1)
		ft_right(data, i, j);
	else if (keycode == 2)
		ft_up(data, i, j);
	else if (keycode == 13)
		ft_down(data, i, j);
}

void	ft_print_step(t_data *data)
{
	ft_printf("Step: %d\n", data->step);
}
