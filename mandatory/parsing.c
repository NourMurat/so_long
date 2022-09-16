/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 03:45:47 by numussan          #+#    #+#             */
/*   Updated: 2022/09/16 19:15:49 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_check_map(t_game *game, char *read_map)
{
	int	i;

	i = 0;
	if (read_map[0] == '\n' || read_map[(ft_strlen(read_map) - 1)] == '\n')
		ft_error("Error! Map not valid!");
	game->map = ft_split(read_map, '\n');
	game->w = ft_strlen(game->map[0]);
	while (game->map[++i])
	{
		if (ft_strlen(game->map[i]) != game->w)
			ft_error_map(game, "Error! Map not valid!");
	}
	game->h = i;
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
		ft_error_tempmap(temp_map, "Error! Map not valid!");
	while (temp_map != NULL)
	{
		if (temp_map != NULL && temp_map[0] == '\n')
			ft_error_tempmap(temp_map, "Error! Map not valid!");
		read_map = ft_strjoin(read_map, temp_map);
		temp_map = get_next_line(fd);
	}
	if (temp_map != NULL)
		free(temp_map);
	close (fd);
	return (read_map);
}

void	ft_check_file_extension(char *file)
{
	char	*extension;
	char	*right_extension;

	right_extension = ".ber";
	extension = "";
	extension = ft_strrchr(file, 46);
	if (extension == NULL)
		ft_error("Error! Extension not valid\n");
	if (ft_strncmp(right_extension, extension, ft_strlen(right_extension)) != 0)
		ft_error("Error! Extension not valid\n");
}

void	ft_parsing(t_game *game, char *file)
{
	ft_check_file_extension(file);
	ft_check_map(game, ft_read_map(file));
	ft_check_boundaries(game);
	ft_check_number_elements(game);
	ft_check_simbols(game);
}
