/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:12:45 by ikharbou          #+#    #+#             */
/*   Updated: 2018/12/08 00:18:07 by ikharbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

void	ft_putendll(char **str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putendl(str[i]);
}

int		ft_rcc_form(int fd)
{
	int i;
	char***cube;

	cube = (char ***)malloc(sizeof(char**) * 27);
	if (read_file(fd, cube) == -1)
		return (-1);
	i = -1;
	while (cube[++i])
		if ((v_cube(cube[i]) != 6) &&
	(v_cube(cube[i]) != 8))
			return (-1);
	ft_crop(cube);
	solver(cube, new_map(cal_m(cube)), cal_m(cube));
	i = -1;
	while (cube[++i])
		ft_strdel(cube[i]);
	return (0);
}

int		main(int ac, char **av)
{
	int fd;
	int i;

	i = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putendl("error");
			return (0);
		}
		if (ft_rcc_form(fd) != 0)
		{
			ft_putendl("error");
			return (0);
		}
	}
	else
		ft_putstr("usage:   ./fillit source_file\n");
	return (0);
}
