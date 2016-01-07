/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:44:08 by jschotte          #+#    #+#             */
/*   Updated: 2016/01/07 12:58:54 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 500, 500, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
