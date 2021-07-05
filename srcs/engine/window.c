/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:18:12 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/07/05 19:32:02 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_image(t_window *window, t_image *img)
{
	img->img = mlx_new_image(
			window->mlx_ptr, window->size.x, window->size.y);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(
			img->img, &img->bpp, &img->size_line, &img->endian);
	return (1);
}

static int	create_window(t_window *w)
{
	w->mlx_ptr = mlx_init();
	if (!w->mlx_ptr)
		return (0);
	w->window = mlx_new_window(w->mlx_ptr, w->size.x, w->size.y, "so_long");
	if (!w->window)
		return (0);
	return (1);
}

int	init_window(t_window *window, t_config *config)
{
	if (config->columns <= 14)
		config->win_size.x = config->columns * config->cell_size;
	if (config->rows <= 9)
		config->win_size.y = config->rows * config->cell_size;
	set_pos(&window->size, config->win_size.x, config->win_size.y);
	window->mlx_ptr = NULL;
	if (!create_window(window))
		return (0);
	set_pos(&window->half, window->size.x / 2, window->size.y / 2);
	if (!init_image(window, &window->screen))
		return (0);
	return (1);
}

void	clear_window(t_window *window)
{
	if (window->screen.img)
		mlx_destroy_image(window->mlx_ptr, window->screen.img);
	if (window->mlx_ptr && window->window)
		mlx_destroy_window(window->mlx_ptr, window->window);
}

int	update_window(t_game *game)
{
	t_pos		p1;
	t_pos		p2;
	t_window	*w;

	w = &game->window;
	set_pos(&p1, 0, 0);
	set_pos(&p2, game->window.size.x, 20);
	draw_rectangle(&game->window, &p1, &p2, BLACK);
	mlx_put_image_to_window(w->mlx_ptr, w->window, w->screen.img, 0, 0);
	draw_hud(game, &game->window, &game->config);
	return (0);
}
