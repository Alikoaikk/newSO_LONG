/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:07:09 by akoaik            #+#    #+#             */
/*   Updated: 2025/10/07 00:10:37 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_map(char **map, int lines)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	copy = (char **)malloc((lines + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	while (i < lines)
	{
		copy[i] = (char *)malloc((ft_strlen(map[0]) + 1) * sizeof(char));
		if (!copy[i])
			return (NULL);
		j = 0;
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[lines] = NULL ;
	return (copy);
}

void	dfs(t_game *game, int x, int y)
{
	if (game->copy[y][x] == '1' || game->copy[y][x] == 's')
		return ;
	else if (game->copy[y][x] == 'C')
		(game->coins)++;
	else if (game->copy[y][x] == 'E')
	{
		(game->exit_found) = 1;
		return ;
	}
	game->copy[y][x] = 's';
	dfs(game, x + 1, y);
	dfs(game, x - 1, y);
	dfs(game, x, y + 1);
	dfs(game, x, y - 1);
}

int	flood_fill(t_game *game)
{
	int	x;
	int	y;

	x = game->player_x;
	y = game->player_y;
	game->coins = 0;
	game->exit_found = 0;
	dfs(game, x, y);
	if (game->coins != game->collect_all || game->exit_found != 1)
		return (0);
	return (1);
}

void	player_position(char **map, int lines, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	validate_path(t_game *game)
{
	char	**copy;

	copy = duplicate_map(game->map, game->map_height);
	if (!copy)
	{
		free_map(game->map);
		write(1, "Error: Failed to allocate memory for path validation\n", 54);
	}
	game->copy = copy;
	if (!flood_fill(game))
	{
		free_map(game->map);
		free_copy(game->copy);
		write(1, "Error: Failed invalid path\n", 28);
		exit(1);
	}
	free_copy(game->copy);
}
