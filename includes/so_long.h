/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 23:26:28 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/16 10:36:34 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10000

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "./mlx.h"
# include "./libft.h"
# include "./ft_get_next_line.h"
# include "./constants.h"
# include "./structures.h"

t_map_element	*get_player(t_window *window);
void			init_window(t_window *window, char *map_patch);
void			parser_map(t_window *window, char *path_map);
t_map_element	*ft_get_last_map_element(t_window *window);
t_map_element	*ft_create_map_element(t_window *window,
					t_characters ch, int position);
void			ft_delete_map_element(t_window *window);
t_element		*ft_create_t_element(t_window *window,
					char *pic, t_characters ch);
void			ft_delete_t_elements(t_window *window);
int				ft_init_map(t_window *window);
void			set_reference_pointer(t_window *window,
					t_map_element *map_element);
int				update_map(t_window *window);
int				close_click(int keycode, void *mlx_win);
void			set_window(t_window *window);
int				move_player(t_window *window, int key);
t_map_element	*move_up_down(t_window *window, t_map_element *player, int key);
int				set_player_new_qt(t_window *window,
					t_map_element *t_map_element);
int				checker_component(const char *patch);
int				checker_ber(const char *patch);
int				checker_element(const char *patch);
int				checker_element_utils(t_item_for_chek *item);
int				checker_map(const char *path);
int				checker_only_folder(const char *patch);
int				checker_rectangle(const char *patch);
int				checker_wal(const char *patch);
void			clean_map_element(t_window *window,
					t_map_element *t_map_element);

#endif
