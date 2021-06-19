/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:50:17 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 19:01:11 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	cell_color(t_game *game, int x, int y)
{
	char	c;

	if (x == game->config.player_pos.x && y == game->config.player_pos.y)
		return (RED);
	c = game->config.map[x][y];
	if (c == MAP_WALL)
		return (BLACK);
	else if (c == MAP_EXIT)
		return (GREEN);
	else if (c == COLLECTIBLE)
		return (BLUE);
	return (WHITE);
}

void	draw_hud(t_game *game, t_window *w, t_config *c)
{
	static int	x = 88;
	static int	x2 = 0;
	t_pos		pos;

	set_pos(&pos, 5, 15);
	mlx_string_put(w->mlx_ptr, w->window, pos.x, pos.y, RED, "Remaining: ");
	set_pos(&pos, 77, 15);
	mlx_string_put(w->mlx_ptr, w->window, pos.x, pos.y,
		RED, ft_itoa(c->to_collect - game->collected));
	if ((game->movements >= 100 && x < 95)
		|| (game->movements >= 1000 && x < 102))
	{
		x += 7;
		x2 += 7;
	}
	set_pos(&pos, w->size.x - x, 15);
	mlx_string_put(w->mlx_ptr, w->window, pos.x, pos.y, RED, "Movements: ");
	if (game->movements >= 10)
		set_pos(&pos, w->size.x - 16 - x2, 15);
	else
		set_pos(&pos, w->size.x - 11 - x2, 15);
	mlx_string_put(w->mlx_ptr, w->window, pos.x, pos.y,
		RED, ft_itoa(game->movements));
}

void	draw_minimap(t_game *game, t_window *w)
{
	int		i;
	int		j;
	int		color;
	t_pos	start;
	t_pos	end;

	i = 0;
	while (i < game->config.rows)
	{
		j = 0;
		while (j < game->config.columns)
		{
			color = cell_color(game, i, j);
			set_pos(&start,
				w->size.x - (game->config.columns * 5) - 5 + (j * 5),
				w->size.y - (game->config.rows * 5) - 5 + (i * 5));
			set_pos(&end,
				w->size.x - (game->config.columns * 5) + 5 + (j * 5),
				w->size.y - (game->config.rows * 5) + 5 + (i * 5));
			draw_rectangle(w, &start, &end, color);
			j++;
		}
		i++;
	}
}
