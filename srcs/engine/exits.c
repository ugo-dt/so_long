/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 13:56:08 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/28 15:49:04 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "so_long.h"

void	check_exit(t_game *game)
{
	t_pos	player;

	copy_pos(&player, &game->config.player_pos);
	if (game->config.map[player.x][player.y] == MAP_EXIT)
	{
		if (game->collected == game->config.to_collect)
		{
			ft_printf("You win! You finished in %d moves.\n",
				game->movements);
			exit_game(game, EXIT_SUCCESS);
		}
		else
		{
			ft_printf("You still need %d ",
				game->config.to_collect - game->collected);
			if (game->config.to_collect - game->collected == 1)
				ft_printf("collectible!\n",
					game->config.to_collect - game->collected);
			else
				ft_printf("collectibles!\n",
					game->config.to_collect - game->collected);
		}
	}
}

void	draw_exit(t_game *game, int region)
{
	int		i;
	t_pos	exit;

	i = 0;
	while (i < game->config.nb_exits)
	{
		copy_pos(&exit, &game->config.exits[i].pos);
		if (exit.x >= game->config.regions[region]->row_start
			&& exit.x < game->config.regions[region]->rows
			+ game->config.regions[region]->row_start
			&& exit.y >= game->config.regions[region]->col_start
			&& exit.y < game->config.regions[region]->cols
			+ game->config.regions[region]->col_start)
			draw_element(game, &exit, GREEN);
		i++;
	}
}
