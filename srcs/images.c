/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:09:00 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/26 20:52:25 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites_cop(t_game *game)
{
	int	width;
	int	height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm",
			&width, &height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm",
			&width, &height);
	game->img_exit_closed = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm",
			&width, &height);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx,
			"sprites/harryFront.xpm", &width, &height);
	game->img_player = game->img_player_down;
	if (!game->img_wall || !game->img_floor || !game->img_exit_closed
		|| !game->img_player)
	{
		write(1, "Failed to load one or more core sprites\n", 41);
		exit(1);
	}
}

void	load_sprites_obj(t_game *game)
{
	int	width;
	int	height;

	game->img_col[0] = mlx_xpm_file_to_image(game->mlx, "sprites/horcrox1.xpm",
			&width, &height);
	game->img_col[1] = mlx_xpm_file_to_image(game->mlx, "sprites/horcrox2.xpm",
			&width, &height);
	game->img_col[2] = mlx_xpm_file_to_image(game->mlx, "sprites/horcrox3.xpm",
			&width, &height);
	game->img_exopen = mlx_xpm_file_to_image(game->mlx, "sprites/exitOpen.xpm",
			&width, &height);
	if (!game->img_wall || !game->img_floor || !game->img_player
		|| !game->img_col[0] || !game->img_col[1] || !game->img_col[2]
		|| !game->img_exit_closed || !game->img_exopen)
		write(1, "Failed to load one or more sprites\n", 36);
}

void	load_player_sprites(t_game *game)
{
	int	width;
	int	height;

	game->img_player_up = mlx_xpm_file_to_image(game->mlx,
			"sprites/harryBack.xpm", &width, &height);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"sprites/harryLeft.xpm", &width, &height);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"sprites/harryRight.xpm", &width, &height);
	if (!game->img_player_down || !game->img_player_up || !game->img_player_left
		|| !game->img_player_right)
		write(1, "Failed to load one or more player sprites\n", 43);
}

void	free_sprites(t_game *game)
{
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player_down)
		mlx_destroy_image(game->mlx, game->img_player_down);
	if (game->img_player_right)
		mlx_destroy_image(game->mlx, game->img_player_right);
	if (game->img_player_left)
		mlx_destroy_image(game->mlx, game->img_player_left);
	if (game->img_player_up)
		mlx_destroy_image(game->mlx, game->img_player_up);
	destroy_collectibles(game);
	if (game->img_exit_closed)
		mlx_destroy_image(game->mlx, game->img_exit_closed);
	if (game->temp)
		mlx_destroy_image(game->mlx, game->temp);
	if (game->img_exopen)
		mlx_destroy_image(game->mlx, game->img_exopen);
}

void	destroy_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->img_col[i])
			mlx_destroy_image(game->mlx, game->img_col[i]);
		i++;
	}
}
