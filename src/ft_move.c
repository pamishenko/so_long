/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:26:00 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/16 14:11:27 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map_element	*get_player(t_window *window)
{
	t_map_element	*gamer;

	gamer = window->tmap->map_list;
	while (gamer->type != player)
		gamer = gamer->next_element;
	return (gamer);
}

t_map_element	*move_up_down(t_window *window, t_map_element *player, int key)
{
	t_map_element	*temp;
	int				x;

	temp = NULL;
	x = window->size.x;
	temp = player;
	if (key == W || key == UP)
		while (x--)
			temp = temp->preview_element;
	if (key == S || key == DOWN)
		while (x--)
			temp = temp->next_element;
	return (temp);
}

int	move_player(t_window *window, int key)
{
	t_map_element	*player;
	int				i;

	i = 0;
	player = get_player(window);
	if (key == RIGHT || key == D)
		if (set_player_new_qt(window, player->next_element) == 0)
			clean_map_element(window, player);
	if (key == LEFT || key == A)
		if (set_player_new_qt(window, player->preview_element) == 0)
			clean_map_element(window, player);
	if (key == W || key == S || key == UP || key == DOWN)
		if (set_player_new_qt(window, move_up_down(window, player, key)) == 0)
			clean_map_element(window, player);
	printf("%d\n", ++window->steps);
	mlx_loop_hook(window->mlx, update_map, window);
	while (i < 999999)
		i++;
	return (0);
}

int	set_player_new_qt(t_window *window, t_map_element *t_map_element)
{	
	long	i;

	i = 0;
	if (t_map_element->type == dor && window->tmap->boxes_count
		== window->tmap->boxes_found)
	{
		while (i < 299999999)
			i++;
		exit (0);
	}
	if (t_map_element->type != wall && t_map_element->type != dor)
	{
		if (t_map_element->type == collectible)
			window->tmap->boxes_found++;
		t_map_element->type = player;
		t_map_element->reference = window->tmap->player->reference;
		return (0);
	}
	return (1);
}
