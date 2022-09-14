/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okavak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 21:15:54 by okavak            #+#    #+#             */
/*   Updated: 2022/09/14 21:15:56 by okavak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		position_i;
	int		position_j;
	int		size;
	int		step_cnt;
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}	t_chr;

typedef struct s_map
{
	int		height;
	int		width;
	int		c_cnt;
	int		e_cnt;
	int		p_cnt;
	int		copy_c;
	int		copy_e;
	char	**allmap;
	char	**copymap;
}	t_map;

typedef struct s_data
{
	t_chr	*chr;
	t_map	*map;
	void	*mlx;
	void	*win;
	void	*exit;
	void	*collectible;
	void	*wall;
	void	*floor;
}	t_data;

void	ft_map_control(char *path, t_data *data);
int		ft_map_name_check(char *path);
void	ft_read_map(t_data *data, char *path);
void	ft_item_control(t_data *data);
void	ft_wall_control(t_data *data, char **allmap);
void	ft_error(char *msg);
void	ft_component_control(t_data *data, char **allmap, int i);
void	ft_playable_control(t_data *data);
void	ft_copymap_control(t_data *data, char **copymap, int i, int y);
void	ft_render_map(t_data *data);
void	ft_assets(t_data *data);
void	ft_render_others(t_data *data);
int		ft_close(t_data *data);
int		ft_key(int keycode, t_data *data);
void	ft_update_map(t_data *data, int keycode);
void	ft_left(t_data *data, int i, int j);
void	ft_right(t_data *data, int i, int j);
void	ft_up(t_data *data, int i, int j);
void	ft_down(t_data *data, int i, int j);
int		ft_line_size_check(char *line, t_data *data);
void	ft_put_step(t_data *data);

#endif
