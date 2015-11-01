/*
** result.c for sources in /home/hamon_e/Piscine/tmp/tmp/Piscine_C_bistromathique/lapin/sources
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  Sat Oct 31 18:05:47 2015 Benoit Hamon
** Last update Sat Oct 31 18:05:47 2015 Benoit Hamon
*/

#include <lapin.h>
#include "the_lib.h"
#include "the_lapin.h"

void				print_calc(t_sfml *sfml, int i)
{
  static t_bunny_position	pos;
  static int			bol = 0;

  if (!bol || sfml->res->data == '@')
  {
    pos.x = 0;
    pos.y = 0;
    bunny_blit(&sfml->img->top_screen->buffer,
	       sfml->img->top_screen_save,
	       &pos);
    pos.x = D_NBRS_X;
    pos.y = D_NBRS_Y;
    bol = 1;
  }
  if (pos.x - D_NBRS_X >= NBRS_X * 17)
  {
    bol = 0;
    print_calc(sfml, i);
  }
  else if (i != 13 && i != 18)
  {
    bunny_blit(&sfml->img->top_screen->buffer, sfml->img->boutons_img[i], &pos);
    pos.x += NBRS_X;
  }
}

static void			my_print(t_sfml *sfml, int i)
{
  print_calc(sfml, i);
  sfml->res->data = '1';
}

static void			print_res(t_sfml *sfml, t_op_nbr *result)
{
  char				*res;
  int				i;
  int				n;

  if (!result)
  {
    print_calc(sfml, 0);
    return ;
  }
  res = result->nbr;
  n = the_strlen(res);
  if (result->sign == MINUS)
    my_print(sfml, 16);
  if (n == result->fracidx)
    my_print(sfml, 0);
  i = -1;
  while (res[++i])
  {
    if (result->fracidx && i == n - result->fracidx)
      my_print(sfml, 19);
    my_print(sfml, res[i] - '0');
  }
}

void				calc_res(t_sfml *sfml)
{
  char				*res;

  res = list_to_str(sfml->res);
  sfml->res = new_elem('@');
  print_res(sfml, calc(sfml->ctrl, res));
  sfml->res->data = '@';
}
