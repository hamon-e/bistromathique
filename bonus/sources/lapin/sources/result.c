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
#include <string.h>
#include "header.h"

void			print_calc(t_sfml *sfml, int i)
{
  static t_bunny_position	pos;
  static int			bol = 0;

  if (!bol || sfml->res->data == '@')
  {
    pos.x = 0;
    pos.y = 0;
    bunny_blit(&sfml->img->top_screen->buffer, sfml->img->top_screen_save, &pos);
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

static void		print_res(t_sfml *sfml, char *res)
{
  while (*res)
  {
    print_calc(sfml, *res - '0');
    sfml->res->data = '1';
    ++res;
  }
  sfml->res->data = '@';
}

void			calc_res(t_sfml *sfml)
{
  char	*res;

  res = list_to_str(sfml->res);
  sfml->res = new_elem('@');
  print_res(sfml, calc(res));
}
