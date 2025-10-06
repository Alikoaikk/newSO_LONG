/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:50:20 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/26 20:58:02 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char **map)
{
	int	height;

	height = 0 ;
	while (map && map[height])
		height++;
	return (height);
}

int	get_map_width(char **map)
{
	if (!map || !map[0])
		return (0);
	return ((int)ft_strlen(map[0]));
}

int	count_lines(char *file)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "Error: cannot open file\n", 25);
		exit(1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
