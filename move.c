#include "so_long.h"

void	ft_left(t_data *data, int i, int j)
{
	if (data->map->allmap[i][j] != 1)
	{
		data->map->allmap[i][j] = mlx_destroy_image(data->mlx, data->chr->left);
		data->map->allmap[i][j - 1] = mlx_put_image_to_window(data->mlx,
				data->win, data->chr->left, (j - 1) * 32, i * 32);
		data->chr->step_cnt++;
	}
}

void	ft_right(t_data *data, int i, int j)
{
	if (data->map->allmap[i][j] != 1)
	{
		data->map->allmap[i][j] = mlx_destroy_image(data->mlx,
				data->chr->right);
		data->map->allmap[i][j + 1] = mlx_put_image_to_window(data->mlx,
				data->win, data->chr->right, (j + 1) * 32, i * 32);
		data->chr->step_cnt++;
	}
}

void	ft_up(t_data *data, int i, int j)
{
	if (data->map->allmap[i][j] != 1)
	{
		data->map->allmap[i][j] = mlx_destroy_image(data->mlx, data->chr->up);
		data->map->allmap[i - 1][j] = mlx_put_image_to_window(data->mlx,
				data->win, data->chr->up, j * 32, (i - 1) * 32);
		data->chr->step_cnt++;
	}
}

void	ft_down(t_data *data, int i, int j)
{
	if (data->map->allmap[i][j] != 1)
	{
		data->map->allmap[i][j] = mlx_destroy_image(data->mlx, data->chr->down);
		data->map->allmap[i + 1][j] = mlx_put_image_to_window(data->mlx,
				data->win, data->chr->down, j * 32, (i + 1) * 32);
		data->chr->step_cnt++;
	}
}
