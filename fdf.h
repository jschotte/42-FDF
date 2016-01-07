/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:45:29 by jschotte          #+#    #+#             */
/*   Updated: 2016/01/07 15:03:43 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# define WIN_X 500
# define WIN_Y 500

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

void	ft_exit(char *str);

#endif
