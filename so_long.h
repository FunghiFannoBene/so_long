/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 03:45:06 by marvin            #+#    #+#             */
/*   Updated: 2023/08/03 03:45:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MURO '1'
# define TERRA '0'
# define FIORI 'C'
# define GIOCATORE 'P'
# define USCITA 'E'
# define VITTORIA 'X'
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define ESC 65307
# define MURO_IMG "./sprites/item/wall.xpm"
# define TERRA_IMG "./sprites/item/terra.xpm"
# define FIORI_IMG "./sprites/item/flower.xpm"
# define G_L "./sprites/char/char_left.xpm"
# define G_R "./sprites/char/char_right.xpm"
# define G_U "./sprites/char/char_back.xpm"
# define G_D "./sprites/char/char_front.xpm"
# define USCITA_IMG "./sprites/item/check.xpm"
# define VITTORIA_IMG "./sprites/item/victory.xpm"

# include "utility/ft_printf/ft_printf.h"
# include "utility/get_next_line/get_next_line_bonus.h"
# include "utility/libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <png.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*img_ptr;
	void	*win;
	void	*character_l;
	void	*character_r;
	void	*character_f;
	void	*character_b;
	void	*actual;
	void	*terra;
	void	*flower;
	void	*wall;
	void	*check;
	void	*victory;
	char	**map;
	int		collectible;
	int		exit_y_65;
	int		exit_x_65;
	int		exit_x;
	int		exit_y;
	int		map_size_y;
	int		map_size_x;
	int		char_y;
	int		char_x;
	int		movement;
	int		char_x_65;
	int		char_y_65;
	int		exit_check;
	int		char_count;
}			t_image;

void		ft_error_msg(char *s, t_image *game);
int			ft_handle_input(int keysym, t_image *game);
void		moveright(t_image *game);
void		moveleft(t_image *game);
void		moveup(t_image *game);
void		movedown(t_image *game);
void		ft_swap(char *a, char *b);
void		free_matrix(char **matrix);
int			close_x(t_image *game);
int			cant_move(t_image *game, int tasto);
void		print_move(t_image *game);
void		check_and_print(char map_letter, t_image *game, int y, int x);
int			print_map(t_image *game);
void		ft_check_map(char **s, t_image *game, char *sr);
char		*convert_for_windows(char *fullstr);
void		check_presence(char *s, t_image *game);
int			close_z(t_image *game);
void		create_store_show(char *argv, t_image *game);
void		init_images(t_image *game);
void		ft_error_msg(char *s, t_image *game);
void		ft_arg(int argc, char **argv, t_image *game);
void		set_game(t_image *game);
int			close_vc(t_image *game);
int			close_ln(t_image *game);
void 		check_n(char* full_str, t_image	*game);

#endif