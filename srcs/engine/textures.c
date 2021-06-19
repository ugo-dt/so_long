/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 09:35:27 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 19:02:06 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	clear_textures(t_game *game)
{
	int		i;

	i = 0;
	while (i < TEXTURES)
	{
		if (game->tex[i].tex)
			mlx_destroy_image(game->window.mlx_ptr, game->tex[i].tex);
		game->tex[i].tex = NULL;
		game->tex[i].ptr = NULL;
		i++;
	}
}

static int	load_texture(t_window *w, t_texture *tex, char *path)
{
	tex->height = 50;
	tex->width = 50;
	if (path)
	{
		tex->path = path;
		tex->tex = mlx_xpm_file_to_image(
				w->mlx_ptr, path, &tex->width, &tex->height);
		if (tex->tex)
			tex->ptr = mlx_get_data_addr(
					tex->tex, &tex->bpp, &tex->size_line, &tex->endian);
		else
			return (0);
	}
	return (1);
}

static int	line_is_empty(t_texture *tex, int line)
{
	int		i;
	t_pos	pos;

	pos.y = line;
	i = 0;
	while (i < tex->width)
	{
		pos.x = i;
		if (get_tex_color(tex, &pos) != 0x0)
			return (0);
		i++;
	}
	return (1);
}

static int	col_is_empty(t_texture *tex, int column)
{
	int		i;
	t_pos	pos;

	pos.x = column;
	i = 0;
	while (i < tex->height)
	{
		pos.y = i;
		if (get_tex_color(tex, &pos) != 0x0)
			return (0);
		i++;
	}
	return (1);
}

int	load_textures(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	while (i < TEXTURES)
	{
		if (!load_texture(&g->window, &g->tex[i], g->config.tex_path[i]))
			return (0);
		j = 0;
		while (j < g->tex[i].height && col_is_empty(&g->tex[i], j))
			j++;
		g->tex[i].start.x = j;
		while (j < g->tex[i].height && !col_is_empty(&g->tex[i], j))
			j++;
		g->tex[i].end.x = j;
		j = 0;
		while (j < g->tex[i].height && line_is_empty(&g->tex[i], j))
			j++;
		g->tex[i].start.y = j;
		while (j < g->tex[i].height && !line_is_empty(&g->tex[i], j))
			j++;
		g->tex[i].end.y = j;
		i++;
	}
	return (1);
}
