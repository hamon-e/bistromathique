/*
** parser.h for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/includes
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 18:23:31 2015 Nicolas Goudal
** Last update Fri Oct 30 03:57:12 2015 Nicolas Goudal
*/

#ifndef PARSER_H_
# define PARSER_H_

# include <stdbool.h>

# ifndef INF_OP_H_

#  define SYNTAXE_ERROR_MSG	"syntax error"
#  define ERROR_MSG		"Error"

typedef enum	e_op_enum
{
  OP_OPEN_PARENT_IDX,
  OP_CLOSE_PARENT_IDX,
  OP_ADD_IDX,
  OP_SUB_IDX,
  OP_MULT_IDX,
  OP_DIV_IDX,
  OP_MOD_IDX,
  OP_ERROR_IDX
}		t_op_enum;

typedef enum	e_sign
{
  PLUS = 1,
  MINUS = -1
}		t_sign;

typedef struct		s_op_nbr
{
  char			*nbr;
  t_sign		sign;
  int			length;
}			t_op_nbr;

# endif /* !INF_OP_H_ */


typedef enum	e_type
{
  OPP,
  NUM
}		t_type;

typedef struct	s_nbr
{
  char const	*nbr;
}		t_nbr;

typedef struct	s_op
{
  char		op;
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


t_op_nbr	*do_inf_op(t_data *ctrl, t_tree *root);
t_op_nbr	*get_op_nbr(t_data *ctrl, t_tree *node);
void		*get_final_result(t_op_nbr *result, t_data *ctrl, int rec);

t_tree		*ope_low(t_data *ctrl, unsigned int *index);
bool		is_upopp(t_data *ctrl, unsigned int index);
bool		is_lowopp(t_data *ctrl, unsigned int index);
bool		is_digit(t_data *ctrl, unsigned int index);
bool		is_num(t_data *ctrl, unsigned int *index);
void		the_space_consumer(t_data *ctrl, unsigned int *index);
t_tree		*create_node(t_type type,
			     void *str,
			     t_tree *left,
			     t_tree *right);

int		check_argv(int argc, char const *argv[]);
void		init(t_data *ctrl, char const *argv[]);
void		free_tree(t_tree *root);

#endif /* !PARSER_H_ */
