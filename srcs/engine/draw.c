/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 21:01:57 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/20 11:50:11 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_pixel(t_window *w, t_pos *pos, int color)
{
	if (pos->x >= 0 && pos->x < w->size.x && pos->y >= 0 && pos->y < w->size.y)
	{
		*(int *)(w->screen.addr + (4 * (int)w->size.x * (int)pos->y)
				+ ((int)pos->x * 4)) = color;
	}
}

int	draw_rectangle(t_window *window, t_pos *p1, t_pos *p2, int color)
{
	int		i;
	int		j;
	t_pos	pos;

	restrain_pos(p1, &window->size);
	restrain_pos(p2, &window->size);
	i = p1->y;
	while (i < p2->y)
	{
		pos.y = i;
		j = p1->x;
		while (j < p2->x)
		{
			pos.x = j++;
			draw_pixel(window, &pos, color);
		}
		i++;
	}
	return (1);
}
