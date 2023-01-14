/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:23:34 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/16 10:59:06 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	checker_element_utils(t_item_for_chek *item)
{
	if (item->pl == 1 && item->col > 0 && item->dor > 0)
		return (0);
	return (1);
}

int	checker_element(const char *patch)
{
	int				fd;
	char			line[1];
	int				i;
	t_item_for_chek	*items;

	items = ft_calloc(sizeof(t_item_for_chek), 1);
	fd = open(patch, O_RDONLY);
	while (read(fd, line, 1) > 0)
	{
		if (line[0] == '0')
			items->none++;
		else if (line[0] == '1')
			items->wall++;
		else if (line[0] == 'C')
			items->col++;
		else if (line[0] == 'E')
			items->dor++;
		else if (line[0] == 'P')
			items->pl++;
	}
	i = checker_element_utils(items);
	close(fd);
	free(items);
	return (i);
}

void	norma_kostyl(t_ch_wal *item)
{
	while (ft_get_next_line(item->fd, &item->line) > 0
		&& (item->count_line++ > -1))
	{
		while (item->line[item->i] && item->count_line == 1)
			if (item->line[item->i++] != '1')
				item->result++;
		if (item->line[0] != '1'
			|| item->line[ft_strlen(item->line) - 1] != '1')
			item->result++;
		item->i = 0;
		free(item->line);
	}
}

int	checker_wal(const char *patch)
{
	t_ch_wal	*item;
	int			i;

	item = ft_calloc(sizeof(t_ch_wal), 1);
	item->fd = open(patch, O_RDONLY);
	norma_kostyl(item);
	while (item->line[item->i])
		if (item->line[item->i++] != '1')
			item->result++;
	free(item->line);
	close(item->fd);
	i = item->result;
	free(item);
	if (i)
		return (1);
	return (0);
}

int	checker_map(const char *path)
{
	if (checker_rectangle(path))
		return (1);
	return (checker_component(path) + checker_ber(path)
		+ checker_element(path)
		+ checker_wal(path));
}
