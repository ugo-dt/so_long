/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:24:33 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 22:10:58 by ugdaniel         ###   ########.fr       */
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
