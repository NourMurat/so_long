/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:55:50 by numussan          #+#    #+#             */
/*   Updated: 2022/09/13 14:24:53 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flag1_steps(t_game *game, int next_x, int next_y)
{
	if (game->map[next_y][next_x] == '0')
	{
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = 'E';
	}
	if (game->map[next_y][next_x] == 'C')
	{
		game->collectible_item--;
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = 'E';
	}
	game->flag = 2;
}

void	ft_flag0_steps(t_game *game, int next_x, int next_y)
{
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
	}
}

void	ft_next_step(t_game *game, int x, int y)
{
	int	next_x;
	int	next_y;

	next_x = game->ppx + x;
	next_y = game->ppy + y;
	if (game->map[next_y][next_x] == '1')
		return ;
	if (game->flag == 0)
		ft_flag0_steps(game, next_x, next_y);
	if (game->flag == 1)
		ft_flag1_steps(game, next_x, next_y);
	ft_met_exit(game, next_x, next_y);
	ft_render_move(game, next_x, next_y);
	ft_printf("step %d\n", ++(game->steps));
}

int	ft_player_movement(int key, t_game *game)
{
	if (key == 13)
		ft_next_step(game, 0, -1);
	if (key == 1)
		ft_next_step(game, 0, 1);
	if (key == 0)
		ft_next_step(game, -1, 0);
	if (key == 2)
		ft_next_step(game, 1, 0);
	if (key == 53)
		ft_close_window(game);
	return (0);
}
