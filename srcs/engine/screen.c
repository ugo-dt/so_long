/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:01:29 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 09:12:06 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_element(t_game *game, t_pos *pos, int color)
{
	t_pos	start;
	t_pos	end;
	t_pos	temp;

	copy_pos(&temp, pos);
	pos_in_window(&temp);
	set_pos(&start,
		temp.y * game->config.cell_size + 15,
		temp.x * game->config.cell_size + 15);
	set_pos(&end,
		start.x + game->config.cell_size - 30,
		start.y + game->config.cell_size - 30);
	draw_rectangle(&game->window, &start, &end, color);
}

static void	draw_map(t_game *game)
{
	int		region;

	region = get_region_to_draw(
			&game->config.player_pos,
			game->config.regions,
			game->config.nb_regions);
	draw_region(game, region);
	draw_collectibles(game, region);
	draw_exit(game, region);
}

void	update_screen(t_game *game)
{
	t_pos	start;

	set_pos(&start, 0, 0);
	draw_rectangle(&game->window, &start, &game->window.size, BLACK);
	draw_map(game);
	draw_element(game, &game->config.player_pos, RED);
	if (game->config.flags & FLAG_UI)
		draw_minimap(game, &game->window);
}
