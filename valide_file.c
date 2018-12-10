/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 01:02:58 by ikharbou          #+#    #+#             */
/*   Updated: 2018/11/15 04:32:54 by ikharbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int		v_cube(char **cube)
{
	int i;
	int j;
	int x;

	x = 0;
	j = -1;
	while (cube[++j])
	{
		i = -1;
		while (cube[j][++i])
		{
			if (cube[j][i] == '#')
			{
				((i < 3) && (cube[j][i + 1] == '#')) ? (x += 1) : (x = x * 1);
				((i > 0) && (cube[j][i - 1] == '#')) ? (x += 1) : (x = x * 1);
				((j < 3) && (cube[j + 1][i] == '#')) ? (x += 1) : (x = x * 1);
				((j > 0) && (cube[j - 1][i] == '#')) ? (x += 1) : (x = x * 1);
			}
		}
	}
	return (x);
}

int		file_check(char opt[27][22], int i)
{
	if (opt[i + 1][0] != '\0')
	{
		if ((ft_cw(opt[i], '#') != 4) || (ft_cw(opt[i], '.') != 12) ||
		(ft_cw(opt[i], '\n') != 5) || opt[i][0] == '\n')
			return (-1);
	}
	else if (opt[i][20] != '\0' ||
	(ft_cw(opt[i], '#') != 4) || (ft_cw(opt[i], '.') != 12) ||
	(ft_cw(opt[i], '\n') != 4) || opt[i][0] == '\n')
		return (-1);
	return (0);
}

int		read_file(int fd, char ***cube)
{
	int		i;
	int		rd;
	char	opt[27][22];

	i = -1;
	while ((rd = read(fd, opt[++i], 21)) > 0)
		;
	if (i == 0 || i > 26)
		return (-1);
	opt[++i][0] = '\0';
	i = -1;
	while (opt[++i][0] != '\0')
		if (file_check(opt, i) != 0)
			return (-1);
	i = -1;
	while (opt[++i][0] != '\0')
		cube[i] = ft_strsplit(opt[i], '\n');
	cube[i] = 0;
	return (0);
}
