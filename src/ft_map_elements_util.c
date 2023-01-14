/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_elements_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:00:22 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/16 00:00:53 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map_element	*ft_get_last_map_element(t_window *window)
{
	t_map_element	*this_element;

	this_element = window->tmap->map_list;
	if (!this_element)
		return (NULL);
	while (this_element->next_element != NULL)
		this_element = this_element->next_element;
	return (this_element);
}

t_map_element	*ft_create_map_element(t_window *window,
	t_characters ch, int position)
{
	t_map_element	*new_element;
	t_map_element	*last_element;

	new_element = ft_calloc(sizeof(t_map_element), 1);
	new_element->type = ch;
	last_element = ft_get_last_map_element(window);
	if (!last_element)
		window->tmap->map_list = new_element;
	else
	{
		last_element->next_element = new_element;
		new_element->preview_element = last_element;
	}
	if (new_element->type == collectible)
		window->tmap->boxes_count++;
	new_element->position_x = position % window->size.x + 1;
	new_element->position_y = position / window->size.x + 1;
	set_reference_pointer(window, new_element);
	return (new_element);
}

void	clean_map_element(t_window *window, t_map_element *t_map_element)
{
	t_map_element->type = none;
	t_map_element->reference = window->tmap->grass->reference;
}

void	ft_delete_map_element(t_window *window)
{
	t_map_element	*last_element;

	last_element = ft_get_last_map_element(window);
	while (last_element)
	{
		if (last_element->preview_element)
			last_element->preview_element->next_element = NULL;
		free(last_element);
		last_element = ft_get_last_map_element(window);
	}
}

t_element	*ft_create_t_element(t_window *window,
	char *patch_pict, t_characters ch)
{
	t_element	*t_el_pt;

	t_el_pt = ft_calloc(sizeof(t_element), 1);
	t_el_pt->patch_picture = patch_pict;
	t_el_pt->reference = mlx_xpm_file_to_image(window->mlx,
			patch_pict, &t_el_pt->img_width, &t_el_pt->img_height);
	t_el_pt->characters = ch;
	return (t_el_pt);
}
