/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   region.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:43:44 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 19:02:24 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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

static void	draw_texture(t_game *game, t_texture *tex, t_pos *cell)
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

static void	draw_cell(t_game *game, int region, int i, int j)
{
	t_pos	start;
	t_pos	end;

	set_pos(&start,
		j * game->config.cell_size, i * game->config.cell_size);
	set_pos(&end,
		start.x + game->config.cell_size - 1,
		start.y + game->config.cell_size - 1);
	if (game->config.regions[region]->region[i][j] == MAP_WALL)
		draw_texture(game, &game->tex[0], &start);
	else
		draw_texture(game, &game->tex[1], &start);
}

void	draw_region(t_game *game, int region)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->config.regions[region]->rows)
	{
		j = 0;
		while (j < game->config.regions[region]->cols)
		{
			draw_cell(game, region, i, j);
			j++;
		}
		i++;
	}
}
