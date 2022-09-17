/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:07:59 by okavak            #+#    #+#             */
/*   Updated: 2022/09/14 20:08:01 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wall_control(t_data *data, char **allmap)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		if (allmap[i][0] == '1' && allmap[i][data->map->width - 1] == '1')
		{
			j = 0;
			while (allmap[i][j] == '1')
				j++;
		}
		else
			ft_error("Map wall wrong. Please check it.");
	}
}

void	ft_component_control(t_data *data, char **allmap, int i)
{
	int	j;

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

	ft_xpm_file_control(data);
	ft_assets(data);
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
			mlx_put_image_to_window(data->mlx, data->win,
				data->floor, j * 32, i * 32);
	}
	ft_render_others(data);
}
