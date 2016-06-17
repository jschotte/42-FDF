/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:45:29 by jschotte          #+#    #+#             */
/*   Updated: 2016/01/25 15:42:28 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/includes/libft.h"
# define WIN_X 1000
# define WIN_Y 800

typedef struct	s_point
{
	int x;
	int y;
	int z;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			**map;
	int			line;
	int			col;
	double		width;
	int			height;
	int			x_start;
	int			y_start;
	double		len;
	t_point		**cord;
}				t_env;

void			ft_exit(char *str);
void			ft_import(char *map);
void			ft_mlx_init(int **tab, int nb_line, int nb_col);
t_point			ft_point(int x, int y, int z);
int				ft_getcolor(int nb);
int				key_hook(int keycode, t_env *e);
void			key_hook_bis(int keycode, t_env *e);
int				expose_hook(t_env *e);
t_point			**ft_getcoord(int l, int c, t_env *e);
void			line(t_env *e, t_point p1, t_point p2);
void			lineclear(t_env *e, t_point p1, t_point p2);
void			draw(t_env *e);
void			ft_clear(t_env *e);
void			ft_commands(t_env *e);
void			ft_commands_clear(t_env *e);
#endif
