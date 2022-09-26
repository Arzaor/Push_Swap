# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/13 13:09:02 by jbarette          #+#    #+#              #
#    Updated: 2022/09/26 13:04:25 by jbarette         ###   ########.fr        #
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
				treatment.c \
				swap.c \
				push.c \
				rotate.c \
				reverse_rotate.c \
				sorted_two.c \
				sorted_three.c \
				sorted_hundred.c \

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