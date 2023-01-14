/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:19:10 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/16 10:59:55 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	checker_component(const char *patch)
{
	int		fd;
	char	*line;
	int		total_count;
	int		target_count;
	int		i;

	total_count = 0;
	target_count = 0;
	fd = open(patch, O_RDONLY);
	while (ft_get_next_line(fd, &line) > 0)
	{
		i = -1;
		total_count += ft_strlen(line);
		while (++i < (int)ft_strlen(line))
		{
			if (line[i] == '0' || line[i] == '1' || line[i] == 'C'
				|| line[i] == 'E' || line[i] == 'P')
				target_count++;
		}
		free(line);
	}
	free(line);
	close(fd);
	return (total_count - target_count);
}

int	checker_ber(const char *patch)
{
	int	len;
	int	result;

	result = 0;
	len = ft_strlen(patch);
	if (len < 5)
		return (1);
	result += patch[len - 4] - '.';
	result += patch[len - 3] - 'b';
	result += patch[len - 2] - 'e';
	result += patch[len - 1] - 'r';
	if (result != 0)
		return (1);
	return (0);
}

int	checker_only_folder(const char *patch)
{
	int		fd;
	char	buff[1];

	fd = open(patch, O_RDONLY);
	if (read(fd, buff, 1) <= 0)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	checker_rectangle(const char *patch)
{
	int		fd;
	char	*line;
	int		len1;
	int		result;

	result = 0;
	fd = open(patch, O_RDONLY);
	if (fd < 0 || ft_get_next_line(fd, &line) < 0 || checker_only_folder(patch))
		return (1);
	len1 = ft_strlen(line);
	free(line);
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (len1 != (int)ft_strlen(line))
			result++;
		free(line);
	}
	if (len1 != (int)ft_strlen(line))
		result++;
	free(line);
	close(fd);
	if (result)
		return (1);
	return (0);
}
