/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplication.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 23:02:43 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/27 12:36:13 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_elements(char **map, int *p_count, int *e_count, int *c_count)
{
	int	i;
	int	j;

	*p_count = 0;
	*e_count = 0;
	*c_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*p_count)++;
			else if (map[i][j] == 'E')
				(*e_count)++;
			else if (map[i][j] == 'C')
				(*c_count)++;
			j++;
		}
		i++;
	}
}

void	check_map_duplicates(t_game *game)
{
	int		p;
	int		e;
	int		c;
	char	**map;

	map = game->map;
	count_elements(map, &p, &e, &c);
	if (p != 1)
		error_exit(map, "Error: Map must contain exactly one player (P)\n");
	if (e != 1)
		error_exit(map, "Error: Map must contain exactly one exit (E)\n");
	if (c < 1)
		error_exit(map,
			"Error: Map must contain at least one collectible (C)\n");
}

void	check_characters(t_game *game, int lines)
{
	int	i;
	int	j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'C' && game->map[i][j] != '0'
				&& game->map[i][j] != '1')
			{
				free_map(game->map);
				write(1, "Invalid character\n", 18);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	check_rectangular(t_game *game, int lines)
{
	int	length;
	int	i;
	int	j;

	i = 0;
	j = 0;
	length = ft_strlen(game->map[0]);
	while (i < lines)
	{
		j = 0;
		while (game->map[i][j])
			j++;
		if (j == length)
			i++;
		else
			error_exit(game->map, "Error: map is not rectangular\n");
	}
	game->map_width = length;
}

void	check_walls(char **map, int lines)
{
	int	i;
	int	j;
	int	length;

	length = ft_strlen(map[0]);
	i = 0;
	while (i < length)
	{
		if (map[0][i] != '1' || map[lines - 1][i] != '1')
			error_exit(map, "Error: map is not surrounded/enclosed by walls\n");
		i++;
	}
	j = 0;
	while (j < lines)
	{
		if (map[j][0] != '1' || map[j][length - 1] != '1')
			error_exit(map, "Error: map is not surrounded/enclosed by walls\n");
		j++;
	}
}
