/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:14:57 by okavak            #+#    #+#             */
/*   Updated: 2022/09/14 21:15:01 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_left(t_data *data, int i, int j)
{
	if (data->map->allmap[i][j - 1] != '1')
	{
		if (data->map->allmap[i][j - 1] != 'E')
		{
			if (data->map->allmap[i][j - 1] == 'C')
				data->map->c_cnt--;
			data->map->allmap[i][j] = '0';
			data->map->allmap[i][j - 1] = 'P';
			data->chr->position_j--;
			data->chr->step_cnt++;
			mlx_clear_window(data->mlx, data->win);
			ft_render_map(data);
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
			if (data->map->allmap[i][j + 1] == 'C')
				data->map->c_cnt--;
			data->map->allmap[i][j] = '0';
			data->map->allmap[i][j + 1] = 'P';
			data->chr->position_j++;
			data->chr->step_cnt++;
			mlx_clear_window(data->mlx, data->win);
			ft_render_map(data);
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
			if (data->map->allmap[i - 1][j] == 'C')
				data->map->c_cnt--;
			data->map->allmap[i][j] = '0';
			data->map->allmap[i - 1][j] = 'P';
			data->chr->position_i--;
			data->chr->step_cnt++;
			mlx_clear_window(data->mlx, data->win);
			ft_render_map(data);
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
			if (data->map->allmap[i + 1][j] == 'C')
				data->map->c_cnt--;
			data->map->allmap[i][j] = '0';
			data->map->allmap[i + 1][j] = 'P';
			data->chr->position_i++;
			data->chr->step_cnt++;
			mlx_clear_window(data->mlx, data->win);
			ft_render_map(data);
		}
		else if (data->map->allmap[i + 1][j] == 'E' && data->map->c_cnt == 0)
		{
			ft_printf("You win!");
			ft_close(data);
		}
	}
}
