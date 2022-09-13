/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:30:40 by numussan          #+#    #+#             */
/*   Updated: 2022/09/13 20:12:46 by numussan         ###   ########.fr       */
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

int	ft_check_path_to_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	if (game->hash_map[y][x] == '1')
		return (0);
	return (1);
}

void	ft_reach_exit(t_game *game, int x, int y)
{
	game->hash_map[y][x] = '1';
	int i = 0;
	int	j = 0;
	while (i < game->h)
	{
		j = 0;
		while (j < game->w)
		{
			printf("%c", game->hash_map[i][j]);
			j++;	
		}
		printf("\n");
		i++;
	}
	printf("\n\n");
	if (game->map[y][x] == 'E')
		game->is_exit = 1;
	if (game->map[y][x] == 'C')
		game->av_coins++;
	if (ft_check_path_to_exit(game, x, y-1) == 1)
		ft_reach_exit(game, x, y-1);
	if (ft_check_path_to_exit(game, x+1, y) == 1)
		ft_reach_exit(game, x+1, y);
	if (ft_check_path_to_exit(game, x, y+1) == 1)
		ft_reach_exit(game, x, y+1);
	if (ft_check_path_to_exit(game, x-1, y) == 1)
		ft_reach_exit(game, x-1, y);
}

void	ft_valid_path_to_exit(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			game->hash_map[y][x] = '0';
			x++;
		}
		y++;
	}
	x = game->ppx;
	y = game->ppy;
	ft_reach_exit(game, x, y);
	if (game->is_exit != 1 || game->av_coins != game->collectible_item)
		ft_error_map(game, "Map not valid!");
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

	game.steps = 0;
	game.ppx = 0;
	game.ppy = 0;
	game.flag = 0;
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
