/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 13:01:04 by jschotte          #+#    #+#             */
/*   Updated: 2016/01/25 15:58:33 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		ft_point(int x, int y, int z)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

int			ft_getcolor(int nb)
{
	if (nb <= 0)
		return (0x0000FF);
	if (nb <= 5)
		return (0x00FF00);
	if (nb <= 10)
		return (0xFFFF00);
	else if (nb <= 20)
		return (0xA97643);
	else if (nb <= 30)
		return (0x808080);
	else if (nb <= 40)
		return (0x404040);
	else
		return (0xFFFFFF);
}

void		key_hook_bis(int keycode, t_env *e)
{
	if (keycode == 124)
		e->x_start += 50;
	else if (keycode == 123)
		e->x_start -= 50;
	else if (keycode == 126)
		e->y_start -= 25;
	else if (keycode == 125)
		e->y_start += 25;
	else if (keycode == 34)
		e->len *= 1.5;
}

int			key_hook(int keycode, t_env *e)
{
	ft_clear(e);
	key_hook_bis(keycode, e);
	if (keycode == 53)
		exit(0);
	else if (keycode == 69)
	{
		e->width++;
		e->height++;
	}
	else if (keycode == 78)
	{
		e->width--;
		e->height--;
	}
	else if (keycode == 2)
		e->len -= e->len * 0.5;
	if (keycode == 78 || keycode == 69 || keycode == 36)
	{
		e->x_start = (WIN_X - (e->col / 2 * e->width)) / 2;
		e->y_start = (WIN_Y - (e->line * e->height)) / 2;
	}
	e->cord = ft_getcoord(e->line, e->col, e);
	draw(e);
	ft_commands(e);
	return (0);
}

int			expose_hook(t_env *e)
{
	draw(e);
	return (0);
}
