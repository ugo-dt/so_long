/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:03:06 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/28 15:49:26 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "so_long.h"

void	check_enemy(t_game *game)
{
	t_pos	player;

	copy_pos(&player, &game->config.player_pos);
	if (game->config.map[player.x][player.y] == MAP_KNIGHT)
	{
		ft_printf("You lose! Try not to touch enemy knights!\n");
		exit_game(game, EXIT_SUCCESS);
	}
}

void	draw_enemy(t_game *game, int region)
{
	int		i;
	t_pos	enemy;

	i = 0;
	while (i < game->config.nb_enemies)
	{
		copy_pos(&enemy, &game->config.enemies[i].pos);
		if (enemy.x >= game->config.regions[region]->row_start
			&& enemy.x < game->config.regions[region]->rows
			+ game->config.regions[region]->row_start
			&& enemy.y >= game->config.regions[region]->col_start
			&& enemy.y < game->config.regions[region]->cols
			+ game->config.regions[region]->col_start)
			draw_element(game, &enemy, GREEN);
		i++;
	}
}
