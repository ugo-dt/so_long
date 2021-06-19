/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:40:12 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/18 12:45:58 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

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
