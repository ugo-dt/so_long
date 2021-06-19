/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:00:55 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 21:22:53 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# ifdef LINUX
#  include "../../mlx-linux/mlx.h"
#  include "../config/config.h"
# else
#  include "mlx.h"
#  include "config/config.h"
# endif

# define RED	0xff0000
# define GREEN	0x00a600
# define BLUE	0x6969ff
# define WHITE	0xf0f0f0
# define BLACK	0x000000
# define GRAY	0x3b3b3b
# define YELLOW	0xfffb00

# ifdef LINUX
#  define KEY_W		119
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_M		109
#  define KEY_ESC	65307
# else
#  define KEY_W		6
#  define KEY_A		12
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_M		41
#  define KEY_ESC	53
# endif

typedef struct s_image
{
	char	*img;
	void	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_image;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*window;
	t_image	screen;
	t_pos	size;
	t_pos	half;
}t_window;

typedef struct s_texture
{
	char	*path;
	void	*tex;
	void	*ptr;
	t_pos	start;
	t_pos	end;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}t_texture;

typedef struct s_sprite
{
	t_pos			pos;
	t_texture		*tex;
	struct s_sprite	*next;
	struct s_sprite	*sorted;
}t_sprite;

typedef struct s_keys
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_left;
	int		key_right;
}t_keys;

typedef struct s_game
{
	t_window	window;
	t_config	config;
	t_keys		keys;
	t_texture	tex[TEXTURES];
	int			movements;
	int			collected;
}t_game;

int		init_window(t_window *window, t_config *config);
int		init_image(t_window *window, t_image *img);
void	clear_window(t_window *window);
void	update_window(t_game *game);
void	update_screen(t_game *game);

int		draw_rectangle(t_window *window,
			t_pos *p1, t_pos *p2, int color);
void	draw_line(t_window *window, t_pos *p1, t_pos *p2, int color);
int		draw_vertical_line(t_window *win,
			t_pos *start, int length, int color);

void	draw_element(t_game *game, t_pos *pos, int color);

void	draw_pixel(t_window *window, t_pos *pos, int color);

void	move_player(t_game *game, int key);

void	draw_minimap(t_game *game, t_window *w);

void	draw_hud(t_game *game, t_window *w, t_config *c);

int		get_region_to_draw(t_pos *player_pos, t_region **regions, int max);
void	draw_region(t_game *game, int region);
void	draw_texture(t_game *game, t_texture *tex, t_pos *cell);

void	draw_collectibles(t_game *game, int region);
void	pick_collectible(t_game *game);
int		get_collectible_number(t_game *game, t_pos *pos);

void	draw_exit(t_game *game, int region);
void	check_exit(t_game *game);

int		load_textures(t_game *game);
void	clear_textures(t_game *game);

int		get_tex_color(t_texture *tex, t_pos *pos);

#endif
