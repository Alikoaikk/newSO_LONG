/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 22:48:11 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/26 19:46:58 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	close_window(t_game *game)
{
	mlx_hook(game->win, 17, 0, handle_window_close, game);
}

int	handle_window_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	destroy_game(game);
	exit(0);
	return (0);
}

void	render_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		write(1, "failed to initialize mlx\n", 26);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
		write(1, "failed to create window\n", 25);
	close_window(game);
}

static void	render_exit_tile(t_game *game, int px, int py)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor, px, py);
	if (game->collectibles_collected == game->collect_all)
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_closed, px,
			py);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_closed, px,
			py);
}

void	render_special_tile(t_game *game, char tile, int x, int y)
{
	int	px;
	int	py;
	int	i;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	if (tile == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, px, py);
	}
	else if (tile == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, px, py);
		i = (x + y) % 3;
		mlx_put_image_to_window(game->mlx, game->win, game->img_col[i], px, py);
	}
	else if (tile == 'E')
	{
		render_exit_tile(game, px, py);
	}
}
