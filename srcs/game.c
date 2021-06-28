/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:10:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/28 15:16:58 by ugdaniel         ###   ########.fr       */
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
		game->config.tex_path[i] = NULL;
		i++;
	}
	game->keys.key_w = 0;
	game->keys.key_a = 0;
	game->keys.key_s = 0;
	game->keys.key_d = 0;
	game->movements = 0;
	game->collected = 0;
	game->config.tex_path[0] = ft_strdup(TEX_WALL_PATH);
	game->config.tex_path[1] = ft_strdup(TEX_FLOOR_PATH);
	game->config.tex_path[2] = ft_strdup(TEX_COLLECTIBLE_PATH);
	game->config.tex_path[3] = ft_strdup(TEX_EXIT_CLOSED_PATH);
	game->config.tex_path[4] = ft_strdup(TEX_EXIT_OPENED_PATH);
	game->config.tex_path[5] = ft_strdup(TEX_PLAYER_PATH);
	game->config.tex_path[6] = ft_strdup(TEX_KNIGHT_PATH);
}

#ifndef LINUX
int	launch_game(t_game *game)
{
	if (!init_window(&game->window, &game->config))
		clear_and_exit(game, "So_long: could not create window\n");
	if (!load_textures(game))
		clear_and_exit(game, "So_long: could not load textures\n");
	mlx_hook(game->window.window, 2, 0, &key_press, game);
	mlx_hook(game->window.window, 17, 0, &exit_hook, game);
	mlx_loop_hook(game->window.mlx_ptr, &main_loop, game);
	mlx_loop(game->window.mlx_ptr);
	return (1);
}

#else
int	launch_game(t_game *game)
{
	if (!init_window(&game->window, &game->config))
		clear_and_exit(game, "So_long: could not create window\n");
	if (!load_textures(game))
		clear_and_exit(game, "So_long: could not load textures\n");
	mlx_hook(game->window.window, 2, (1L << 0), &key_press, game);
	mlx_hook(game->window.window, 33, (1L << 17), &exit_hook, game);
	mlx_hook(game->window.window, 9, (1L << 21), &update_window, game);
	mlx_loop_hook(game->window.mlx_ptr, &main_loop, game);
	mlx_loop(game->window.mlx_ptr);
	return (1);
}
#endif
