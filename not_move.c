/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:19:59 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 17:19:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_element_and_character(t_image *game, int tasto, char **element)
{
	if (tasto == D || tasto == RIGHT)
	{
		game->actual = game->character_r;
		*element = &(game->map[game->char_y][game->char_x + 1]);
	}
	else if (tasto == A || tasto == LEFT)
	{
		game->actual = game->character_l;
		*element = &(game->map[game->char_y][game->char_x - 1]);
	}
	else if (tasto == W || tasto == UP)
	{
		game->actual = game->character_b;
		*element = &(game->map[game->char_y - 1][game->char_x]);
	}
	else if (tasto == S || tasto == DOWN)
	{
		game->actual = game->character_f;
		*element = &(game->map[game->char_y + 1][game->char_x]);
	}
}

void	check_for_victory(t_image *game, char *element)
{
	if (*element == VITTORIA)
		close_x(game);
}

void	check_for_flowers(t_image *game, char *element)
{
	if (*element == FIORI)
	{
		game->collectible--;
		*element = TERRA;
		if (game->collectible == 0)
		{
			game->map[game->exit_y][game->exit_x] = 'X';
			mlx_put_image_to_window(game->img_ptr, game->win, game->victory,
				game->exit_x_65, game->exit_y_65);
		}
	}
}

int	check_for_wall_or_exit(t_image *game, char *element)
{
	if (*element == MURO || *element == USCITA)
	{
		mlx_put_image_to_window(game->img_ptr, game->win, game->actual,
			game->char_x_65, game->char_y_65);
		return (1);
	}
	return (0);
}

int	cant_move(t_image *game, int tasto)
{
	char	*element;

	set_element_and_character(game, tasto, &element);
	check_for_victory(game, element);
	check_for_flowers(game, element);
	return (check_for_wall_or_exit(game, element));
}
