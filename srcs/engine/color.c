/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 09:58:23 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 19:00:57 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	get_tex_color(t_texture *tex, t_pos *pos)
{
	if (pos->x >= 0 && pos->x < tex->width
		&& pos->y >= 0 && pos->y < tex->height)
	{
		return (*(int *)(tex->ptr
			+ (4 * tex->width * (int)pos->y)
			+ (4 * (int)pos->x)));
	}
	return (0x0);
}
