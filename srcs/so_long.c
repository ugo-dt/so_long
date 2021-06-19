/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:28:33 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/17 14:37:04 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_game *game)
{
	return (exit_game(game, EXIT_SUCCESS));
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player(game, KEY_W);
	if (keycode == KEY_A)
		move_player(game, KEY_A);
	if (keycode == KEY_S)
		move_player(game, KEY_S);
	if (keycode == KEY_D)
		move_player(game, KEY_D);
	if (keycode == KEY_M)
		game->config.flags = game->config.flags ^ FLAG_UI;
	if (keycode == KEY_ESC)
		exit_game(game, EXIT_SUCCESS);
	game->config.flags = game->config.flags | FLAG_UPDATE;
	return (0);
}

int	main_loop(t_game *game)
{
	if (game->config.flags & FLAG_UPDATE)
	{
		update_screen(game);
		update_window(game);
	}
	game->config.flags = game->config.flags & ~FLAG_UPDATE;
	return (0);
}
