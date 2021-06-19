/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:41:36 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/05/29 15:29:56 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	size_t	len;
	char	*d;

	len = ft_strlen(s) + 1;
	d = malloc(sizeof(char) * len);
	if (!d)
		return (NULL);
	return (ft_memcpy(d, s, len));
}
