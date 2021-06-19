/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:10:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 17:53:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game, int status)
{
	clear_textures(game);
	clear_config(&game->config);
	clear_window(&game->window);
	exit(status);
	return (status);
}

void	init_game(t_game *game)
{
	int		i;

	i = 0;
	while (i < TEXTURES)
	{
		game->tex[i].tex = NULL;
		game->tex[i].ptr = NULL;
		i++;
	}
	mlx_mouse_hide();
	game->keys.key_w = 0;
	game->keys.key_a = 0;
	game->keys.key_s = 0;
	game->keys.key_d = 0;
	game->movements = 0;
	game->collected = 0;
	game->config.tex_path[0] = ft_strdup(TEX_WALL_PATH);
	game->config.tex_path[1] = ft_strdup(TEX_FLOOR_PATH);
}

int	launch_game(t_game *game)
{
	if (!init_window(&game->window, &game->config))
		clear_and_exit(game, "So_long: could not create window\n");
	if (!load_textures(game))
		clear_and_exit(game, "So_long: could not load textures\n");
	return (1);
}
