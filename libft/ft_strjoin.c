/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:31:22 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/05/29 15:36:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	char			*d;

	if (!s1 || !s2)
		return (NULL);
	d = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (*s1)
		d[i++] = *s1++;
	while (*s2)
		d[i++] = *s2++;
	d[i] = '\0';
	return (d);
}
