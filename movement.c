/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 08:55:50 by numussan          #+#    #+#             */
/*   Updated: 2022/09/09 08:57:15 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	ft_render_move(t_game *game, int next_x, int next_y)
{
	ft_render_image(game, GROUND, next_x, next_y);
	if ((game->steps % 2) != 0)
		ft_render_image(game, PLAYER1, next_x, next_y);
	else
		ft_render_image(game, PLAYER2, next_x, next_y);
	ft_render_image(game, GROUND, game->x, game->y);
	game->x = next_x;
	game->y = next_y;
}

void	ft_next_step(t_game *game, int x, int y)
{
	int	next_x;
	int	next_y;
	
	next_x = game->x + x;
	next_y = game->y + y;
	if (game->map[next_y][next_x] == '1')
		return ;
	if (game->map[next_y][next_x] == '0')
	{
		game->map[next_y][next_x] = 'P';
		game->map[game->y][game->x] = '0';
	}
	if (game->map[next_y][next_x] == 'C')
	{
		game->collectible_item--;
		game->map[next_y][next_x] = 'P';
		game->map[game->y][game->x] = '0';
	}
	if (game->map[next_y][next_x] == 'E' && game->collectible_item == 0)
		ft_close_window(game);
	if (game->map[next_y][next_x] == 'E' && game->collectible_item > 0)
		return ;
	ft_render_move(game, next_x, next_y);
	ft_printf("step %d\n", ++(game->steps));
}

int		ft_player_movement(int key, t_game *game)
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