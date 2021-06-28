/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:56:13 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/28 15:13:09 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	clear_config(t_config *config)
{
	int		i;

	if (config->map)
	{
		i = 0;
		while (i < config->rows)
			free(config->map[i++]);
		free(config->map);
	}
	if (config->regions)
	{
		i = 0;
		while (i < config->nb_regions)
			free(config->regions[i++]);
		free(config->regions);
	}
	if (config->exits)
		free(config->exits);
	if (config->collectibles)
		free(config->collectibles);
	if (config->enemies)
		free(config->enemies);
	return (0);
}

void	init_config(t_config *config)
{
	config->map = NULL;
	config->rows = 0;
	config->columns = 0;
	config->win_size.x = 700;
	config->win_size.y = 450;
	config->cell_size = 50;
	set_pos(&config->player_pos, -1, -1);
	config->regions = NULL;
	config->nb_regions = 0;
	config->to_collect = 0;
	config->collectibles = 0;
	config->flags = FLAG_UPDATE;
	config->nb_exits = 0;
	config->exits = 0;
	config->nb_enemies = 0;
	config->enemies = 0;
}

static int	parse_line(t_config *config, char *line, t_str **map_buf)
{
	int		i;
	int		len;

	len = ft_strlen(line);
	if (len == 0)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] == COLLECTIBLE)
			config->to_collect++;
		else if (line[i] == MAP_EXIT)
			config->nb_exits++;
		else if (line[i] == MAP_KNIGHT)
			config->nb_enemies++;
		i++;
	}
	return (!!t_str_add_back(map_buf, ft_strdup(line)));
}

int	parse_config(t_config *config, int fd)
{
	char	*line;
	int		read;
	t_str	*map_buffer;

	map_buffer = NULL;
	read = 1;
	while (get_next_line(fd, &line))
	{
		read = (read && parse_line(config, line, &map_buffer));
		free(line);
	}
	if (read && ft_strlen(line) > 0)
		read = !!t_str_add_back(&map_buffer, ft_strdup(line));
	free(line);
	close(fd);
	if (!parse_map(config, map_buffer))
		return (t_str_clear(&map_buffer));
	t_str_clear(&map_buffer);
	define_regions(config);
	return (1);
}
