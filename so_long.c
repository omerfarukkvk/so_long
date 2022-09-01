#include "so_long.h"

int main(int ac, char **av)
{
    t_data  *data;

    if (ac == 2 && ft_map_name_check(av[1]) == 1)
    {
        data = ft_calloc(1, sizeof(t_data));
        data->map = ft_calloc(sizeof(t_map), 1);
        data->chr = ft_calloc(1, sizeof(t_chr));
		ft_map_control(av[1], data);
        data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, data->map->width * 64,
			data->map->height * 64, "SOLONG");
		
        mlx_loop(data->mlx);
    }
    else
        ft_printf("Error!!");
}