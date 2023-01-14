/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:23:36 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/15 23:48:55 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_init_map(t_window *window)
{
	window->tmap = ft_calloc(sizeof(t_map), 1);
	window->tmap->grass = ft_create_t_element(window,
			"./assets/map/grass.xpm", none);
	window->tmap->wall = ft_create_t_element(window,
			"./assets/map/wall.xpm", wall);
	window->tmap->collect = ft_create_t_element(window,
			"./assets/map/box.xpm", collectible);
	window->tmap->dor = ft_create_t_element(window,
			"./assets/map/dor.xpm", dor);
	window->tmap->player = ft_create_t_element(window,
			"./assets/player/fHero_l.xpm", player);
	return (0);
}

void	set_reference_pointer(t_window *window, t_map_element *map_element)
{
	if (map_element->type == none)
		map_element->reference = window->tmap->grass->reference;
	if (map_element->type == wall)
		map_element->reference = window->tmap->wall->reference;
	if (map_element->type == collectible)
		map_element->reference = window->tmap->collect->reference;
	if (map_element->type == dor)
		map_element->reference = window->tmap->dor->reference;
	if (map_element->type == player)
		map_element->reference = window->tmap->player->reference;
}

void	set_window(t_window *window)
{
	t_map_element	*temp;

	temp = window->tmap->map_list;
	window->mlx_win = mlx_new_window(window->mlx, window->size.x * 31,
			window->size.y * 31 + 31, "So_long by ttanja");
	while (temp)
	{
		if (temp->type != none)
			mlx_put_image_to_window(window->mlx, window->mlx_win,
				window->tmap->grass->reference,
				temp->position_x * 31,
				temp->position_y * 31);
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			window->tmap->grass->reference,
			temp->position_x * 30,
			temp->position_y * 30);
		temp = temp->next_element;
	}
}

int	update_map(t_window *window)
{
	t_map_element	*temp;

	temp = window->tmap->map_list;
	mlx_put_image_to_window(window->mlx, window->mlx_win, temp->reference,
		0, 0);
	temp = temp->next_element;
	while (temp)
	{
		mlx_put_image_to_window(window->mlx, window->mlx_win, temp->reference,
			temp->position_x * 31 - 31,
			temp->position_y * 31 - 31);
		temp = temp->next_element;
	}
	return (0);
}

void	ft_delete_t_elements(t_window *window)
{
	free(window->tmap->grass->patch_picture);
	free(window->tmap->wall->patch_picture);
	free(window->tmap->collect->patch_picture);
	free(window->tmap->dor->patch_picture);
	free(window->tmap->player->patch_picture);
	free(window->tmap->grass);
	free(window->tmap->wall);
	free(window->tmap->collect);
	free(window->tmap->dor);
	free(window->tmap->player);
}
