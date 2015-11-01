/*
** inf_op.h for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/includes
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 22:12:08 2015 Nicolas Goudal
** Last update Sun Nov  1 15:17:48 2015 lin patrick
*/

#ifndef INF_OP_H_
# define INF_OP_H_

# ifndef PARSER_H_

#  define SYNTAXE_ERROR_MSG	"syntax error"
#  define ERROR_MSG		"Error"

typedef enum		e_sign
{
  PLUS = 1,
  MINUS = -1
}			t_sign;

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

typedef struct		s_op_nbr
{
  char			*nbr;
  t_sign		sign;
  int			length;
  int			fracidx;
}			t_op_nbr;

# endif /* !PARSER_H_ */

# define ACC			7

typedef struct		s_op_data
{
  t_op_nbr		*nbr1;
  t_op_nbr		*nbr2;
  t_op_nbr		*tmp;
  t_op_nbr		*result;
}			t_op_data;

typedef struct		s_op_and_fun
{
  t_op_enum		op;
  void			(*inf_op)(t_op_data *arg);
}			t_op_and_fun;


void		inf_add(t_op_data *ctrl);
void		inf_sub(t_op_data *ctrl);
void		inf_mult(t_op_data *ctrl);
void		inf_div(t_op_data *ctrl);
void		inf_mod(t_op_data *ctrl);
void		inf_div_int(t_op_data *ctrl);

char		*sub_op(t_op_nbr *res, t_op_nbr *nbr2);
int		div_op(t_op_nbr *div, t_op_nbr *tmp);

int		checkswap(t_op_nbr *nbr1, t_op_nbr *nbr2);
int		check_div(t_op_nbr *nbr1, t_op_nbr *nbr2);
void		check_frac(t_op_nbr *nbr1, t_op_nbr *nbr2);

void		char_shift(char *str, int length);
void		char_shift_to_the_left(t_op_nbr *nbr);
void		remove_zfrac(t_op_nbr *res);
void		a_to_i(char *str, int length);
void		i_to_a(char *str, int length);
void		copy_str(char *src, char *dest, int start, int min);
void		rev_copy_str(char *src, char *dest, int idxsrc, int idxdest);
void		clear_str(char *str, int length);

#endif /* !INF_OP_H_ */
