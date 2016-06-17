/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:01:58 by jschotte          #+#    #+#             */
/*   Updated: 2016/01/25 15:58:20 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *str)
{
	perror(str);
	exit(0);
}

void	ft_clear(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->col)
		{
			if (j != e->col - 1)
				lineclear(e, e->cord[i][j], e->cord[i][j + 1]);
			if (i != e->line - 1)
				lineclear(e, e->cord[i][j], e->cord[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	ft_commands(t_env *e)
{
	ft_commands_clear(e);
	mlx_string_put(e->mlx, e->win, 20, 40, 0x00FFFF, "Use arrows to Move");
	mlx_string_put(e->mlx, e->win, 20, 60, 0x00FF00, "Use + or - to Zoom");
	mlx_string_put(e->mlx, e->win, 20, 80, 0xFF0000, "Use i to Increase");
	mlx_string_put(e->mlx, e->win, 20, 100, 0xFFFF00, "And d to Decrease");
	mlx_string_put(e->mlx, e->win, 20, 120, 0xFF00FF, "Press esc to exit");
}

void	ft_commands_clear(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 20, 40, 0x000000, "Use arrows to Move");
	mlx_string_put(e->mlx, e->win, 20, 60, 0x000000, "Use + or - to Zoom");
	mlx_string_put(e->mlx, e->win, 20, 80, 0x000000, "Use i to Increase");
	mlx_string_put(e->mlx, e->win, 20, 100, 0x000000, "And d to Decrease");
	mlx_string_put(e->mlx, e->win, 20, 120, 0x000000, "Press esc to exit");
}
