/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:44:08 by jschotte          #+#    #+#             */
/*   Updated: 2016/01/27 10:18:06 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*map;

	if (argc < 2)
		ft_exit("Map missing");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			map = ft_strnew(1);
			while (get_next_line(fd, &line) > 0)
			{
				map = ft_strjoin(map, ft_strjoin(line, "\n"));
				free(line);
			}
			ft_import(map);
		}
		else
			ft_exit("Bad file descriptor");
	}
	return (0);
}
