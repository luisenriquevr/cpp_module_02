# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 18:00:26 by lvarela           #+#    #+#              #
#    Updated: 2023/02/27 21:27:43 by lvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	:=	$(wildcard *.cpp)
OBJS	:=	$(SRCS:%.cpp=%.o)
CC		:=	c++
CPPSTD	:=	-std=c++98
FLAGS	:=	-Wall -Werror -Wextra
RM		:=	rm -rf
NAME	:=	TNow\ we’re\ talking

all		:	$(NAME)

$(NAME) :	$(OBJS)
			$(CC) $(FLAGS) $(CPPSTD) $(OBJS) -o $(NAME)

$(%.o)	:	$(%.c)
			$(CC) -c $^ -o $@

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME) text/*.replace

re		:	fclean all

.PHONY	:	all $(NAME) clean fclean re
