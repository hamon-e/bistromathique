##
## Makefile for Bistromathique in /home/morty/rendu/Piscine_C_bistromathique/bonus
## 
## Made by Nicolas Goudal
## Login   <goudal_n@epitech.net>
## 
## Started on  Thu Oct 29 02:02:32 2015 Nicolas Goudal
## Last update Thu Oct 29 05:25:51 2015 Nicolas Goudal
##

NAME		=	the_lapin

SRCS_DIR	=	sources/

SRCS_NAMES	+=	main.c

SRCS_NAMES	+=	lapin/init.c
SRCS_NAMES	+=	lapin/list.c
SRCS_NAMES	+=	lapin/blit.c
SRCS_NAMES	+=	lapin/result.c
SRCS_NAMES	+=	lapin/event_keyboard.c
SRCS_NAMES	+=	lapin/event_mouse.c

SRCS_NAMES	+=	inf_op/do_inf_op.c
SRCS_NAMES	+=	inf_op/get_op_nbr.c
SRCS_NAMES	+=	inf_op/char_shift.c
SRCS_NAMES	+=	inf_op/check_tools.c
SRCS_NAMES	+=	inf_op/inf_add.c
SRCS_NAMES	+=	inf_op/inf_div.c
SRCS_NAMES	+=	inf_op/inf_mod.c
SRCS_NAMES	+=	inf_op/inf_mult.c
SRCS_NAMES	+=	inf_op/inf_sub.c
SRCS_NAMES	+=	inf_op/str_tools.c
SRCS_NAMES	+=	inf_op/check_frac.c
SRCS_NAMES	+=	inf_op/div_sub.c

SRCS_NAMES	+=	parser/parser_checkers.c
SRCS_NAMES	+=	parser/peg_rules.c
SRCS_NAMES	+=	parser/peg_tools.c
SRCS_NAMES	+=	parser/free_tree.c

HDRS_NAMES	+=	parser.h
HDRS_NAMES	+=	inf_op.h
HDRS_NAMES	+=	the_lapin.h

SRCS		=	$(addprefix $(SRC_DIR), $(SRCS_NAMES))

OBJS		=	$(SRCS:.c=.o)

DB_OBJS		=	$(SRCS:.c=.db.o)

HDRS		=	$(addprefix $(INC_DIR), $(HDRS_NAMES))

LIB_NAME	=	the_lib.a

LIB_PATH	=	$(LIB_DIR)$(LIB_NAME)

BNS_NAME	=	../$(NAME)

DB_NAME		=	$(NAME)_debug

SRC_DIR		=	sources/

LIB_DIR		=	../../lib/

LIB_INC_DIR	=	../../lib/includes/

INC_DIR		=	includes/

CC		=	gcc

RM		=	rm -f

CFLAGS		+=	-W -Wall -Wextra
CFLAGS		+=	-pedantic
CFLAGS		+=	-I $(INC_DIR) -I $(LIB_INC_DIR)
CFLAGS		+=	-L/home/${USER}/.froot/include

LDFLAGS		+=	-lsfml-audio -lsfml-graphics -lsfml-window
LDFLAGS		+=	-lsfml-system -lstdc++ -ldl -lm
LDFLAGS		+=	-L/home/${USER}/.froot/lib/ -llapin

LDFLAGS		+=	

DBFLAGS		=	-g -g3 -ggdb


.PHONY		:	all lib project bonus lapin debug clean fclean re

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

$(NAME)		:	$(OBJS) $(LIB_PATH)
			$(CC) -o $@ $^ $(LDFLAGS)
			@printf "\033[32m[BINARY LINKED]\n\033[37m"
			mv $(NAME) ../

$(BNS_NAME)	:	$(OBJS) $(LIB_PATH)
			$(CC) -o $@ $^ $(LDFLAGS)
			@printf "\033[32m[BINARY LINKED]\n\033[37m"

$(DB_NAME)	:	$(DB_OBJS) $(LIB_PATH)
			$(CC) -o $@ $^ $(LDFLAGS)
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
			$(RM) ../$(NAME)
			@$(RM) $(DB_NAME)
			@printf "\033[31m[BINARY DELETED]\n\033[37m"

re		:	fclean all
