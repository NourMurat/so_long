/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:51:28 by numussan          #+#    #+#             */
/*   Updated: 2022/09/05 03:12:10 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <fcntl.h>

typedef struct s_game
{
	int		x;
	int		y;
	char	**map;
	int		width;
	int		height;
	int		coins;
	int		steps;
	void	*mlx;
	void	*mlx_win;
	void	*img;
}	t_game;

char	*get_next_line(int fd);
int		gnl_strlen(char *s);
char	*gnl_strchr(char *s);
char	*gnl_strdup(char	*remainder);
char	*gnl_strjoin(char *old, char *new);

void	ft_error(t_game *game, char *string);
void	ft_check_file_extension(t_game *game, char *file);
char	*ft_read_map(t_game *game, char *file);
void	ft_check_map(t_game *game, char *read_map);
void	ft_check_boundaries(t_game *game);
void	ft_find_player(t_game *game);
void	ft_check_number_elements(t_game *game);
int		ft_count_elements(t_game *game, char c);
void	ft_check_simbols(t_game *game);

#endif