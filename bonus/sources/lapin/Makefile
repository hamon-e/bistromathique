##
## Makefile for lapin in /home/hamon_e/Piscine/Piscine_C_bistromathique/lapin
## 
## Made by Benoit Hamon
## Login   <hamon_e@epitech.net>
## 
## Started on  mer. oct. 28 22:21:26 2015 Benoit Hamon
## Last update Sun Nov  1 11:27:49 2015 lin patrick
##

NAME		=	lapin

CC		=	gcc

SRCS_DIR	=	sources/

FILES		=	main.c			\
			init.c			\
			list.c			\
			blit.c			\
			result.c		\
			event_keyboard.c	\
			event_mouse.c

SRCS		=	$(addprefix $(SRCS_DIR), $(FILES))

OBJS		=	$(SRCS:.c=.o)

LIB		=	-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm -L/home/${USER}/.froot/lib/ -llapin

CFLAGS		+=	-Wall -Wextra

CFLAGS		+=	-I includes -I/home/${USER}/.froot/include/

CFLAGS		+=	$(LIB)

LDFLAGS		=	$(LIB)

RM		=	rm -f

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all
