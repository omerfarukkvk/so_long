/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:07:34 by okavak            #+#    #+#             */
/*   Updated: 2022/09/14 20:07:36 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg)
{
	ft_printf("%s", msg);
	exit(0);
}

int	ft_close(t_data *data)
{
	int	i;

	mlx_destroy_image(data->mlx, data->chr->up);
	mlx_destroy_image(data->mlx, data->chr->down);
	mlx_destroy_image(data->mlx, data->chr->left);
	mlx_destroy_image(data->mlx, data->chr->right);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->collectible);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->floor);
	i = -1;
	while (++i < data->map->height)
	{
		free(data->map->copymap[i]);
		free(data->map->allmap[i]);
	}
	free(data->map->copymap);
	free(data->map->allmap);
	exit(0);
	return (0);
}

int	ft_key(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_close(data);
	else if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
	{
		ft_update_map(data, keycode);
		ft_put_step(data);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2 && ft_map_name_check(av[1]) == 1)
	{
		data = ft_calloc(1, sizeof(t_data));
		data->map = ft_calloc(sizeof(t_map), 1);
		data->chr = ft_calloc(1, sizeof(t_chr));
		data->chr->step_cnt = 0;
		ft_map_control(av[1], data);
		data->mlx = mlx_init();
		ft_read_map(data, av[1]);
		ft_item_control(data);
		data->win = mlx_new_window(data->mlx, data->map->width * 32,
				data->map->height * 32, "SOLONG");
		ft_render_map(data);
		mlx_hook(data->win, 2, 1L << 0, ft_key, data);
		mlx_hook(data->win, 17, 0, ft_close, data);
		mlx_loop(data->mlx);
	}
	else
		ft_error("Error!!");
}
