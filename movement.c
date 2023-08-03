/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:47:18 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 03:47:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	moveright(t_image *game)
{
	ft_swap(&(game->map[game->char_y][game->char_x]),
		&(game->map[game->char_y][game->char_x + 1]));
	game->actual = game->character_r;
	mlx_put_image_to_window(game->img_ptr, game->win, game->actual,
		game->char_x_65 += 65, game->char_y_65);
	mlx_put_image_to_window(game->img_ptr, game->win, game->terra,
		game->char_x_65 - 65, game->char_y_65);
	game->char_x++;
}

void	moveleft(t_image *game)
{
	ft_swap(&(game->map[game->char_y][game->char_x]),
		&(game->map[game->char_y][game->char_x - 1]));
	game->actual = game->character_l;
	mlx_put_image_to_window(game->img_ptr, game->win, game->actual,
		game->char_x_65 -= 65, game->char_y_65);
	mlx_put_image_to_window(game->img_ptr, game->win, game->terra,
		game->char_x_65 + 65, game->char_y_65);
	game->char_x--;
}

void	moveup(t_image *game)
{
	ft_swap(&(game->map[game->char_y][game->char_x]),
		&(game->map[game->char_y - 1][game->char_x]));
	game->actual = game->character_b;
	mlx_put_image_to_window(game->img_ptr, game->win, game->actual,
		game->char_x_65, game->char_y_65 -= 65);
	mlx_put_image_to_window(game->img_ptr, game->win, game->terra,
		game->char_x_65, game->char_y_65 + 65);
	game->char_y--;
}

void	movedown(t_image *game)
{
	ft_swap(&(game->map[game->char_y][game->char_x]),
		&(game->map[game->char_y + 1][game->char_x]));
	game->actual = game->character_f;
	mlx_put_image_to_window(game->img_ptr, game->win, game->actual,
		game->char_x_65, game->char_y_65 += 65);
	mlx_put_image_to_window(game->img_ptr, game->win, game->terra,
		game->char_x_65, game->char_y_65 - 65);
	game->char_y++;
}
