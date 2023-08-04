/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 06:31:30 by marvin            #+#    #+#             */
/*   Updated: 2023/07/24 06:31:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	uscita_giocatore(t_image *game, int y, int x, char map_letter)
{
	int	sx;
	int	sy;

	sx = x * 65;
	sy = y * 65;
	if (map_letter == USCITA)
	{
		game->exit_x_65 = sx;
		game->exit_y_65 = sy;
		game->exit_x = x;
		game->exit_y = y;
		mlx_put_image_to_window(game->img_ptr, game->win, game->check, sx, sy);
	}
	if (map_letter == GIOCATORE)
	{
		mlx_put_image_to_window(game->img_ptr, game->win, game->actual, sx, sy);
		game->char_x = x;
		game->char_y = y;
		game->char_x_65 = sx;
		game->char_y_65 = sy;
	}
}

void	check_and_print(char map_letter, t_image *game, int y, int x)
{
	int	sx;
	int	sy;

	sx = x * 65;
	sy = y * 65;
	if (map_letter == MURO)
		mlx_put_image_to_window(game->img_ptr, game->win, game->wall, sx, sy);
	if (map_letter == TERRA)
		mlx_put_image_to_window(game->img_ptr, game->win, game->terra, sx, sy);
	if (map_letter == FIORI)
		mlx_put_image_to_window(game->img_ptr, game->win, game->flower, sx, sy);
	if (map_letter == VITTORIA)
		mlx_put_image_to_window(game->img_ptr, game->win, game->victory, sx,
			sy);
	uscita_giocatore(game, y, x, map_letter);
}

void	ft_check_map(char **s, t_image *game, char *sr)
{
	int	y;
	int	x;

	y = 0;
	x = ft_strlen(s[y]) - 1;
	while (s[++y] != NULL)
	{
		if (!(s[y][0] == MURO && s[y][x] == MURO))
		{
			free(sr);
			close_vc(game);
		}
	}
	game->map_size_y = y;
	x = 0;
	y--;
	while (s[y][x])
	{
		if (!(s[y][x] == MURO && s[0][x] == MURO))
		{
			free(sr);
			close_vc(game);
		}
		x++;
	}
}

void	create_store_show(char *argv, t_image *game)
{
	int		fileid;
	char	*linea;
	char	*full_str;
	char	*temp;

	fileid = open(argv, O_RDONLY);
	if (fileid == -1)
		close_z(game);
	full_str = (char *)ft_calloc(1, sizeof(char));
	while (1)
	{
		linea = get_next_line(fileid);
		if (linea == NULL)
			break ;
		temp = full_str;
		full_str = ft_strjoin(full_str, linea);
		free(temp);
		free(linea);
	}
	check_n(full_str, game);
	full_str = convert_for_windows(full_str);
	game->map = ft_split(full_str, '\n');
	ft_check_map(game->map, game, full_str);
	check_presence(full_str, game);
	free(full_str);
}

int	main(int argc, char **argv)
{
	t_image	*game;

	game = malloc(sizeof(t_image));
	ft_arg(argc, argv, game);
	game->img_ptr = mlx_init();
	init_images(game);
	set_game(game);
	create_store_show(argv[1], game);
	game->map_size_x = ft_strlen(game->map[0]);
	game->win = mlx_new_window(game->img_ptr, game->map_size_x * 65,
			game->map_size_y * 65, "so_long");
	game->actual = game->character_f;
	mlx_hook(game->win, KeyPress, KeyPressMask, ft_handle_input, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, close_x, game);
	mlx_hook(game->win, Expose, ExposureMask, print_map, game);
	mlx_loop(game->img_ptr);
}
