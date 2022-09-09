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
	
	data->map->height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("map not opening");
	line = get_next_line(fd);
	if (line == 0)
		ft_error("Map is empty");
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
	while (line)
	{
		data->map->allmap[i] = ft_calloc(data->map->width, sizeof(char));
		ft_strlcpy(data->map->allmap[i], line, data->map->width + 1);
		i++;
		free(line);
		line = get_next_line(fd);
	
	}
	free(line);
	close(fd);
	
}

void	ft_item_control(t_data *data)
{
	char **allmap;
	
	data->map->e_cnt = 0;
	data->map->c_cnt = 0;
	data->map->p_cnt = 0;
	allmap = data->map->allmap;
	ft_wall_control(data, allmap);
}

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
			while (j < data->map->width)
			{
				if (allmap[0][j] != '1'  || allmap[data->map->width-1][j] != '1')
					ft_error("Wrong map wall");
				else if (allmap[0][j] == '1' || allmap[data->map->width-1][j] == '1')
					j++;
				else if (allmap[i][j] == '1')
					j++;
				else if (allmap[i][j] != '1')
					j += ft_component_control(allmap[i][j], data, j);
			}
		}
		else
			ft_error("zaaa");	
	}
}

int	ft_component_control(char c, t_data *data, int j)
{

	if (c == 'E')
		data->map->e_cnt++;
	else if (c == 'C')
		data->map->c_cnt++;
	else if (c == 'P')
		data->map->p_cnt++;
	else if (c == '0')
		return (j + 1);
	else
		return(ft_error("Wrong map"));
	return (j + 1);
}
