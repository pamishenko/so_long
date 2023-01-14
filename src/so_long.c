/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttanja <ttanja@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:46:15 by ttanja            #+#    #+#             */
/*   Updated: 2021/10/16 00:08:21 by ttanja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_click(int keycode, void *mlx_win)
{
	(void) mlx_win;
	(void) keycode;
	exit(0);
	return (0);
}

int	key_press(int keycode, t_window *window)
{
	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT
		|| keycode == W || keycode == S
		|| keycode == A || keycode == D)
		move_player(window, keycode);
	if (keycode == ESCAPE)
		exit(0);
	return (keycode);
}

int	main(int argc, char *argv[])
{
	t_window	*window;

	if (argc != 2 || checker_map(argv[1]) > 0)
	{
		ft_putstr_fd("error map\n", 1);
		return (1);
	}
	window = ft_calloc(sizeof(t_window), 1);
	window->mlx = mlx_init();
	parser_map(window, argv[1]);
	set_window(window);
	update_map(window);
	mlx_hook(window->mlx_win, 17, 0, close_click, &window->mlx_win);
	mlx_hook(window->mlx_win, 2, 1L << 0, key_press, window);
	mlx_loop(window->mlx);
	return (0);
}
