/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:42:28 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/22 18:34:31 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_str(char *str)
{
	char	*dest;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!dest)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		dest[j++] = str[i++];
	dest[j] = '\0';
	free(str);
	return (dest);
}

char	*create_line(char *str)
{
	char	*line;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*str[256];
	int			nb_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	nb_read = 1;
	while (!find_endl(str[fd]) && nb_read != 0)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[nb_read] = '\0';
		str[fd] = strjoin(str[fd], buffer);
	}
	free(buffer);
	*line = create_line(str[fd]);
	str[fd] = save_str(str[fd]);
	return (!(nb_read == 0));
}
