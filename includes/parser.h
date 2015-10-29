/*
** parser.h for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/includes
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 18:23:31 2015 Nicolas Goudal
** Last update Thu Oct 29 20:15:39 2015 Nicolas Goudal
*/

#ifndef PARSER_H_
# define PARSER_H_

# include <stdbool.h>


typedef enum	e_type
{
  OPP,
  NUM
}		t_type;

typedef enum	e_sign
{
  PLUS = 1,
  MINUS = -1
}		t_sign;

typedef struct	s_nbr
{
  char const	*nbr;
  int		lenght;
  t_sign	sign;
}		t_nbr;

typedef struct	s_op
{
  char		c;
}		t_op;

typedef struct	s_tree
{
  void		*data;
  t_type	type;
  t_sign	sign;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

typedef struct	s_data
{
  char const	*str;
  char const	*op_base;
  char const	*nbr_base;
}		t_data;


int		calc(t_tree *racine);

t_tree		*ope_low(t_data *ctrl, unsigned int *index);
bool		is_upopp(t_data *ctrl, unsigned int index);
bool		is_lowopp(t_data *ctrl, unsigned int index);
bool		is_digit(t_data *ctrl, unsigned int index);
bool		is_num(t_data *ctrl, unsigned int *index);
void		the_space_consumer(t_data *ctrl, unsigned int *index);
t_tree		*create_node(t_type type, void *str,
			     t_tree *left, t_tree *right);

int		check_argv(int argc, char const *argv[]);
void		init(t_data *ctrl, char const *argv[]);

#endif /* !PARSER_H_ */
