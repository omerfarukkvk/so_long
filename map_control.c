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
	ft_component_control(data, allmap);
	ft_playable_control(data, allmap);
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
			while (allmap[i][j])
			{
				if (i == 0 || i == data->map->height - 1)
				{
					if (allmap[i][j] != '1')
					{
						ft_error("Map wall wrong. Please check it.");
						break;
					}
				}
				j++;
			}
		}
		else
			ft_error("Map wall wrong. Please check it.");
	}
}

void	ft_component_control(t_data *data, char **allmap)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (allmap[i][++j])
		{
			if (allmap[i][j] == 'P')
				data->map->p_cnt++;
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
	if (data->map->e_cnt < 1)
		ft_error("wrong exit");
}

void	ft_playable_control(t_data *data, char **allmap)
{
	int	i;
	int	j;

	data->map->copymap = ft_calloc(data->map->height, sizeof(char *));
	i = 0;
	j = 0;
	while (allmap[i])
	{
		data->map->copymap[i] = ft_calloc(data->map->width, sizeof(char));
		ft_strlcpy(data->map->copymap[i], allmap[i], data->map->width + 1);
		i++;
	}
	// data->map->copymap[i] = '\0';
	while (data->map->copymap[j])
	{
		ft_printf("%s", data->map->copymap[j]);
		j++;
	}
}
