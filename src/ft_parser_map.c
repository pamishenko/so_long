/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 15:49:37 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/16 00:01:18 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_characters	parse_character(char c)
{
	if (c == '0')
		return (none);
	if (c == '1')
		return (wall);
	if (c == 'E')
		return (dor);
	if (c == 'C')
		return (collectible);
	if (c == 'P')
		return (player);
	else
		return (none);
}

void	parser_map(t_window *window, char *path_map)
{
	char	*line;
	char	*temp;
	int		fd;
	int		position;

	position = 0;
	ft_init_map(window);
	fd = open(path_map, O_RDONLY);
	while (ft_get_next_line(fd, &line) > 0)
	{
		temp = line;
		window->size.x = ft_strlen(line);
		window->size.y++;
		while (*temp)
			ft_create_map_element(window, parse_character(*temp++), position++);
		free(line);
	}
	temp = line;
	while (*temp)
		ft_create_map_element(window, parse_character(*temp++), position++);
	close(fd);
	free(line);
}
