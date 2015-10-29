/*
** do_inf_op.h for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/includes
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 21:07:53 2015 Nicolas Goudal
** Last update Thu Oct 29 21:34:57 2015 Nicolas Goudal
*/

#ifndef DO_INF_OP_H_
# define DO_INF_OP_H_

typedef	int		t_op_ctr;

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
  void			(*inf_op)(t_op_ctr *arg);
}			t_op_and_fun;

#endif /* !DO_INF_OP_H_ */
