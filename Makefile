# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zchatoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 22:54:03 by zchatoua          #+#    #+#              #
#    Updated: 2018/12/08 04:22:14 by ikharbou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FLAGS = -Wall -Werror -Wextra
NAME = fillit
all : $(NAME)

$(NAME) : *.c
	gcc $(FLAGS) -c maps.c u_function.c valide_file.c recursive.c libft/*.c -I.
	gcc $(FLAGS) main.c *.o -o $@
clean :
	rm -f *.o
	@make -C libft clean
fclean : clean
	rm -f fillit
	@make -C libft fclean
re : fclean all
