/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:40:12 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/28 15:11:02 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	find_exits(t_config *config)
{
	int		i;
	int		j;
	int		k;

	config->exits = malloc(sizeof(t_element) * config->nb_exits);
	if (!config->exits)
		return (0);
	i = 0;
	j = 0;
	while (j < config->rows)
	{
		k = 0;
		while (k < config->columns)
		{
			if (config->map[j][k] == MAP_EXIT && i < config->nb_exits)
			{
				set_pos(&config->exits[i].pos, j, k);
				config->exits->number = i;
				i++;
			}
			k++;
		}
		j++;
	}
	return (1);
}

int	find_collectibles(t_config *config)
{
	int		i;
	int		j;
	int		k;

	config->collectibles = malloc(sizeof(t_element) * config->to_collect);
	if (!config->collectibles)
		return (0);
	i = 0;
	j = 0;
	while (j < config->rows)
	{
		k = 0;
		while (k < config->columns)
		{
			if (config->map[j][k] == COLLECTIBLE && i < config->to_collect)
			{
				set_pos(&config->collectibles[i].pos, j, k);
				config->collectibles->number = i;
				i++;
			}
			k++;
		}
		j++;
	}
	return (1);
}

int	find_enemies(t_config *config)
{
	int		i;
	int		j;
	int		k;

	config->enemies = malloc(sizeof(t_element) * config->nb_enemies);
	if (!config->enemies)
		return (0);
	i = 0;
	j = 0;
	while (j < config->rows)
	{
		k = 0;
		while (k < config->columns)
		{
			if (config->map[j][k] == MAP_KNIGHT && i < config->nb_enemies)
			{
				set_pos(&config->enemies[i].pos, j, k);
				config->enemies->number = i;
				i++;
			}
			k++;
		}
		j++;
	}
	return (1);
}

static void	copy_map(t_config *config, t_str *map_buffer, char **map)
{
	int		i;
	int		j;
	int		col;

	col = ft_strlen(map_buffer->content);
	i = 0;
	while (map_buffer)
	{
		j = 0;
		map[i] = malloc(sizeof(char) * col + 1);
		while (map_buffer->content[j])
		{
			if (map_buffer->content[j] == PLAYER)
				set_pos(&config->player_pos, i, j);
			map[i][j] = map_buffer->content[j];
			j++;
		}
		map[i][j] = '\0';
		i++;
		map_buffer = map_buffer->next;
	}
}

int	parse_map(t_config *config, t_str *map_buffer)
{
	char	**map;

	map = NULL;
	config->columns = check_top_bottom_borders(map_buffer);
	config->rows = check_side_borders(map_buffer);
	if (config->columns <= 2 || config->rows <= 2
		|| !check_valid_map(config, map_buffer))
		return (0);
	map = malloc(sizeof(map) * config->rows + 1);
	if (!map)
		return (0);
	copy_map(config, map_buffer, map);
	config->map = map;
	return (1);
}
