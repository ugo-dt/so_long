/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:11:25 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/07/05 19:28:07 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_and_exit(t_game *game, char *s)
{
	write(1, "Error\n", 7);
	if (s)
		write(STDERR_FILENO, s, ft_strlen(s));
	exit_game(game, EXIT_FAILURE);
}

static void	check_arguments(t_game *game, int argc, const char **argv)
{
	int	fd;

	if (argc < 2)
		clear_and_exit(game, "So_long: no map specified\n");
	else if (argc > 2)
		clear_and_exit(game, "So_long: expected 1 argument\n");
	else if (!check_extension(argv[1], ".ber"))
		clear_and_exit(game, "So_long: expected .ber file\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		clear_and_exit(game, "So_long: could not read file\n");
	if (!parse_config(&game->config, fd))
		clear_and_exit(game, "So_long: invalid map\n");
	if (!find_collectibles(&game->config) || !find_exits(&game->config))
		clear_and_exit(game, "Please try again\n");
	if (game->config.nb_enemies > 0)
		if (!find_enemies(&game->config))
			clear_and_exit(game, "Please try again\n");
	if (game->config.to_collect < 1 || game->config.nb_exits < 1
		|| game->config.player_pos.x == -1 || game->config.player_pos.y == -1)
		clear_and_exit(game, "So_long: map elements are missing\n");
}

int	main(int argc, const char **argv)
{
	t_game	game;

	init_config(&game.config);
	init_game(&game);
	game.window.window = NULL;
	game.window.screen.img = NULL;
	check_arguments(&game, argc, argv);
	launch_game(&game);
	return (0);
}
