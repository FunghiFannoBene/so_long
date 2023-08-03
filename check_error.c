/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:58:11 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 12:58:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_msg(char *s, t_image *game)
{
	free(game);
	ft_printf("%s", s);
	exit(0);
}

void	ft_arg(int argc, char **argv, t_image *game)
{
	int	map_parameter_len;

	if (argc > 2)
		ft_error_msg("Error\n", game);
	if (argc < 2)
		ft_error_msg("Error\n", game);
	map_parameter_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_parameter_len - 4], ".ber", 4))
		ft_error_msg("Error\n", game);
}

void	init_images(t_image *game)
{
	int	s;

	s = 65;
	game->wall = mlx_xpm_file_to_image(game->img_ptr, MURO_IMG, &s, &s);
	game->check = mlx_xpm_file_to_image(game->img_ptr, USCITA_IMG, &s, &s);
	game->terra = mlx_xpm_file_to_image(game->img_ptr, TERRA_IMG, &s, &s);
	game->victory = mlx_xpm_file_to_image(game->img_ptr, VITTORIA_IMG, &s, &s);
	game->flower = mlx_xpm_file_to_image(game->img_ptr, FIORI_IMG, &s, &s);
	game->character_r = mlx_xpm_file_to_image(game->img_ptr, G_R, &s, &s);
	game->character_f = mlx_xpm_file_to_image(game->img_ptr, G_D, &s, &s);
	game->character_b = mlx_xpm_file_to_image(game->img_ptr, G_U, &s, &s);
	game->character_l = mlx_xpm_file_to_image(game->img_ptr, G_L, &s, &s);
}

int	close_z(t_image *game)
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
	free(game);
	ft_printf("Error\n");
	exit(1);
}

int	print_map(t_image *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y] != NULL)
	{
		while (game->map[y][x])
		{
			check_and_print(game->map[y][x], game, y, x);
			x++;
		}
		y++;
		x = 0;
	}
	print_move(game);
	return (0);
}
