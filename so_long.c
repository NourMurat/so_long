/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:30:40 by numussan          #+#    #+#             */
/*   Updated: 2022/09/13 06:32:10 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_close_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_error_map(game, "Good bye!");
	exit(0);
}

// void	ft_check_way(t_game game, int ppx, int ppy)
// {
// 	HM[ppx][ppy] = 1;
	
// }

void	ft_error_map(t_game *game, char *s)
{
	int i;

	i = 0;
	ft_printf("%s\n", s);
	while(game->map[i] != NULL)
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

	game.steps = 0;
	game.x = 0;
	game.y = 0;
	if (argc != 2)
		ft_error("Error! Add the map or check the start command!\n");
	ft_parsing(&game, argv[1]);
	// ft_check_way(&game, &game.x, &game.y);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (0);
	ft_render_map(&game);
	mlx_key_hook(game.mlx_win, ft_player_movement, &game);
	mlx_hook(game.mlx_win, 17, 0, ft_close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
