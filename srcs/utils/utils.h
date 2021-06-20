/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 16:07:12 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/20 11:50:26 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

# ifdef LINUX
#  include "../../libft/libft.h"
# else
#  include "libft.h"
# endif

typedef struct s_str
{
	char			*content;
	struct s_str	*next;
}t_str;

typedef struct s_pos
{
	int		x;
	int		y;
}t_pos;

void	set_pos(t_pos *pos, double x, double y);
void	copy_pos(t_pos *pos_to, t_pos *pos_from);
void	pos_in_window(t_pos *pos);
void	restrain_pos(t_pos *pos, t_pos *win_size);

int		char_in_str(char c, const char *s);
int		check_extension(const char *s, const char *end);

int		t_str_size(t_str *str);
int		t_str_clear(t_str **list);
t_str	*t_str_add_back(t_str **str, char *content);
t_str	*t_str_last(t_str *str);
t_str	*t_str_split(const char *str, const char sep);

#endif
