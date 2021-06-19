/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:40:00 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 20:40:59 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	move_player(t_game *game, int key)
{
	t_pos	temp;
	t_pos	*player;

	player = &game->config.player_pos;
	copy_pos(&temp, player);
	if (key == KEY_W && temp.x - 1 > 0)
		if (game->config.map[temp.x - 1][temp.y] != '1')
			set_pos(player, temp.x - 1, temp.y);
	if (key == KEY_A && temp.y - 1 > 0)
		if (game->config.map[temp.x][temp.y - 1] != '1')
			set_pos(player, temp.x, temp.y - 1);
	if (key == KEY_S && temp.x + 1 < game->config.rows)
		if (game->config.map[temp.x + 1][temp.y] != '1')
			set_pos(player, temp.x + 1, temp.y);
	if (key == KEY_D && temp.y + 1 < game->config.columns)
		if (game->config.map[temp.x][temp.y + 1] != '1')
			set_pos(player, temp.x, temp.y + 1);
	if (player->x != temp.x	|| player->y != temp.y)
		ft_printf("Movements: %d\n", ++game->movements);
	pick_collectible(game);
	check_exit(game);
	game->config.map[temp.x][temp.y] = MAP_FLOOR;
	game->config.map[player->x][player->y] = PLAYER;
}
