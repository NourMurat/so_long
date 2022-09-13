/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 06:47:37 by numussan          #+#    #+#             */
/*   Updated: 2022/09/13 14:40:40 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_image(t_game *game, char *path, int x, int y)
{
	int	size;

	size = 100;
	x = x * size;
	y = y * size;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &game->w, &game->h);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x, y);
	mlx_destroy_image(game->mlx, game->img);
}

void	put_image_and_find_player(t_game *game, char c, int x, int y)
{
	if (c == '0')
		ft_render_image(game, GROUND, x, y);
	if (c == '1')
	{
		ft_render_image(game, GROUND, x, y);
		ft_render_image(game, WALL, x, y);
	}
	if (c == 'P')
	{
		game->ppx = x;
		game->ppy = y;
		ft_render_image(game, GROUND, x, y);
		ft_render_image(game, PLAYER1, x, y);
	}
	if (c == 'C')
	{
		ft_render_image(game, GROUND, x, y);
		ft_render_image(game, KEY, x, y);
	}
	if (c == 'E')
	{
		ft_render_image(game, GROUND, x, y);
		ft_render_image(game, EXIT, x, y);
	}
}

void	ft_render_window(t_game *game)
{
	int	ww;
	int	wh;

	ww = game->w * 100;
	wh = game->h * 100;
	game->mlx_win = mlx_new_window(game->mlx, ww, wh, "SO_LONG");
}

void	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	ft_render_window(game);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_image_and_find_player(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
	ft_printf("Player position - %d %d\n", game->ppx, game->ppy);
}
