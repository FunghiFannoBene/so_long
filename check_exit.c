/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:29:09 by marvin            #+#    #+#             */
/*   Updated: 2023/08/09 15:29:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**deep_copy(char **original, t_image size, t_image *game)
{
	int		i;
	int		j;
	char	**copy;

	i = 0;
	copy = malloc((size.map_size_y + 1) * sizeof(char *));
	while (i < size.map_size_y)
	{
		copy[i] = malloc((size.map_size_x + 1) * sizeof(char));
		j = 0;
		while (original[i][j] != '\0')
		{
			if (original[i][j] == GIOCATORE)
			{
				game->char_y = i;
				game->char_x = j;
			}
			copy[i][j] = original[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

t_image	copy_and_update_game(const t_image game, int char_x_delta,
		int char_y_delta)
{
	t_image	new_game;

	new_game.map_size_x = game.map_size_x;
	new_game.map_size_y = game.map_size_y;
	new_game.char_x = game.char_x + char_x_delta;
	new_game.char_y = game.char_y + char_y_delta;
	return (new_game);
}

void	flood_fill(char **tab, t_image game)
{
	if (game.char_x < 0 || game.char_x >= game.map_size_x || game.char_y < 0
		|| game.char_y >= game.map_size_y
		|| tab[game.char_y][game.char_x] == MURO)
		return ;
	tab[game.char_y][game.char_x] = '1';
	flood_fill(tab, copy_and_update_game(game, 1, 0));
	flood_fill(tab, copy_and_update_game(game, -1, 0));
	flood_fill(tab, copy_and_update_game(game, 0, -1));
	flood_fill(tab, copy_and_update_game(game, 0, 1));
}

void	check_exit(char **map, t_image *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == FIORI || map[y][x] == USCITA)
			{
				free_matrix(map);
				close_vc(game);
			}
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
	free_matrix(map);
	if (x == 1)
		close_vc(game);
}
