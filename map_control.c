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
	i=0;
	data->map->allmap = malloc(sizeof(char *) * (data->map->height + 1));
	while (line && i<=data->map->height)
	{
		data->map->allmap[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map->allmap[i] = 0;
	i = 0;	
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
	ft_playable_control(data);
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
			while (allmap[i][j] == '1')
				j++;
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
			{
				data->map->p_cnt++;
				data->chr->position_i = i;
				data->chr->position_j = j;
			}
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
	if (data->map->e_cnt != 1)
		ft_error("wrong exit");
}

void	ft_playable_control(t_data *data)
{
	int	i;

	data->map->copy_c = data->map->c_cnt;
	data->map->copy_e = data->map->e_cnt;
	data->map->copymap = ft_calloc(data->map->height, sizeof(char *));
	i = -1;
	while (++i < data->map->height)
		data->map->copymap[i] = ft_strdup(data->map->allmap[i]);
	ft_copymap_control(data, data->map->copymap, data->chr->position_i,
		data->chr->position_j);
	if (data->map->copy_c != 0 || data->map->copy_e != 0)
		ft_error("Map is not playable");
}

void	ft_copymap_control(t_data *data, char **copymap, int i, int j)
{
	if (copymap[i][j] != '1' && copymap[i][j] != 'E')
	{
		if (copymap[i][j] == 'C')
			data->map->copy_c--;
		copymap[i][j] = 'x';
		if (copymap[i][j + 1] != '1' \
			&& copymap[i][j + 1] != 'x')
			ft_copymap_control(data, copymap, i, j + 1);
		if (copymap[i][j - 1] != '1' \
			&& copymap[i][j - 1] != 'x')
			ft_copymap_control(data, copymap, i, j - 1);
		if (copymap[i + 1][j] != '1' \
			&& copymap[i + 1][j] != 'x')
			ft_copymap_control(data, copymap, i + 1, j);
		if (copymap[i - 1][j] != '1' \
			&& copymap[i - 1][j] != 'x')
			ft_copymap_control(data, copymap, i - 1, j);
	}
	else
		data->map->copy_e = 0;
}

void	ft_render_map(t_data *data, int keycode)
{
	int	i;
	int	j;

	ft_assets(data);
	mlx_clear_window(data->mlx, data->win);
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->floor, j * 32, i * 32);
		}
	}
	ft_render_others(data);
	ft_update_map(data, keycode);
}

void	ft_assets(t_data *data)
{
	data->chr->size = 32;
	data->chr->up = mlx_xpm_file_to_image(data->mlx, "./assets/W.xpm",
			&data->chr->size, &data->chr->size);
	data->chr->down = mlx_xpm_file_to_image(data->mlx, "./assets/S.xpm",
			&data->chr->size, &data->chr->size);
	data->chr->left = mlx_xpm_file_to_image(data->mlx, "./assets/A.xpm",
			&data->chr->size, &data->chr->size);
	data->chr->right = mlx_xpm_file_to_image(data->mlx, "./assets/D.xpm",
			&data->chr->size, &data->chr->size);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./assets/E.xpm",
			&data->chr->size, &data->chr->size);
	data->collectible = mlx_xpm_file_to_image(data->mlx, "./assets/C.xpm",
			&data->chr->size, &data->chr->size);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm",
			&data->chr->size, &data->chr->size);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./assets/bg.xpm",
			&data->chr->size, &data->chr->size);
}

void	ft_render_others(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			if (data->map->allmap[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->wall, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->collectible, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->exit, j * 32, i * 32);
			else if (data->map->allmap[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->chr->down, j * 32, i * 32);
		}
	}
}

void	ft_update_map(t_data *dat, int keycode)
{
	
}
