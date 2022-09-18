/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:55:50 by numussan          #+#    #+#             */
/*   Updated: 2022/09/18 16:05:03 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_flag1_steps(t_game *game, int next_x, int next_y)
{
	char	*keys_win;

	keys_win = ft_strjoin
		(ft_itoa(game->collectible_item - 1), " keys left");
	if (game->map[next_y][next_x] == '0')
	{
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = 'E';
		game->flag = 2;
	}
	if (game->map[next_y][next_x] == 'C')
	{
		game->collectible_item--;
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = 'E';
		ft_render_image(game, WALL, 0, 1);
		mlx_string_put(game->mlx, game->mlx_win, 11, 150, 0x310C29, keys_win);
		game->flag = 2;
	}
	if (game->map[next_y][next_x] == 'E')
	{
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = 'E';
		game->flag = 3;
	}
}

void	ft_flag0_steps(t_game *game, int next_x, int next_y)
{
	char	*keys_win;

	keys_win = ft_strjoin
		(ft_itoa(game->collectible_item - 1), " keys left");
	if (game->map[next_y][next_x] == '0')
	{
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = '0';
	}
	if (game->map[next_y][next_x] == 'C')
	{
		game->collectible_item--;
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = '0';
		ft_render_image(game, WALL, 0, 1);
		mlx_string_put(game->mlx, game->mlx_win,
			11, 150, 0x310C29, keys_win);
	}
}

void	ft_next_step(t_game *game, int x, int y)
{
	int		next_x;
	int		next_y;
	char	*steps_in_window;

	next_x = game->ppx + x;
	next_y = game->ppy + y;
	if (game->map[next_y][next_x] == '1')
		return ;
	if (game->map[next_y][next_x] == 'D')
		ft_close_window(game);
	if (game->flag == 0)
		ft_flag0_steps(game, next_x, next_y);
	if (game->flag == 1)
		ft_flag1_steps(game, next_x, next_y);
	ft_met_exit(game, next_x, next_y);
	ft_render_move(game, next_x, next_y);
	++(game->steps);
	steps_in_window = ft_strjoin("Steps: ", ft_itoa(game->steps));
	ft_render_image(game, WALL, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 18, 54, 0x310C29, steps_in_window);
}

int	ft_player_movement(int key, t_game *game)
{
	if (key == 13)
		ft_next_step(game, 0, -1);
	if (key == 2)
		ft_next_step(game, 1, 0);
	if (key == 1)
		ft_next_step(game, 0, 1);
	if (key == 0)
		ft_next_step(game, -1, 0);
	if (key == 53)
		ft_close_window(game);
	return (0);
}
