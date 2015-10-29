##
## Makefile for Bistromathique in /home/morty/rendu/Piscine_C_bistromathique/bonus
## 
## Made by Nicolas Goudal
## Login   <goudal_n@epitech.net>
## 
## Started on  Thu Oct 29 02:02:32 2015 Nicolas Goudal
## Last update Thu Oct 29 03:10:46 2015 Nicolas Goudal
##

NAME		=	the_bistromatik

SRCS_NAMES	+=	.c

HDRS_NAMES	+=	.h

SRCS		=	$(addprefix $(SRC_DIR), $(SRCS_NAMES))

OBJS		=	$(SRCS:.c=.o)

DB_OBJS		=	$(SRCS:.c=.db.o)

HDRS		=	$(addprefix $(INC_DIR), $(HDRS_NAMES))

LIB_NAME	=	the_lib.a

LIB_PATH	=	$(LIB_DIR)$(LIB_NAME)

BNS_NAME	=	../$(NAME)

DB_NAME		=	$(NAME)_debug

SRC_DIR		=	sources/

LIB_DIR		=	../lib/

LIB_INC_DIR	=	../lib/includes/

INC_DIR		=	includes/

CC		=	gcc

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra
CFLAGS		+=	-pedantic
CFLAGS		+=	-I $(INC_DIR) -I $(LIB_INC_DIR)

LDFLAGS		+=	

DBFLAGS		=	-g -g3 -ggdb


.PHONY		:	all lib project bonus debug clean fclean re

all		:	project

lib		:	$(LIB_DIR)
			@$(MAKE) -C $(LIB_DIR)

project		:	lib
			@printf "\033[36m------------------------------BONUS COMPILATION------------------------------\n\033[37m"
			@$(MAKE) $(NAME)

bonus		:	lib
			@printf "\033[36m------------------------------BONUS COMPILATION------------------------------\n\033[37m"
			@$(MAKE) $(BNS_NAME)

debug		:
			@printf "\033[36m------------------------------BONUS COMPILATION------------------------------\n\033[37m"
			@$(MAKE) $(DB_NAME)

%.o		:	%.c
			$(CC) -o $@ -c $< $(CFLAGS)
			@printf "\033[33m[OBJECT COMPILED]\n\033[37m"

%.db.o		:	%.c $(HDRS)
			$(CC) -o $@ -c $< $(CFLAGS) $(DBFLAGS)
			@printf "\033[33m[OBJECT COMPILED]\n\033[37m"

$(NAME)		:	$(OBJS)
			$(CC) -o $@ $^ $(LIB_PATH) $(LDFLAGS)
			@printf "\033[32m[BINARY LINKED]\n\033[37m"

$(BNS_NAME)	:	$(OBJS)
			$(CC) -o $@ $^ $(LIB_PATH) $(LDFLAGS)
			@printf "\033[32m[BINARY LINKED]\n\033[37m"

$(DB_NAME)	:	$(DB_OBJS)
			$(CC) -o $@ $^ $(LIB_PATH) $(LDFLAGS)
			@printf "\033[32m[BINARY LINKED]\n\033[37m"

clean		:
			@$(MAKE) -C $(LIB_DIR) $@
			@printf "\033[36m--------------------------------BONUS DELETION-------------------------------\n\033[37m"
			$(RM) $(OBJS)
			@$(RM) $(DB_OBJS)
			@printf "\033[31m[OBJECTS DELETED]\n\033[37m"


fclean		:
			@$(MAKE) -C $(LIB_DIR) $@
			@printf "\033[36m--------------------------------BONUS DELETION-------------------------------\n\033[37m"
			$(RM) $(OBJS)
			@printf "\033[31m[OBJECTS DELETED]\n\033[37m"
			$(RM) $(NAME)
			@$(RM) $(DB_NAME)
			@printf "\033[31m[BINARY DELETED]\n\033[37m"

re		:	fclean all