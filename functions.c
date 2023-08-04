/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:49:51 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 03:49:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_image *game)
{
	char	*movements;
	char	*phrase;

	movements = ft_itoa(game->movement);
	phrase = ft_strjoin("Movementi: ", movements);
	mlx_put_image_to_window(game->img_ptr, game->win, game->wall, 0, 0);
	mlx_put_image_to_window(game->img_ptr, game->win, game->wall, 65, 0);
	mlx_string_put(game->img_ptr, game->win, 40, 20, 0x000000, phrase);
	ft_printf("%s\n", phrase);
	free(movements);
	free(phrase);
}

int	close_x(t_image *game)
{
	free_matrix(game->map);
	mlx_destroy_image(game->img_ptr, game->wall);
	mlx_destroy_image(game->img_ptr, game->check);
	mlx_destroy_image(game->img_ptr, game->terra);
	mlx_destroy_image(game->img_ptr, game->victory);
	mlx_destroy_image(game->img_ptr, game->flower);
	mlx_destroy_image(game->img_ptr, game->character_r);
	mlx_destroy_image(game->img_ptr, game->character_f);
	mlx_destroy_image(game->img_ptr, game->character_b);
	mlx_destroy_image(game->img_ptr, game->character_l);
	mlx_destroy_window(game->img_ptr, game->win);
	mlx_destroy_display(game->img_ptr);
	free(game->img_ptr);
	free(game);
	ft_printf("Error\n");
	exit(1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	*convert_for_windows(char *fullstr)
{
	int	i;

	i = 0;
	while (fullstr[i])
	{
		if (fullstr[i] == '\r')
			fullstr[i] = '\n';
		i++;
	}
	return (fullstr);
}

void	check_presence(char *s, t_image *game)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '\n' && s[i] != MURO && s[i] != FIORI && s[i] != TERRA
			&& s[i] != GIOCATORE && s[i] != USCITA)
		{
			free(s);
			close_vc(game);
		}
		if (s[i] == FIORI)
			game->collectible++;
		if (s[i] == GIOCATORE)
			game->char_count++;
		if (s[i] == USCITA)
			game->exit_check++;
		i++;
	}
	if (game->collectible == 0 || game->char_count != 1
		|| game->exit_check != 1)
	{
		free(s);
		close_vc(game);
	}
}
