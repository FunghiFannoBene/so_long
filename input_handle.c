/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:09:17 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 17:09:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_vc(t_image *game)
{
	mlx_destroy_image(game->img_ptr, game->wall);
	mlx_destroy_image(game->img_ptr, game->check);
	mlx_destroy_image(game->img_ptr, game->terra);
	mlx_destroy_image(game->img_ptr, game->victory);
	mlx_destroy_image(game->img_ptr, game->flower);
	mlx_destroy_image(game->img_ptr, game->character_r);
	mlx_destroy_image(game->img_ptr, game->character_f);
	mlx_destroy_image(game->img_ptr, game->character_b);
	mlx_destroy_image(game->img_ptr, game->character_l);
	mlx_destroy_display(game->img_ptr);
	free(game->img_ptr);
	free_matrix(game->map, game->map_size_y);
	free(game);
	ft_printf("Error\n");
	exit(1);
}

int	ft_handle_input(int tasto, t_image *game)
{
	int	terra;

	if (cant_move(game, tasto))
		return (0);
	if (tasto == ESC)
		close_x(game);
	if (tasto == D || tasto == RIGHT)
		moveright(game);
	if (tasto == A || tasto == LEFT)
		moveleft(game);
	if (tasto == W || tasto == UP)
		moveup(game);
	if (tasto == S || tasto == DOWN)
		movedown(game);
	game->movement++;
	print_move(game);
	return (0);
}

void	set_game(t_image *game)
{
	game->exit_x_65 = 0;
	game->exit_y_65 = 0;
	game->map_size_y = 0;
	game->map_size_x = 0;
	game->char_y = 0;
	game->char_x = 0;
	game->movement = 0;
	game->char_x_65 = 0;
	game->char_y_65 = 0;
	game->collectible = 0;
	game->exit_check = 0;
	game->char_count = 0;
}
