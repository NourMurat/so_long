/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:21:47 by numussan          #+#    #+#             */
/*   Updated: 2022/09/16 17:58:07 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_if_flag1_flag2_render(t_game *game, int next_x, int next_y)
{
	if (game->flag == 1)
	{
		ft_render_image(game, EXIT, next_x, next_y);
		ft_render_image(game, PLAYER2, next_x, next_y);
		ft_render_image(game, GROUND, game->ppx, game->ppy);
		game->ppx = next_x;
		game->ppy = next_y;
	}
	if (game->flag == 2)
	{
		ft_render_image(game, GROUND, next_x, next_y);
		ft_render_image(game, PLAYER2, next_x, next_y);
		ft_render_image(game, EXIT, game->ppx, game->ppy);
		game->ppx = next_x;
		game->ppy = next_y;
		game->flag = 0;
	}
}

void	ft_render_move(t_game *game, int next_x, int next_y)
{
	if (game->flag == 0)
	{
		ft_render_image(game, GROUND, next_x, next_y);
		ft_render_image(game, PLAYER2, next_x, next_y);
		ft_render_image(game, GROUND, game->ppx, game->ppy);
		game->ppx = next_x;
		game->ppy = next_y;
	}
	ft_if_flag1_flag2_render(game, next_x, next_y);
}

void	ft_met_exit(t_game *game, int next_x, int next_y)
{
	if (game->map[next_y][next_x] == 'E' && game->collectible_item == 0)
		ft_close_window(game);
	if (game->map[next_y][next_x] == 'E' \
		&& game->collectible_item > 0 && game->flag == 0)
	{
		game->flag = 1;
		game->map[next_y][next_x] = 'P';
		game->map[game->ppy][game->ppx] = '0';
	}
}
