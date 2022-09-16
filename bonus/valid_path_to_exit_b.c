/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_to_exit_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:10:06 by numussan          #+#    #+#             */
/*   Updated: 2022/09/16 17:45:35 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_path_to_exit(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'D')
		return (0);
	if (game->hash_map[y][x] == '1')
		return (0);
	return (1);
}

void	ft_scan_map(t_game *game, int x, int y)
{
	game->hash_map[y][x] = '1';
	if (game->map[y][x] == 'E')
		game->find_e = 1;
	if (game->map[y][x] == 'C')
		game->find_c++;
	if (ft_check_path_to_exit(game, x, y - 1) == 1)
		ft_scan_map(game, x, y - 1);
	if (ft_check_path_to_exit(game, x + 1, y) == 1)
		ft_scan_map(game, x + 1, y);
	if (ft_check_path_to_exit(game, x, y + 1) == 1)
		ft_scan_map(game, x, y + 1);
	if (ft_check_path_to_exit(game, x - 1, y) == 1)
		ft_scan_map(game, x - 1, y);
}

void	ft_valid_path_to_exit(t_game *game)
{
	int	x;
	int	y;

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
	ft_scan_map(game, x, y);
	if (game->find_e != 1 || game->find_c != game->collectible_item)
		ft_error_map(game, "Map not valid!");
}
