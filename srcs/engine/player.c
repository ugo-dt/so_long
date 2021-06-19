/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:40:00 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 09:44:57 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	move_player(t_game *game, int key)
{
	t_pos	temp;

	copy_pos(&temp, &game->config.player_pos);
	if (key == KEY_W && temp.x - 1 > 0)
		if (game->config.map[(int)temp.x - 1][(int)temp.y] != '1')
			set_pos(&game->config.player_pos, temp.x - 1, temp.y);
	if (key == KEY_A && temp.y - 1 > 0)
		if (game->config.map[(int)temp.x][(int)temp.y - 1] != '1')
			set_pos(&game->config.player_pos, temp.x, temp.y - 1);
	if (key == KEY_S && temp.x + 1 < game->config.rows)
		if (game->config.map[(int)temp.x + 1][(int)temp.y] != '1')
			set_pos(&game->config.player_pos, temp.x + 1, temp.y);
	if (key == KEY_D && temp.y + 1 < game->config.columns)
		if (game->config.map[(int)temp.x][(int)temp.y + 1] != '1')
			set_pos(&game->config.player_pos, temp.x, temp.y + 1);
	if (game->config.player_pos.x != temp.x
		|| game->config.player_pos.y != temp.y)
		ft_printf("Movements: %d\n", ++game->movements);
}
