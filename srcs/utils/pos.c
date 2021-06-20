/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:24:33 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/20 11:50:16 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

void	copy_pos(t_pos *pos_to, t_pos *pos_from)
{
	pos_to->x = pos_from->x;
	pos_to->y = pos_from->y;
}

void	pos_in_window(t_pos *pos)
{
	while (pos->x >= 9)
		pos->x -= 9;
	while (pos->y >= 14)
		pos->y -= 14;
}

void	restrain_pos(t_pos *pos, t_pos *win_size)
{
	if (pos->x < 0)
		pos->x = 0;
	if (pos->x > win_size->x)
		pos->x = win_size->x - 1;
	if (pos->y < 0)
		pos->y = 0;
	if (pos->y > win_size->y)
		pos->y = win_size->y - 1;
}