/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:50:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 18:43:06 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_flags(t_flags *flags)
{
	if (flags->specs[SPEC_INT])
	{
		flags->specs[SPEC_PTR] = 0;
		flags->flags[FLAG_HASH] = 0;
		flags->flags[FLAG_PLUS] = 0;
		flags->flags[FLAG_SPACE] = 0;
	}
	if (flags->width < 0)
	{
		flags->flags[FLAG_LEFT] = 1;
		flags->width *= -1;
	}
	if (flags->specs[SPEC_HEX])
	{
		flags->specs[SPEC_INT] = 0;
		flags->specs[SPEC_UINT] = 0;
	}
	if (flags->flags[FLAG_MINUS])
		flags->flags[FLAG_ZERO] = 0;
}
