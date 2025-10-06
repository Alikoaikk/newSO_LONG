/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:38:59 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/27 13:06:06 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		destroy_game(game);
		exit(1);
	}
	else if (keycode == 'w')
		move_player(game, 0, -1, game->img_player_up);
	else if (keycode == 's')
		move_player(game, 0, 1, game->img_player_down);
	else if (keycode == 'a')
		move_player(game, -1, 0, game->img_player_left);
	else if (keycode == 'd')
		move_player(game, 1, 0, game->img_player_right);
	return (0);
}

void	update_player_position(t_game *game, int new_x, int new_y)
{
	char	*moves_str;
	char	*display;

	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->mouvments_counter++;
	draw_map(game);
	moves_str = ft_itoa(game->mouvments_counter);
	display = ft_strjoin("Movements: ", moves_str);
	mlx_string_put(game->mlx, game->win, game->map_width * TILE_SIZE - 150, 20,
		0xFFFFFF, display);
	ft_printf("%s\n", display);
	free(moves_str);
	free(display);
}

static void	process_tile_effect(t_game *game, int x, int y, char tile)
{
	if (tile == 'C')
	{
		game->map[y][x] = '0';
		game->collectibles_collected++;
		if (game->collectibles_collected == game->collect_all)
		{
			game->temp = game->img_exit_closed;
			game->img_exit_closed = game->img_exopen;
			game->img_exopen = NULL;
		}
	}
	else if (tile == 'E')
	{
		if (game->collect_all
			&& game->collectibles_collected == game->collect_all)
		{
			ft_printf("Movements: %d\n", game->mouvments_counter + 1);
			write(1, "---We-have-a-WINNER---!\n", 25);
			destroy_game(game);
			exit(1);
		}
		else
			return ;
	}
	update_player_position(game, x, y);
}

void	handle_tile_interaction(t_game *game, int x, int y, void *sprite)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '1')
		return ;
	game->img_player = sprite;
	process_tile_effect(game, x, y, tile);
}

void	move_player(t_game *game, int dx, int dy, void *sprite)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	handle_tile_interaction(game, new_x, new_y, sprite);
}
