/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 01:02:28 by ikharbou          #+#    #+#             */
/*   Updated: 2018/11/13 01:02:29 by ikharbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIS_H
# define TETRIS_H

# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft/libft.h"

void	ft_putendll(char **str);
void	ft_print_cube(char ***cube);
void	remove_cube(char **map, char **cube);
void	delete_map(char **map);
int		ft_cw(char const *s, char c);
int		read_file(int fd, char ***cube);
int		v_cube(char **cube);
int		c(char **cube);
int		p(char **cube);
int		cal_m(char ***cube);
char	**map_c(char ***cube, int p);
char	**ft_crop(char ***cube);
char	**new_map(int size);
char	ft_tetletter(char *tet);
char	**c_map(char **map, char **cube, int i, int j);
int		ft_chek_map(char **map, char **cube, int j, int i);
int		solver(char ***cube, char **map, int p);

#endif
