#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct chr
{
}   t_chr;


typedef struct s_map
{
    int		height;
	int		width;
	char	**allmap;
}   t_map;


typedef struct s_data
{
    t_chr	*chr;
    t_map	*map;
    void	*mlx;
    void	*win;
}   t_data;

void	ft_map_control(char *path, t_data *data);
int		ft_map_name_check(char *path);
int		ft_map_size_check(t_data *data,char *line);

#endif