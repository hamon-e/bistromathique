/*
** inf_op.h for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/includes
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 22:12:08 2015 Nicolas Goudal
** Last update Thu Oct 29 22:35:55 2015 Nicolas Goudal
*/

#ifndef INF_OP_H_
# define INF_OP_H_

# ifndef PARSER_H_

typedef enum		e_sign
{
  PLUS = 1,
  MINUS = -1
}			t_sign;

# endif /* !PARSER_H_ */

typedef enum		e_op_enum
{
  OP_OPEN_PARENT_IDX,
  OP_CLOSE_PARENT_IDX,
  OP_ADD_IDX,
  OP_SUB_IDX,
  OP_MULT_IDX,
  OP_DIV_IDX,
  OP_MOD_IDX,
  OP_ERROR_IDX
}			t_op_enum;

typedef struct		s_op_and_fun
{
  t_op_enum		op;
  void			(*inf_op)(t_op_data *arg);
}			t_op_and_fun;

typedef struct		s_op_nbr
{
  char			*nbr;
  t_sign		sign;
  int			length;
}			t_op_nbr;

typedef struct		t_op_data
{
  t_op_nbr		*nbr1;
  t_op_nbr		*nbr2;
  t_op_nbr		*tmp;
  t_op_nbr		*result;
}			t_op_data;


void		inf_add(t_op_data *ctrl);
void		inf_sub(t_op_data *ctrl);
void		inf_mult(t_op_data *ctrl);
void		inf_div(t_op_data *ctrl);
void		inf_mod(t_op_data *ctrl);

void		a_to_i(char *str, int length);
void		i_to_a(char *str, int length);
void		copy_str(char *src, char *dest, int start, int min);
void		rev_copy_str(char *src, char *dest, int idxsrc, int idxdest);
int		checkswap(t_nbr *nbr1, t_nbr *nbr2);
void		clear_str(char *str, int length);
char		*sub_op(t_nbr *res, t_nbr *nbr2);
char		*div_process(t_nbr *res, t_nbr *nbr1, t_nbr *nbr2, t_nbr *tmp);
void		char_shift(char *c, int length);
int		div_op(t_nbr *div, t_nbr *tmp);
int		check_div(t_nbr *nbr1, t_nbr *nbr2);

#endif /* !INF_OP_H_ */
