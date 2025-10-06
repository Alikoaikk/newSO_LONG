/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:16:08 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/26 20:55:11 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, char tile, int x, int y)
{
	int	px;
	int	py;

	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, px, py);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, px, py);
	else if (tile == 'P' || tile == 'C' || tile == 'E')
		render_special_tile(game, tile, x, y);
	else
	{
		write(2, "Error: invalid character tile in map\n", 37);
		destroy_game(game);
		exit(1);
	}
}

void	draw_map(t_game *game)
{
	int	y ;
	int	x ;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, game->map[y][x], x, y);
			x++;
		}
		y++;
	}
}
