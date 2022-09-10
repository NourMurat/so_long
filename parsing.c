/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 03:45:47 by numussan          #+#    #+#             */
/*   Updated: 2022/09/10 13:23:03 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// void	ft_check_simbols(t_game *game)
// {
// 	int		i;
// 	int		k;
// 	char	ch;

// 	i = 0;
// 	while (game->map[i])
// 	{
// 		k = 0;
// 		while (game->map[i][k])
// 		{
// 			ch = game->map[i][k];
// 			if (ch != 'P' && ch != 'C' && ch != 'E' && ch != '0' && ch != '1')
// 				ft_error_map(game, "Error! Invalid simbol(s) on the map!");
// 			k++;
// 		}
// 		i++;
// 	}
// }

// int	ft_count_elements(t_game *game, char c)
// {
// 	int	y;
// 	int	x;
// 	int	num;

// 	y = 0;
// 	num = 0;
// 	while (game->map[y])
// 	{
// 		x = 0;
// 		while (game->map[y][x])
// 		{
// 			if (game->map[y][x] == c)
// 				num++;
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (num);
// }

// void	ft_check_number_elements(t_game *game)
// {
// 	if (ft_count_elements(game, 'P') != 1)
// 		ft_error_map(game, "Error! There must be only 1 Player on the map!");
// 	if ((game->collectible_item = ft_count_elements(game, 'C')) < 1)
// 		ft_error_map(game, "Error! There must be 1 or more Coins on the map!");
// 	if (ft_count_elements(game, 'E') < 1)
// 		ft_error_map(game, "Error! There must be 1 or more Exits on the map!");
// }

// void	ft_check_boundaries(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (game->map[0][i])
// 	{
// 		if (game->map[0][i] != '1')
// 			ft_error_map(game, "Error! The Upper boundary isn`t correct!");
// 		if (game->map[game->height - 1][i] != '1')
// 			ft_error_map(game, "Error! The Lower boundary isn`t correct!");
// 		i++;
// 	}
// 	i = 1;
// 	while (game->map[i])
// 	{
// 		if (game->map[i][0] != '1')
// 			ft_error_map(game, "Error! The Left boundary isn`t correct!");
// 		if (game->map[i][game->width - 1] != '1')
// 			ft_error_map(game, "Error! The Right boundary isn`t correct!");
// 		i++;
// 	}
// }

void	ft_check_map(t_game *game, char *read_map)
{
	int	i;

	i = 0;
	if (read_map[0] == '\n' || read_map[(ft_strlen(read_map) - 1)] == '\n')
		ft_error("Error! Map not valid!");
	game->map = ft_split(read_map, '\n');
	game->width = ft_strlen(game->map[0]);
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != game->width)
			ft_error_map(game, "Error! Map not valid!");
	}
	game->height = i;
}

char	*ft_read_map(char *file)
{
	int		fd;
	char	*read_map;
	char	*temp_map;

	read_map = "";
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Error! Impossible to read the map!");
	temp_map = get_next_line(fd);
	if (temp_map == NULL)
		ft_error_tempmap(temp_map, "Error! Impossible to read the map!");
	while (temp_map != NULL)
	{
		if (temp_map != NULL && temp_map[0] == '\n')
			ft_error_tempmap(temp_map, "Error! Impossible to read the map!");
		read_map = ft_strjoin(read_map, temp_map);
		temp_map = get_next_line(fd);
	}
	if (temp_map != NULL)
		free(temp_map);
	close (fd);
	// ft_printf("%s\n", read_map);
	return (read_map);
}

void	ft_check_file_extension(char *file)
{
	char	*extension;
	char	*right_extension;

	right_extension = ".ber";
	extension = "";
	extension = ft_strrchr(file, 46);
	if (ft_strncmp(right_extension, extension, ft_strlen(right_extension)) != 0)
		ft_error("Error! Extension not valid\n");
}

void	ft_parsing(t_game *game, char *file)
{
	ft_check_file_extension(file);
	ft_check_map(game, ft_read_map(file));
	// ft_check_boundaries(game);
	// ft_check_number_elements(game);
	// ft_check_simbols(game);
}
