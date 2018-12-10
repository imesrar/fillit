/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 05:17:30 by ikharbou          #+#    #+#             */
/*   Updated: 2018/12/02 03:02:13 by ikharbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

void	remove_cube(char **map, char **cube)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (cube[0][++i])
		if (cube[0][i] != '.')
			c = cube[0][i];
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
			if (map[j][i] == c)
				map[j][i] = '.';
	}
}

int		cal_m(char ***cube)
{
	int i;
	int p;

	p = -1;
	while (cube[++p])
		;
	i = 0;
	while ((i * i) < p)
		i++;
	return (i);
}

char	ft_tetletter(char *tet)
{
	int i;

	i = 0;
	while (tet[i] == '.')
		i++;
	return (tet[i]);
}

int		print_result(char ***cube, char **map)
{
	if (!(*cube))
	{
		ft_putendll(map);
		return (1);
	}
	return (0);
}

int		solver(char ***cube, char **map, int p)
{
	int i;
	int j;

	j = 0;
	if (print_result(cube, map) == 1)
		return (1);
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (ft_chek_map(*cube, map, j, i))
			{
				c_map(*cube, map, j, i);
				if (solver(cube + 1, map, p))
					return (1);
				remove_cube(map, *cube);
			}
			i++;
		}
		j++;
	}
	if (ft_tetletter((*cube)[0]) == 'A')
		solver(cube, new_map(p + 1), p + 1);
	return (0);
}
