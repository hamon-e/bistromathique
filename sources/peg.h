/*
** peg.h for sources in /home/hamon_e/Piscine/Piscine_C_bistromathique/sources
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  Thu Oct 29 15:01:15 2015 Benoit Hamon
** Last update Thu Oct 29 15:01:15 2015 Benoit Hamon
*/

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
  t_sign	sign;
  int		lenght;
  char const	*nbr;
}		t_nbr;

typedef struct	s_op
{
  char		c;
}		t_op;

typedef struct	s_tree
{
  t_type	type;
  t_sign	sign;
  void		*data;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

typedef struct	s_data
{
  char const	*str;
  char const	*op_base;
  char const	*nbr_base;
}		t_data;

t_tree *pth(t_data *ctrl, int *index);
int	check_av(int ac, char const *av[]);
t_data		*init(const char *av[]);
int	calc(t_tree *racine);
t_tree *ope_low(t_data *ctrl, unsigned int *index);
