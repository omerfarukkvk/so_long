/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:08:07 by okavak            #+#    #+#             */
/*   Updated: 2022/09/14 20:08:09 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_assets(t_data *data)
{
	if (data->xpm_error == 1)
		ft_error("XPM file error");
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
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->collectible, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->exit, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->chr->down, j * 32, i * 32);
		}
	}
}

void	ft_update_map(t_data *data, int keycode)
{
	int	i;
	int	j;

	i = data->chr->position_i;
	j = data->chr->position_j;
	if (data->map->allmap[data->chr->position_i][data->chr->position_j] == 'E' \
			&& data->map->c_cnt == 0)
	{
		ft_error("You win!");
		ft_close(data);
	}
	if (keycode == 0)
		ft_left(data, i, j);
	else if (keycode == 1)
		ft_down(data, i, j);
	else if (keycode == 2)
		ft_right(data, i, j);
	else if (keycode == 13)
		ft_up(data, i, j);
}

void	ft_put_step(t_data *data)
{
	char	*step;
	char	*tmp;

	step = ft_itoa(data->chr->step_cnt);
	tmp = ft_strjoin("Step: ", step);
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000, tmp);
	free(step);
	free(tmp);
}

void	ft_xpm_file_control(t_data *data)
{
	int	fd;

	fd = open("./assets/S.xpm", O_RDONLY);
	if (fd == -1)
		data->xpm_error = 1;
	close(fd);
	fd = open("./assets/E.xpm", O_RDONLY);
	if (fd == -1)
		data->xpm_error = 1;
	close(fd);
	fd = open("./assets/C.xpm", O_RDONLY);
	if (fd == -1)
		data->xpm_error = 1;
	close(fd);
	fd = open("./assets/wall.xpm", O_RDONLY);
	if (fd == -1)
		data->xpm_error = 1;
	close(fd);
	fd = open("./assets/bg.xpm", O_RDONLY);
	if (fd == -1)
		data->xpm_error = 1;
	close(fd);
}
