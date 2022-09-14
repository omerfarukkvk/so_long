#include "so_long.h"

void	ft_left(t_data *data, int i, int j)
{
	if (data->map->allmap[i][j - 1] != '1')
	{
		if (data->map->allmap[i][j - 1] != 'E')
		{
			data->map->allmap[i][j] = mlx_destroy_image(data->mlx,
					data->chr->right);
			data->chr->step_cnt++;
			ft_render_map(data);
			data->map->allmap[i][j + 1] = mlx_put_image_to_window(data->mlx,
					data->win, data->chr->left, (j - 1) * 32, i * 32);
			data->map->allmap[i][j]='0';
			data->chr->position_j--;
		}
		else if (data->map->allmap[i][j - 1] == 'E' && data->map->c_cnt == 0)
		{
			ft_printf("You win!");
			ft_close(data);
		}
	}
}

void	ft_right(t_data *data, int i, int j)
{	
	if (data->map->allmap[i][j + 1] != '1')
	{
		if (data->map->allmap[i][j + 1] != 'E')
		{
			data->map->allmap[i][j] = mlx_destroy_image(data->mlx,
					data->chr->right);
			data->chr->step_cnt++;
			ft_render_map(data);
			data->map->allmap[i][j + 1] = mlx_put_image_to_window(data->mlx,
					data->win, data->chr->right, (j + 1) * 32, i * 32);
			data->map->allmap[i][j]='0';
			data->chr->position_j++;
		}
		else if (data->map->allmap[i][j + 1] == 'E' && data->map->c_cnt == 0)
		{
			ft_printf("You win!");
			ft_close(data);
		}
	}
}

void	ft_up(t_data *data, int i, int j)
{
	if (data->map->allmap[i - 1][j] != '1')
	{
		if (data->map->allmap[i - 1][j] != 'E')
		{
			data->map->allmap[i][j] = mlx_destroy_image(data->mlx,
					data->chr->right);
			data->chr->step_cnt++;
			ft_render_map(data);
			data->map->allmap[i - 1][j] = mlx_put_image_to_window(data->mlx,
					data->win, data->chr->up, j * 32, (i - 1) * 32);
			data->map->allmap[i][j]='0';
			data->chr->position_i--;
		}
		else if (data->map->allmap[i - 1][j] == 'E' && data->map->c_cnt == 0)
		{
			ft_printf("You win!");
			ft_close(data);
		}
	}
}

void	ft_down(t_data *data, int i, int j)
{
	if (data->map->allmap[i + 1][j] != '1')
	{
		if (data->map->allmap[i + 1][j] != 'E')
		{
			data->map->allmap[i][j] = mlx_destroy_image(data->mlx,
					data->chr->right);
			data->chr->step_cnt++;
			ft_render_map(data);
			data->map->allmap[i + 1][j] = mlx_put_image_to_window(data->mlx,
					data->win, data->chr->down, j * 32, (i + 1) * 32);
			data->map->allmap[i][j]='0';
			data->chr->position_i++;
		}
		else if (data->map->allmap[i + 1][j] == 'E' && data->map->c_cnt == 0)
		{
			ft_printf("You win!");
			ft_close(data);
		}
	}
}