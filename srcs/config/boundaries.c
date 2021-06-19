/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:19:32 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/17 10:08:57 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

static t_region	*fill_region(t_config *config, t_region *r, int row, int col)
{
	int		i;
	int		j;
	int		i_col;
	int		i_row;

	i_row = row;
	i = 0;
	while (i < 9 && i_row < config->rows)
	{
		i_col = col;
		j = 0;
		while (j < 14 && i_col < config->columns)
		{
			r->region[i][j] = config->map[i_row][i_col];
			r->size++;
			i_col++;
			j++;
		}
		r->region[i][j] = '\0';
		i_row++;
		i++;
	}
	r->rows = i;
	r->cols = j;
	return (r);
}

static t_region	*create_region(t_config *config, int row_start, int col_start)
{
	t_region	*region;

	region = malloc(sizeof(t_region));
	if (!region)
		return (NULL);
	region->size = 0;
	region->row_start = row_start;
	region->col_start = col_start;
	return (fill_region(config, region, row_start, col_start));
}

static int	count_regions(t_config *config)
{
	int		i;
	int		j;
	int		nb;

	config->map_size = config->columns * config->rows;
	if (config->map_size <= 126)
		return (1);
	nb = 0;
	i = 0;
	while (i < config->rows)
	{
		j = 0;
		while (j < config->columns)
		{
			nb++;
			j += 14;
		}
		i += 9;
	}
	return (nb);
}

void	define_regions(t_config *config)
{
	int		i;
	int		j;
	int		k;

	config->nb_regions = count_regions(config);
	config->regions = NULL;
	config->regions = malloc(sizeof(config->regions) * config->nb_regions);
	if (!config->regions)
		return ;
	i = 0;
	k = 0;
	while (i < config->rows)
	{
		j = 0;
		while (j < config->columns && k < config->nb_regions)
		{
			config->regions[k++] = create_region(config, i, j);
			j += 14;
		}
		i += 9;
	}
}
