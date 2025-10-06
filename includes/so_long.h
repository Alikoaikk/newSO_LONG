/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 20:05:50 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/27 12:57:43 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "mlx.h"
# include <fcntl.h>
// # include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 120
# define KEY_ESC 65307

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*file_name;
	int		map_width;
	int		map_height;
	void	*img_wall;
	void	*img_floor;
	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_player;
	void	*img_col[3];
	void	*img_exit_closed;
	void	*img_exopen;
	void	*temp;
	int		player_x;
	int		player_y;
	int		collect_all;
	int		collectibles_collected;
	char	**copy;
	int		coins;
	int		exit_found;
	int		mouvments_counter ;
}			t_game;

void		error_exit(char **map, char *msg);
void		draw_map(t_game *game);
size_t		ft_strlen(const char *str);
int			handle_keypress(int keycode, t_game *game);
void		load_sprites_cop(t_game *game);
void		load_sprites_obj(t_game *game);
void		load_player_sprites(t_game *game);
void		free_map(char **map);
int			count_lines(char *file);
void		*ft_memset(void *b, int c, unsigned int len);
void		render_window(t_game *game);
void		render_special_tile(t_game *game, char tile, int x, int y);
void		free_sprites(t_game *game);
int			get_map_height(char **map);
void		player_position(char **map, int lines, int *x, int *y);
int			get_map_width(char **map);
void		render_tile(t_game *game, char tile, int x, int y);
void		move_player(t_game *game, int dx, int dy, void *sprite);
void		check_map_duplicates(t_game *game);
void		dfs(t_game *game, int x, int y);
int			flood_fill(t_game *game);
void		validate_path(t_game *game);
void		update_player_position(t_game *game, int new_x, int new_y);
void		destroy_game(t_game *game);
void		check_characters(t_game *game, int lines);
void		check_rectangular(t_game *game, int lines);
void		read_and_parse_map(char *file, int *lines, t_game *window);
void		fill_map(char **map, int lines, int fd);
void		check_walls(char **map, int lines);
void		free_copy(char **copy);
int			handle_window_close(void *param);
void		destroy_collectibles(t_game *game);
void		load_sprites_cop(t_game *game);
void		load_sprites_obj(t_game *game);
void		free_sprites(t_game *game);
void		init_player_and_collectibles(t_game *game);
char		*ft_itoa(int n);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
