/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:51:28 by numussan          #+#    #+#             */
/*   Updated: 2022/09/13 06:32:00 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

#define GROUND	"img/ground.xpm"
#define WALL	"img/wall.xpm"
#define PLAYER1	"img/player1.xpm"
#define PLAYER2	"img/player2.xpm"
#define KEY		"img/key.xpm"
#define EXIT	"img/exit.xpm"

typedef struct s_game
{
	int		x;
	int		y;
	char	**map;
	int		width;
	int		height;
	int		collectible_item;
	int		steps;
	void	*mlx;
	void	*mlx_win;
	void	*img;
}	t_game;

// typedef struct s_check_way
// {
// 	int	is_exit;
// 	int av_coins;
// } t_check_way;

void	ft_error(char *string);
void	ft_error_tempmap(char *tempmap, char *string);
void	ft_error_map(t_game *game, char *string);

char	*get_next_line(int fd); 
int		gnl_strlen(char *s);
char	*gnl_strchr(char *s);
char	*gnl_strdup(char	*remainder);
char	*gnl_strjoin(char *old, char *new);

void	ft_parsing(t_game *game, char *file);
void	ft_check_file_extension(char *file);
char	*ft_read_map(char *file);
void	ft_check_map(t_game *game, char *read_map);
void	ft_check_boundaries(t_game *game);
void	ft_check_number_elements(t_game *game);
int		ft_count_elements(t_game *game, char c);
void	ft_check_simbols(t_game *game);

void	ft_render_map(t_game *game);
void	ft_render_window(t_game *game);
void	ft_put_image_and_find_player(t_game *game, char c, int x, int y);
void	ft_render_image(t_game *game, char *path, int x, int y);

int		ft_player_movement(int key, t_game *game);
void	ft_next_step(t_game *game, int x, int y);
void	ft_render_move(t_game *game, int next_x, int next_y);
int		ft_close_window(t_game *game);

#endif