/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 16:47:52 by akoaik            #+#    #+#             */
/*   Updated: 2025/08/26 23:20:26 by akoaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename[len - 1] == 'r')
		return (1);
	return (0);
}

void	ber_exit(char *file_name)
{
	if (!check_ber_extension(file_name))
	{
		write(1, "Error: map file must have .ber extension\n", 41);
		exit(1);
	}
}

void	check_map(t_game game, int lines)
{
	check_characters(&game, lines);
	check_rectangular(&game, lines);
	check_walls(game.map, lines);
	check_map_duplicates(&game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		lines;

	if (argc != 2)
	{
		write(1, "Usage: ./so_long <map_file>\n", 29);
		exit(1);
	}
	ber_exit(argv[1]);
	ft_memset(&game, 0, sizeof(t_game));
	game.file_name = argv[1];
	read_and_parse_map(argv[1], &lines, &game);
	game.map_height = get_map_height(game.map);
	game.map_width = get_map_width(game.map);
	check_map(game, lines);
	init_player_and_collectibles(&game);
	validate_path(&game);
	render_window(&game);
	load_sprites_cop(&game);
	load_sprites_obj(&game);
	load_player_sprites(&game);
	draw_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
