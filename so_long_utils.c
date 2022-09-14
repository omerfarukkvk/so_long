/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:07:50 by okavak            #+#    #+#             */
/*   Updated: 2022/09/14 20:07:51 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	data->map->width = (int)ft_strlen(line)-2;
	while (line)
	{
		if (ft_line_size_check(line, data) == 1)
			ft_error("wrong mapsize");
		free(line);
		line = get_next_line(fd);
		data->map->height++;
	}
	free(line);
	close(fd);
}

int	ft_line_size_check(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (i != data->map->width - 1)
		return (0);
	return (1);
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
	i = 0;
	data->map->allmap = malloc(sizeof(char *) * (data->map->height + 1));
	while (line && (i <= data->map->height))
	{
		data->map->allmap[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map->allmap[i] = 0;
	free(line);
	close(fd);
}

void	ft_item_control(t_data *data)
{
	char	**allmap;
	int		i;

	i = -1;
	data->map->e_cnt = 0;
	data->map->c_cnt = 0;
	data->map->p_cnt = 0;
	allmap = data->map->allmap;
	ft_wall_control(data, allmap);
	ft_component_control(data, allmap, i);
	ft_playable_control(data);
}
