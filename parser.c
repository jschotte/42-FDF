/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:12:23 by jschotte          #+#    #+#             */
/*   Updated: 2016/01/27 10:22:01 by jschotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_count_c(char *map)
{
	int i;
	int count;
	int test;

	i = 0;
	test = 0;
	count = 0;
	while (map[i] != '\0' && map[i] != '\n')
	{
		if (map[i] != ' ' && test == 0)
		{
			count++;
			test = 1;
		}
		if (test == 1 && map[i] == ' ')
			test = 0;
		i++;
	}
	return (count);
}

int		ft_count_l(char *map)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		**ft_make_tab(char **split, int nb_col, int nb_line)
{
	int **tab;
	int i;
	int j;
	int k;

	tab = (int**)malloc(sizeof(int*) * (nb_line));
	i = 0;
	k = 0;
	j = 0;
	while (split[k] != '\0')
	{
		if (j == 0)
			tab[i] = (int*)malloc(sizeof(int) * (nb_col));
		tab[i][j] = ft_atoi(split[k]);
		j++;
		k++;
		if (j >= nb_col)
		{
			j = 0;
			i++;
		}
	}
	return (tab);
}

char	*ft_remove_n(char *map, int c, int i)
{
	int test;
	int count;

	test = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			map[i] = ' ';
			if (count % c != 0)
				ft_exit("file error");
			count = 0;
			test = 0;
		}
		if (map[i] != ' ' && test == 0)
		{
			count++;
			test = 1;
		}
		if (test == 1 && map[i] == ' ')
			test = 0;
		i++;
	}
	return (map);
}

void	ft_import(char *map)
{
	int		nb_line;
	int		nb_col;
	char	**split;
	int		**tab;
	int		i;

	nb_line = ft_count_l(map);
	nb_col = ft_count_c(map);
	map = ft_remove_n(map, nb_col, 0);
	split = ft_strsplit(map, ' ');
	tab = ft_make_tab(split, nb_col, nb_line);
	i = 0;
	while (split[i])
		i++;
	if (i == 1)
		ft_exit("Empty file");
	if (nb_line * nb_col != i)
		ft_exit("File error");
	ft_mlx_init(tab, nb_line, nb_col);
}
