/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:14:15 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/16 00:02:02 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_size
{
	int	y;
	int	x;
}				t_size;

typedef enum t_characters
{
	none,
	wall,
	collectible,
	dor,
	player
}	t_characters;

typedef struct s_element {
	t_characters	characters;
	char			*patch_picture;
	void			*reference;
	int				img_width;
	int				img_height;
}					t_element;

typedef struct s_map_element
{
	struct s_map_element	*preview_element;
	struct s_map_element	*next_element;
	int						position_x;
	int						position_y;
	void					*reference;
	t_characters			type;
}							t_map_element;

typedef struct s_map
{
	t_element		*grass;
	t_element		*wall;
	t_element		*collect;
	t_element		*dor;
	t_element		*player;
	t_map_element	*map_list;
	int				boxes_count;
	int				boxes_found;
}					t_map;

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	t_map		*tmap;
	t_size		size;
	int			steps;
}				t_window;

typedef struct s_item_for_chek
{
	int			wall;
	int			none;
	int			col;
	int			dor;
	int			pl;
}				t_item_for_chek;

typedef struct s_chek_wall
{
	int		fd;
	char	*line;
	int		i;
	int		count_line;
	int		result;
}			t_ch_wal;

#endif
