/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:24:01 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/26 23:17:53 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player_and_collectibles(t_game *game)
{
	int	j;
	int	i;

	j = 0;
	game->collect_all = 0;
	while (j < game->map_height)
	{
		i = 0;
		while (i < game->map_width)
		{
			if (game->map[j][i] == 'P')
			{
				game->player_x = i;
				game->player_y = j;
			}
			else if (game->map[j][i] == 'C')
				game->collect_all++;
			i++;
		}
		j++;
	}
}

void	fill_map(char **map, int lines, int fd)
{
	int	i;
	int	len;

	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			write(1, "Error while reading\n", 21);
			exit(1);
		}
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			map[i][len - 1] = '\0';
		i++;
	}
	map[lines] = NULL ;
}

void	read_and_parse_map(char *file, int *lines, t_game *game)
{
	int		fd;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error: cannot open file\n", 25);
		exit(1);
	}
	*lines = count_lines(file);
	if (*lines == 0)
	{
		write(1, "Error: empty map\n", 18);
		exit(1);
	}
	game->map_height = *lines;
	map = malloc(sizeof(char *) * (*lines + 1));
	if (!map)
		error_exit(map, "Error: malloc failed\n");
	fill_map(map, *lines, fd);
	close(fd);
	game->map = map;
}
