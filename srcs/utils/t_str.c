/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_str.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:02:33 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 21:07:46 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	t_str_size(t_str *str)
{
	int	i;

	i = 0;
	while (str)
	{
		str = str->next;
		i++;
	}
	return (i);
}

t_str	*t_str_add_back(t_str **str, char *content)
{
	t_str	*first;
	t_str	*new;

	if (!content)
		return (NULL);
	new = malloc(sizeof(t_str));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (!*str)
		*str = new;
	else
	{
		first = *str;
		while ((*str)->next)
			*str = (*str)->next;
		(*str)->next = new;
		*str = first;
	}
	return (new);
}

t_str	*t_str_last(t_str *str)
{
	if (!str)
		return (NULL);
	while (str->next)
		str = str->next;
	return (str);
}

int	t_str_clear(t_str **list)
{
	t_str	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->content);
		free(*list);
		(*list) = tmp;
	}
	return (0);
}

t_str	*t_str_split(const char *str, const char sep)
{
	int		i;
	int		start;
	t_str	*dest;

	i = 0;
	start = 0;
	dest = NULL;
	while (str[i])
	{
		if (str[i] == sep)
		{
			if (i - start > 0
				&& !t_str_add_back(
					&dest, ft_substr((char *)str, start, i - start)))
				return ((void *)((unsigned long)(t_str_clear(&dest))));
			i++;
			start = i;
		}
		else
			i++;
	}
	if (i - start > 0
		&& !t_str_add_back(&dest, ft_substr((char *)str, start, i - start)))
		return ((void *)((unsigned long)(t_str_clear(&dest))));
	return (dest);
}
