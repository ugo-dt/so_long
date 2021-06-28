/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:08:58 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/28 15:16:35 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <unistd.h>
# include <fcntl.h>

# ifdef LINUX
#  include "../utils/utils.h"
#  include "../gnl/get_next_line.h"
# else
#  include "utils/utils.h"
#  include "gnl/get_next_line.h"
# endif

# define MAP_CHARACTERS "01CEPK"
# define POSITIONS		"CEPK"
# define MAP_WALL		'1'
# define MAP_FLOOR		'0'
# define COLLECTIBLE	'C'
# define PLAYER			'P'
# define MAP_EXIT		'E'
# define MAP_KNIGHT		'K'

# define TEXTURES			7
# define TEX_WALL			0
# define TEX_FLOOR			1
# define TEX_COLLECTIBLE	2
# define TEX_EXIT_CLOSED	3
# define TEX_EXIT_OPENED	4
# define TEX_PLAYER			5
# define TEX_KNIGHT			6

# define TEX_WALL_PATH			"data/wall.xpm"
# define TEX_FLOOR_PATH			"data/floor.xpm"
# define TEX_COLLECTIBLE_PATH	"data/key.xpm"
# define TEX_EXIT_CLOSED_PATH	"data/closed_door.xpm"
# define TEX_EXIT_OPENED_PATH	"data/opened_door.xpm"
# define TEX_PLAYER_PATH		"data/character.xpm"
# define TEX_KNIGHT_PATH		"data/knight.xpm"


# define FLAG_UPDATE	0b1
# define FLAG_UI		0b10

typedef struct s_region
{
	char	region[9][14];
	int		col_start;
	int		row_start;
	int		size;
	int		cols;
	int		rows;
}t_region;

typedef struct s_element
{
	t_pos	pos;
	int		number;
}t_element;

typedef struct s_config
{
	t_pos			win_size;
	t_pos			player_pos;
	t_region		**regions;
	int				nb_regions;
	int				columns;
	int				rows;
	int				map_size;
	char			**map;
	double			cell_size;
	t_element		*collectibles;
	int				to_collect;
	t_element		*exits;
	int				nb_exits;
	t_element		*enemies;
	int				nb_enemies;
	char			*tex_path[TEXTURES];
	unsigned int	flags;
}t_config;

void	init_config(t_config *config);
int		parse_config(t_config *config, int fd);
int		clear_config(t_config *config);

int		parse_map(t_config *config, t_str *map_buffer);

int		check_side_borders(t_str *map_buf);
int		check_top_bottom_borders(t_str *map_buf);
int		check_valid_map(t_config *config, t_str *map_buf);

void	positions_in_map(t_config *config, char element, int x, int y);

void	define_regions(t_config *confi);

void	init_textures(t_config *config);

int		find_collectibles(t_config *config);
int		find_enemies(t_config *config);
int		find_exits(t_config *config);

#endif
