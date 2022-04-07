# Variables

NAME	=	philo
SRCS	=	main.c init.c parsing.c threads.c actions.c routines.c routine_checks.c \
			waiting.c utils.c garbage_collector.c
OBJS	=	${SRCS:.c=.o}
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Iincludes -g3

# Rules

all:	${NAME}

$(NAME):	${OBJS}
	${CC} -o ${NAME} ${OBJS} -lpthread

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean :
	rm -rf ${OBJS}

fclean:	clean
	rm -rf ${NAME}

re:	fclean all

.PHONY: all clean fclean re
