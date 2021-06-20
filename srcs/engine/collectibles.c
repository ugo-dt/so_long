/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:42:24 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/20 10:36:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	get_collectible_number(t_game *game, t_pos *pos)
{
	int		i;

	i = 0;
	while (i < game->config.to_collect)
	{
		if (pos->x == game->config.collectibles[i].pos.x
			&& pos->y == game->config.collectibles[i].pos.y)
			return (i);
		i++;
	}
	return (-1);
}

void	pick_collectible(t_game *game)
{
	int		i;
	int		region;
	t_pos	player;

	copy_pos(&player, &game->config.player_pos);
	if (game->config.map[player.x][player.y] == COLLECTIBLE)
	{
		region = get_region_to_draw(
				&player,
				game->config.regions,
				game->config.nb_regions);
		game->config.map[player.x][player.y] = MAP_FLOOR;
		pos_in_window(&player);
		game->config.regions[region]->region[player.x][player.y] = MAP_FLOOR;
		i = get_collectible_number(game, &player);
		game->collected++;
	}
}

void	draw_collectibles(t_game *game, int region)
{
	int		i;
	t_pos	collectible;

	i = 0;
	while (i < game->config.to_collect)
	{
		copy_pos(&collectible, &game->config.collectibles[i].pos);
		if (collectible.x >= game->config.regions[region]->row_start
			&& collectible.x < game->config.regions[region]->rows
			+ game->config.regions[region]->row_start
			&& collectible.y >= game->config.regions[region]->col_start
			&& collectible.y < game->config.regions[region]->cols
			+ game->config.regions[region]->col_start)
			draw_element(game, &collectible, BLUE);
		i++;
	}
}
