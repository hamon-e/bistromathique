##
## Makefile for Project in /home/morty/rendu/project/lib
## 
## Made by Nicolas Goudal
## Login   <goudal_n@epitech.net>
## 
## Started on  Thu Oct 29 01:58:41 2015 Nicolas Goudal
## Last update Thu Oct 29 03:05:44 2015 Nicolas Goudal
##

NAME		=	the_lib.a

SRCS_NAMES	+=	the_atoi.c
SRCS_NAMES	+=	the_exit.c
SRCS_NAMES	+=	the_malloc.c
SRCS_NAMES	+=	the_putchar.c
SRCS_NAMES	+=	the_putnbr.c
SRCS_NAMES	+=	the_putstr.c
SRCS_NAMES	+=	the_read.c
SRCS_NAMES	+=	the_strcmp.c
SRCS_NAMES	+=	the_strlen.c
SRCS_NAMES	+=	the_write.c

HDRS_NAMES	+=	the_lib.h

SRCS		=	$(addprefix $(SRC_DIR), $(SRCS_NAMES))

OBJS		=	$(SRCS:.c=.o)

HDRS		=	$(addprefix $(INC_DIR), $(HDRS_NAMES))

SRC_DIR		=	sources/

INC_DIR		=	includes/

CC		=	gcc

AR		=	ar rc

RANLIB		=	ranlib

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra
CFLAGS		+=	-pedantic
CFLAGS		+=	-I $(INC_DIR)


.PHONY		:	all lib clean fclean re

all		:	lib

lib		:	$(LIB_DIR)
			@printf "\033[35m-----------------------------LIBRARY COMPILATION-----------------------------\n\033[37m"
			@$(MAKE) $(NAME)

%.o		:	%.c $(HDRS)
			$(CC) -o $@ -c $< $(CFLAGS)
			@printf "\033[33m[OBJECT COMPILED]\n\033[37m"

$(NAME)		:	$(OBJS)
			$(AR) $@ $^
			@printf "\033[32m[ARCHIVE CREATED]\n\033[37m"
			$(RANLIB) $@
			@printf "\033[32m[ARCHIVE INDEXED]\n\033[37m"

clean		:
			@printf "\033[35m-------------------------------LIBRARY DELETION------------------------------\n\033[37m"
			$(RM) $(OBJS)
			@printf "\033[31m[OBJECTS DELETED]\n\033[37m"


fclean		:	clean
			$(RM) $(NAME)
			@printf "\033[31m[ARCHIVE DELETED]\n\033[37m"

re		:	fclean all
