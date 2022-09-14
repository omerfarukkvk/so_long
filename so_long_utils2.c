#include "so_long.h"

void	ft_component_control(t_data *data, char **allmap)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (allmap[i][++j])
		{
			if (allmap[i][j] == 'P')
			{
				data->map->p_cnt++;
				data->chr->position_i = i;
				data->chr->position_j = j;
			}
			else if (allmap[i][j] == 'C')
				data->map->c_cnt++;
			else if (allmap[i][j] == 'E')
				data->map->e_cnt++;
		}
	}
	if (data->map->p_cnt != 1)
		ft_error("wrong player");
	if (data->map->c_cnt < 1)
		ft_error("wrong collectible");
	if (data->map->e_cnt != 1)
		ft_error("wrong exit");
}

void	ft_playable_control(t_data *data)
{
	int		i;

	data->map->copy_c = data->map->c_cnt;
	data->map->copy_e = data->map->e_cnt;
	data->map->copymap = ft_calloc(data->map->height, sizeof(char *));
	i = -1;
	while (++i < data->map->height)
		data->map->copymap[i] = ft_strdup(data->map->allmap[i]);
	ft_copymap_control(data, data->map->copymap, data->chr->position_i,
		data->chr->position_j);
	if (data->map->copy_c != 0 || data->map->copy_e != 0)
		ft_error("Map is not playable");
}

void	ft_copymap_control(t_data *data, char **copymap, int i, int j)
{
	if (copymap[i][j] != '1' && copymap[i][j] != 'E')
	{
		if (copymap[i][j] == 'C')
			data->map->copy_c--;
		copymap[i][j] = 'x';
		if (copymap[i][j + 1] != '1' \
			&& copymap[i][j + 1] != 'x')
			ft_copymap_control(data, copymap, i, j + 1);
		if (copymap[i][j - 1] != '1' \
			&& copymap[i][j - 1] != 'x')
			ft_copymap_control(data, copymap, i, j - 1);
		if (copymap[i + 1][j] != '1' \
			&& copymap[i + 1][j] != 'x')
			ft_copymap_control(data, copymap, i + 1, j);
		if (copymap[i - 1][j] != '1' \
			&& copymap[i - 1][j] != 'x')
			ft_copymap_control(data, copymap, i - 1, j);
	}
	else
		data->map->copy_e = 0;
}

void	ft_render_map(t_data *data)
{
	int	i;
	int	j;

	ft_assets(data);
	mlx_clear_window(data->mlx, data->win);
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
			mlx_put_image_to_window(data->mlx, data->win, data->floor, j * 32, i * 32);
	}
	ft_render_others(data);
}

void	ft_assets(t_data *data)
{
	data->chr->size = 32;
	data->chr->up = mlx_xpm_file_to_image(data->mlx, "./assets/W.xpm",
			&data->chr->size, &data->chr->size);
	data->chr->down = mlx_xpm_file_to_image(data->mlx, "./assets/S.xpm",
			&data->chr->size, &data->chr->size);
	data->chr->left = mlx_xpm_file_to_image(data->mlx, "./assets/A.xpm",
			&data->chr->size, &data->chr->size);
	data->chr->right = mlx_xpm_file_to_image(data->mlx, "./assets/D.xpm",
			&data->chr->size, &data->chr->size);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./assets/E.xpm",
			&data->chr->size, &data->chr->size);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "./assets/C.xpm",
			&data->chr->size, &data->chr->size);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm",
			&data->chr->size, &data->chr->size);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/bg.xpm",
			&data->chr->size, &data->chr->size);
}
