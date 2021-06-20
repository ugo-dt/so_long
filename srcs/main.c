/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:11:25 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/06/20 10:59:41 by ugdaniel         ###   ########.fr       */
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

static int	find_exits(t_config *config)
{
	int		i;
	int		j;
	int		k;

	config->exits = malloc(sizeof(t_element) * config->nb_exits);
	if (!config->exits)
		return (0);
	i = 0;
	j = 0;
	while (j < config->rows)
	{
		k = 0;
		while (k < config->columns)
		{
			if (config->map[j][k] == MAP_EXIT && i < config->nb_exits)
			{
				set_pos(&config->exits[i].pos, j, k);
				config->exits->number = i;
				i++;
			}
			k++;
		}
		j++;
	}
	return (1);
}

static int	find_collectibles(t_config *config)
{
	int		i;
	int		j;
	int		k;

	config->collectibles = malloc(sizeof(t_element) * config->to_collect);
	if (!config->collectibles)
		return (0);
	i = 0;
	j = 0;
	while (j < config->rows)
	{
		k = 0;
		while (k < config->columns)
		{
			if (config->map[j][k] == COLLECTIBLE && i < config->to_collect)
			{
				set_pos(&config->collectibles[i].pos, j, k);
				config->collectibles->number = i;
				i++;
			}
			k++;
		}
		j++;
	}
	return (1);
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
	if (!find_collectibles(&game->config))
		clear_and_exit(game, "Please try again\n");
	if (!find_exits(&game->config))
		clear_and_exit(game, "Please try again\n");
	if (game->config.to_collect < 1 || game->config.player_pos.x == -1
		|| game->config.player_pos.y == -1)
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
