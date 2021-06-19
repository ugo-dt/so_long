/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:50:25 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/15 17:07:58 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static int	count_columns(const char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '1')
			j++;
		else
			return (0);
		i++;
	}
	return (j);
}

int	check_top_bottom_borders(t_str *map_buf)
{
	int		first_line;
	int		last_line;
	t_str	*last;

	if (!map_buf)
		return (0);
	first_line = count_columns(map_buf->content);
	last = t_str_last(map_buf);
	if (last)
		last_line = count_columns(last->content);
	else
		last_line = 0;
	if (first_line == last_line)
		return (first_line);
	return (0);
}

int	check_side_borders(t_str *map_buf)
{
	int		i;
	int		len;

	if (!map_buf)
		return (0);
	i = 0;
	while (map_buf)
	{
		len = ft_strlen(map_buf->content) - 1;
		if (len <= 1 || map_buf->content[0] != '1'
			|| map_buf->content[len] != '1')
			return (0);
		map_buf = map_buf->next;
		i++;
	}
	return (i);
}

int	check_valid_map(t_config *config, t_str *map_buf)
{
	int		i;
	int		columns;

	while (map_buf)
	{
		i = 0;
		columns = 0;
		while (map_buf->content[i])
		{
			columns++;
			if (!char_in_str(map_buf->content[i], MAP_CHARACTERS))
				return (0);
			i++;
		}
		if (columns != config->columns)
			return (0);
		map_buf = map_buf->next;
	}
	return (1);
}
