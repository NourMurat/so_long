/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:30:40 by numussan          #+#    #+#             */
/*   Updated: 2022/09/15 22:17:38 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_error_map(game, "<<<<<<<<<< SEE YOU !!! >>>>>>>>>>");
	exit(0);
}

void	ft_error_map(t_game *game, char *s)
{
	int	i;

	i = 0;
	ft_printf("%s\n", s);
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit (1);
}

void	ft_error_tempmap(char *tempmap, char *s)
{
	ft_printf("%s\n", s);
	free(tempmap);
	exit (1);
}

void	ft_error(char *s)
{
	ft_printf("%s\n", s);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.w = 0;
	game.h = 0;
	game.collectible_item = 0;
	game.flag = 0;
	game.is_exit = 0;
	game.av_coins = 0;
	game.ppx = 0;
	game.ppy = 0;
	game.steps = 0;
	if (argc != 2)
		ft_error("Error! Add the map or check the start command!\n");
	ft_parsing(&game, argv[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	ft_render_map(&game);
	ft_valid_path_to_exit(&game);
	mlx_key_hook(game.mlx_win, ft_player_movement, &game);
	mlx_hook(game.mlx_win, 17, 0, ft_close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
