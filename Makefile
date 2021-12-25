# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/09 12:38:48 by gkelsie           #+#    #+#              #
#    Updated: 2021/11/12 17:21:15 by a1111            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRC			=	actions.c		args.c		errors.c \
				init.c			philo.c		process.c \
				utils.c

OBJ			=	${SRC:.c=.o}
OBJ_D		=	${patsubst %.c,%.d,${SRC}}

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror -pthread
FLAGS_O		=	-O2

RM			=	rm

all			:	${NAME}

${NAME}		:	${OBJ}

%.o			:	%.c	philo.h
	${CC} ${FLAGS} ${FLAGS_O} -c $< -o $@ -MD

include ${wildcard ${OBJ_D}}

clean		:
	${RM} -f ${OBJ} ${OBJ_D}

fclean		:	clean
	${RM} -f ${NAME}

re			:	fclean all

.PHONY	:	all re clean fclean