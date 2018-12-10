/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 05:51:41 by ikharbou          #+#    #+#             */
/*   Updated: 2018/11/20 05:51:42 by ikharbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

int		ft_chek_map(char **cube, char **map, int mem_j, int mem_i)
{
	int x;
	int y;
	int memo_i;

	memo_i = mem_i;
	y = -1;
	while (cube[++y])
	{
		x = -1;
		mem_i = memo_i;
		if (map[mem_j] == NULL)
			return (0);
		while (cube[y][++x])
		{
			if (((mem_i || mem_j) >= ft_strlen(map[0])) ||
			(map[mem_j][mem_i] != '.' && cube[y][x] != '.'))
				return (0);
			mem_i++;
		}
		mem_j++;
	}
	return (1);
}

char	**c_map(char **cube, char **map, int j, int i)
{
	int x;
	int y;
	int mem_i;

	mem_i = i;
	y = -1;
	while (cube[++y])
	{
		x = -1;
		i = mem_i;
		while (cube[y][++x])
		{
			if (map[j][i] == '.' && cube[y][x] != '.')
				map[j][i] = cube[y][x];
			i++;
		}
		j++;
	}
	return (map);
}

char	**new_map(int size)
{
	int		i;
	int		j;
	char	**map;

	map = (char **)malloc(sizeof(char*) * (size + 1));
	ft_bzero(map, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		map[i] = (char *)malloc(sizeof(char));
		while (++j < size)
			map[i][j] = '.';
	}
	map[i] = 0;
	i = -1;
	return (map);
}

void	cpy(char **dest, char **src)
{
	int	i;

	i = -1;
	delete_map(dest);
	while (src[++i])
		dest[i] = ft_strdup(src[i]);
	dest[i] = NULL;
}

void	delete_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		ft_strclr(map[i]);
		++i;
	}
}
