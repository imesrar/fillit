/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:26:52 by ikharbou          #+#    #+#             */
/*   Updated: 2018/11/05 13:26:56 by ikharbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int		ft_cw(char const *s, char c)
{
	unsigned int	i;
	int				cntr;

	i = -1;
	cntr = 0;
	while (s[++i])
		if (s[i] == c)
			cntr++;
	return (cntr);
}

int		c(char **cube)
{
	int i;
	int j;
	int x;

	x = 0;
	j = 0;
	i = -1;
	while (cube[j][++i])
	{
		if (cube[j][i] == '#' || cube[j + 1][i] == '#' ||
			cube[j + 2][i] == '#' || cube[j + 3][i] == '#')
			x++;
	}
	return (x);
}

int		p(char **cube)
{
	int i;
	int j;
	int x;

	x = 0;
	j = 0;
	i = -1;
	while (cube[j][++i])
	{
		if (cube[j][i] == '#' || cube[j + 1][i] == '#' ||
			cube[j + 2][i] == '#' || cube[j + 3][i] == '#')
			return (i);
	}
	return (0);
}

void	ft_indice_copy(char ***cube, char **tmp, int k)
{
	static char	x = 'A';
	int			j;
	int			i;

	j = -1;
	while (tmp[++j])
	{
		cube[k][j] = ft_strdup(tmp[j]);
		ft_strclr(tmp[j]);
		i = -1;
		while (cube[k][j][++i])
			if (cube[k][j][i] == '#')
				cube[k][j][i] = x;
	}
	cube[k][j] = 0;
	x++;
}

char	**ft_crop(char ***cube)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char*) * 5);
	k = -1;
	while (cube[++k])
	{
		j = -1;
		i = -1;
		while (cube[k][++j])
			if (ft_cw(cube[k][j], '#') > 0)
				tmp[++i] = ft_strdup(
				ft_strsub(cube[k][j], p(cube[k]), c(cube[k])));
		tmp[++i] = 0;
		j = -1;
		while (cube[k][++j])
			ft_strclr(cube[k][j]);
		j = -1;
		ft_indice_copy(cube, tmp, k);
	}
	return (NULL);
}
