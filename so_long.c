#include "so_long.h"

void	ft_error(char *msg)
{
	ft_printf("%s",msg);
	exit(0);
}

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
		ft_read_map(data, av[1]);
		ft_item_control(data);
		data->win = mlx_new_window(data->mlx, data->map->width * 32,
			data->map->height * 32, "SOLONG");
		ft_render_map(data);
        mlx_loop(data->mlx);
    }
    else
        ft_error("Error!!");
}