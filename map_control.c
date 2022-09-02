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
	//ft_printf("%d",(int)ft_strlen(line));
	data->map->width = (int)ft_strlen(line)-1;
	while (line !=NULL)
	{
		if (ft_map_size_check(data, line))
			ft_error("wrong mapsize");
		data->map->height++;
		free(line);
		line = get_next_line(fd);
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
		data->map->allmap[i] = ft_calloc(data->map->width, 1);
		ft_strlcpy(data->map->allmap[i], line, data->map->width + 1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map->allmap[i]=NULL;
	ft_printf("%s",data->map->allmap[0][0]);
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
	int	j;

	i = -1;
 	while (++i < data->map->height)
	{
		ft_printf("%s", allmap[0][0]);
		if (allmap[i][0] == '1' && ft_strlen(allmap[i - 1]) == '1')
		{
			j = 0; 
			while (allmap[i][j])
			{
				if (allmap[0][j] != '1' || allmap[data->map->height][j])
					ft_error("horizantal wall wrong");
				else
					j++;
			}
		}
		else
			ft_error("duvar hatası");
	} 
}
