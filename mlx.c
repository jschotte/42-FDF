/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:01:04 by jschotte          #+#    #+#             */
/*   Updated: 2016/01/25 15:26:00 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		**ft_getcoord(int l, int c, t_env *e)
{
	int		i;
	int		j;
	int		start;
	t_point	**coord;

	coord = (t_point**)malloc(sizeof(t_point*) * (l));
	i = 0;
	start = e->x_start;
	while (i < l)
	{
		j = 0;
		while (j < c)
		{
			if (j == 0)
				coord[i] = (t_point*)malloc(sizeof(t_point) * c);
			coord[i][j] = ft_point(start + j * e->width, e->y_start
					+ i * e->height - e->len * e->map[i][j],
					ft_getcolor(e->map[i][j]));
			j++;
		}
		start -= e->width;
		i++;
	}
	return (coord);
}

void		line(t_env *e, t_point p1, t_point p2)
{
	int		err;
	int		e2;
	t_point	d;
	t_point	s;

	d = ft_point(ft_abs(p2.x - p1.x), ft_abs(p2.y - p1.y), 0);
	s = ft_point((p1.x < p2.x ? 1 : -1), (p1.y < p2.y ? 1 : -1), 0);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (1)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, p1.z);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			p1.x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
}

void		lineclear(t_env *e, t_point p1, t_point p2)
{
	int		err;
	int		e2;
	t_point	d;
	t_point	s;

	d = ft_point(ft_abs(p2.x - p1.x), ft_abs(p2.y - p1.y), 0);
	s = ft_point((p1.x < p2.x ? 1 : -1), (p1.y < p2.y ? 1 : -1), 0);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (1)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x, p1.y, 0x000000);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			p1.x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
}

void		draw(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->col)
		{
			if (j != e->col - 1)
				line(e, e->cord[i][j], e->cord[i][j + 1]);
			if (i != e->line - 1)
				line(e, e->cord[i][j], e->cord[i + 1][j]);
			j++;
		}
		i++;
	}
}

void		ft_mlx_init(int **tab, int nb_line, int nb_col)
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "42");
	e.line = nb_line;
	e.col = nb_col;
	e.map = tab;
	e.width = 4;
	e.height = 7;
	e.x_start = (WIN_X - (e.col / 2 * e.width)) / 2;
	e.y_start = (WIN_Y - (e.line * e.height)) / 2;
	e.len = 1;
	e.cord = ft_getcoord(e.line, e.col, &e);
	ft_commands(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
