#include "so_long.h"

int main(int ac, char **av)
{
    t_data  *data;

    if (ac == 2 && !ft_strncmp(&av[1][ft_strlen(av[1] - 4)], ".ber", 5))
    {
        data = ft_calloc(1, sizeof(t_data));
        data->map = ft_calloc(sizeof(t_map), 1);
        data->chr = ft_calloc(1, sizeof(t_chr));
        data->mlx = mlx_init();
        
    }
    else
        ft_printf("Error!!");
}