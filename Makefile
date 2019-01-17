##
## Makefile for navy in /home/mael/PSU_2016_navy
##
## Made by mael drapier
## Login   <mael.drapier@epitech.eu@epitech.net>
##
## Started on  Mon Jan 30 11:47:10 2017 mael drapier
## Last update Wed Dec 20 23:18:34 2017 mael drapier
##

CC	=	gcc

RM	=	rm -f

#CFLAGS	+=	-W -Wall -Wextra -Werror
CFLAGS	+=	-I include/

LDFLAGS	+=

NAME	=	navy

SRCS	=	src/colorise.c		\
		src/colorise_boats.c	\
		src/display.c 		\
		src/map.c 		\
		src/error_hdl.c 	\
		src/nice_fct.c 		\
		src/core.c 		\
		src/catch_module.c 	\
		src/send.c 		\
		src/player.c 		\
		src/get_next_line.c	\
		src/main.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
