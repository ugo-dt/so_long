/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:03:17 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/19 16:41:24 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "engine/engine.h"
# include "utils/utils.h"
# include "config/config.h"

void	init_game(t_game *game);
int		launch_game(t_game *game);
int		exit_game(t_game *game, int status);

int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
int		exit_hook(t_game *game);

void	clear_and_exit(t_game *game, char *s);
int		main_loop(t_game *game);

#endif

/*
**	SO_LONG_H
*/
