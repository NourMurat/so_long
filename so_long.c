/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:30:40 by numussan          #+#    #+#             */
/*   Updated: 2022/09/05 04:07:29 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(t_game *game)
{
	
	
}

void	ft_create_window(t_game *game)
{
	int	w;
	int	h;

	w = game->width * 100;
	h = game->height * 100;
	game->mlx_win = mlx_new_window(game->mlx, width, height, "SO_LONG");
}

void	ft_check_simbols(t_game *game)
{
	int		i;
	int		k;
	char	ch;

	i = 0;
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k])
		{
			ch = game->map[i][k];
			if (ch != 'P' && ch != 'C' && ch != 'E' && ch != '0' && ch != '1')
				ft_error(game, "Error! Invalid simbol(s) on the map!");
			k++;
		}
		i++;
	}
}

int	ft_count_elements(t_game *game, char c)
{
	int	i;
	int	k;
	int	num;

	i = 0;
	num = 0;
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k])
		{
			if (game->map[i][k] == c)
				num++;
			k++;
		}
		i++;
	}
	return (num);
}

void	ft_check_number_elements(t_game *game)
{
	if (ft_count_elements(game, 'P') != 1)
		ft_error(game, "Error! There must be only 1 Player on the map!");
	if (ft_count_elements(game, 'C') < 1)
		ft_error(game, "Error! There must be 1 or more Coins on the map!");
	if (ft_count_elements(game, 'E') < 1)
		ft_error(game, "Error! There must be 1 or more Exits on the map!");
	if (ft_count_elements(game, '0') < 1)
		ft_error(game, "Error! Map not valid!");
}

void	ft_find_player(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k])
		{
			if (game->map[i][k] == 'P')
			{
				game->x = k;
				game->y = i;
			}
			k++;
		}
		i++;
	}
	// ft_printf("%d %d", game->x, game->y);
}

void	ft_check_boundaries(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			ft_error(game, "Error! The Upper boundary isn`t correct!");
		if (game->map[game->height - 1][i] != '1')
			ft_error(game, "Error! The Lower boundary isn`t correct!");
		i++;
	}
	i = 1;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
			ft_error(game, "Error! The Right boundary isn`t correct!");
		if (game->map[i][game->width - 1] != '1')
			ft_error(game, "Error! The Left boundary isn`t correct!");
		i++;
	}
}

void	ft_check_map(t_game *game, char *read_map)
{
	int	i;

	i = 0;
	game->map = ft_split(read_map, '\n');
	game->width = ft_strlen(game->map[0]);
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != game->width)
			ft_error(game, "Error! Map not valid!");
	}
	game->height = i;
}

char	*ft_read_map(t_game *game, char *file)
{
	int		fd;
	char	*read_map;
	char	*temp_map;

	read_map = "";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error(game, "Error! Impossible to read the map!");
	temp_map = get_next_line(fd);
	while (read_map != NULL)
	{
		if (temp_map == NULL)
			break ;
		read_map = ft_strjoin(read_map, temp_map);
		temp_map = get_next_line(fd);
	}
	if (temp_map != NULL)
	{
		free(temp_map);
		temp_map = NULL;
	}
	close (fd);
	ft_printf("%s\n", read_map);
	return (read_map);
}

void	ft_check_file_extension(t_game *game, char *file)
{
	char	*extension;
	char	*right_extension;

	right_extension = ".ber";
	extension = "";
	extension = ft_strrchr(file, 46);
	if (ft_strncmp(right_extension, extension, ft_strlen(right_extension)) != 0)
		ft_error(game, "Error! Extension not valid\n");
}

void	ft_error(t_game *game, char *s)
{
	ft_printf("%s\n", s);
	free(game);
	game = NULL;
	exit(1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = (malloc(sizeof(t_game)));
	if (!game)
		return (0);
	if (argc != 2)
		ft_error(game, "Error! Add the map or check the start command!\n");
	ft_check_file_extension(game, argv[1]);
	ft_check_map(game, ft_read_map(game, argv[1]));
	ft_check_boundaries(game);
	ft_find_player(game);
	ft_check_number_elements(game);
	ft_check_simbols(game);
	ft_create_window(game);
	ft_create_map(game);
	return (0);
}
