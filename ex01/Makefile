# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvarela <lvarela@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 18:00:26 by lvarela           #+#    #+#              #
#    Updated: 2022/06/27 22:14:32 by lvarela          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	:=	$(wildcard *.cpp)
OBJS	:=	$(SRCS:%.cpp=%.o)
CC		:=	c++
CPPSTD	:=	-std=c++98
FLAGS	:=	-Wall -Werror -Wextra
RM		:=	rm -rf
NAME	:=	Towards\ a\ more\ useful\ fixed\ point\ class

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

.PHONY	:	all clean fclean re
