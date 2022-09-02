#include "so_long.h"

int	ft_map_name_check(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (path[i - 1] == 'r' && path[i - 2] == 'e'
		&& path[i - 3] == 'b' && path[i - 4] == '.')
		return (1);
	return (0);
}

void	ft_map_control(char *path, t_data *data)
{
	char	*line;
	int		fd;
	int		a;
	
	a = 0;
	data->map->height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("map not opening");
	line = get_next_line(fd);
	if (line == 0)
		ft_error("Map is empty");
	//ft_printf("%d",(int)ft_strlen(line));
	data->map->width = (int)ft_strlen(line)-1;
	while (line)
	{
		if (ft_map_size_check(data, line))
			ft_error("wrong mapsize");
		free(line);
		line = get_next_line(fd);
		data->map->height++;
	} 
	free(line);
	close(fd);
}

int	ft_map_size_check(t_data *data,char *line)
{
	return (((int)ft_strlen(line) - 1 != data->map->width
			&& line[ft_strlen(line) - 1] == '\n')
		|| (line[ft_strlen(line) - 1] != '\n'
			&& (int)ft_strlen(line) != data->map->width));
}

void	ft_read_map(t_data *data, char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("files not openning");
	line = get_next_line(fd);
	data->map->allmap = ft_calloc(data->map->height, sizeof(char *));
	i = 0;
	//ft_printf("%d",data->map->width);
	while (line)
	{
		data->map->allmap[i] = ft_calloc(data->map->width, sizeof(char));
		ft_strlcpy(data->map->allmap[i], line, data->map->width + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	
	}
	// data->map->allmap[i]=NULL;
	free(line);
	close(fd);
	
}

void	ft_item_control(t_data *data)
{
	char **allmap;

	allmap = data->map->allmap;
	ft_wall_control(data, allmap);
	
}

void	ft_wall_control(t_data *data, char **allmap)
{
	int	i;
	// int	j;
	int		a;
	int		height;

	height = data->map->height;
	a = data->map->width - 1;
	i = 0;
	(void)allmap;

 	while (a >= 0)
	 {
		 if (allmap[0][a] == '1' && allmap[data->map->height - 1] [a] == '1')
		 {
			while (height-- > 0)
			{
				
				if (allmap[height][0] == '1' && allmap[height][a] == '1')
				{ 	
					ft_printf("%d", height);
					ft_printf("doğru\n");
				}
				else
					ft_error("Mapp WALL Error.");
			}
			
		 }
		 else
		 	ft_printf("false");
		 
		 a--;
	 }
	 
}
