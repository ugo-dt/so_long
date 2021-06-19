/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:19:51 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/14 18:51:44 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	char_in_str(char c, const char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (c == s[i])
			return (c);
	return (0);
}

int	check_extension(const char *s, const char *end)
{
	int		s_len;
	int		end_len;

	s_len = ft_strlen((char *)s);
	end_len = ft_strlen((char *)end);
	if (end_len > s_len)
		return (0);
	return (!ft_strncmp(s + s_len - end_len, end, s_len - end_len - 1));
}
