# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:09:02 by jbarette          #+#    #+#              #
#    Updated: 2022/09/13 14:46:04 by jbarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	push_swap

SRC_DIR 	= 	srcs/
INC_DIR 	= 	includes/

SRC 		=	main.c \
				parsing.c \
				exit.c \
				list.c \
				utils.c \
				
SRCS 		= 	$(addprefix ${SRC_DIR}, ${SRC})
SRCS_ALL 	= 	${SRCS}

OBJS 		= 	$(SRCS:.c=.o)

CC			= 	gcc
# CFLAGS		=	-Wall -Wextra -Werror

LIB_RDL 	= 	./libft/libft.a

%.o: %.c
		${CC} $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJS)
		make -C ./libft
		${CC} $(CFLAGS) $(OBJS) ${LIB_RDL} -o $(NAME)

all:
		$(MAKE) -j $(NAME)

clean:
		make -C ./libft clean
		rm -rf $(OBJS)

fclean:	clean
		make -C ./libft fclean
		rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re