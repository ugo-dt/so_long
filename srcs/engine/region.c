/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:43:44 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 22:30:11 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#define COLLEC COLLECTIBLE

int	get_region_to_draw(t_pos *player_pos, t_region **regions, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		if (player_pos->x >= regions[i]->row_start
			&& player_pos->x < regions[i]->row_start + 9
			&& player_pos->y >= regions[i]->col_start
			&& player_pos->y < regions[i]->col_start + 14)
			return (i);
		i++;
	}
	return (0);
}

void	draw_texture(t_game *game, t_texture *tex, t_pos *cell)
{
	int		i;
	int		j;
	t_pos	pixel;
	t_pos	p_tex;

	copy_pos(&pixel, cell);
	i = 0;
	while (i < tex->height - 1)
	{
		j = 0;
		pixel.y = cell->y;
		while (j < tex->width - 1)
		{
			set_pos(&p_tex, i, j);
			draw_pixel(&game->window, &pixel, get_tex_color(tex, &p_tex));
			pixel.y++;
			j++;
		}
		pixel.x++;
		i++;
	}
}

static void	draw_cell(t_game *game, int region, t_pos *pos)
{
	t_pos	start;

	set_pos(&start,
		pos->y * game->config.cell_size, pos->x * game->config.cell_size);
	if (game->config.regions[region]->region[pos->x][pos->y] == MAP_WALL)
		draw_texture(game, &game->tex[0], &start);
	else if (game->config.regions[region]->region[pos->x][pos->y] == COLLEC)
		draw_texture(game, &game->tex[2], &start);
	else if (game->config.regions[region]->region[pos->x][pos->y] == MAP_EXIT
		&& game->collected < game->config.to_collect)
		draw_texture(game, &game->tex[3], &start);
	else if (game->config.regions[region]->region[pos->x][pos->y] == MAP_EXIT
		&& game->collected >= game->config.to_collect)
		draw_texture(game, &game->tex[4], &start);
	else
		draw_texture(game, &game->tex[1], &start);
}

void	draw_region(t_game *game, int region)
{
	t_pos	pos;

	pos.x = 0;
	while (pos.x < game->config.regions[region]->rows)
	{
		pos.y = 0;
		while (pos.y < game->config.regions[region]->cols)
		{
			draw_cell(game, region, &pos);
			pos.y++;
		}
		pos.x++;
	}
}
