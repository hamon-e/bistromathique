/*
** event.c for lapin in /home/hamon_e/Piscine/Piscine_C_bistromathique/lapin
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  mer. oct. 28 22:01:28 2015 Benoit Hamon
** Last update mer. oct. 28 22:01:28 2015 Benoit Hamon
*/

#include <lapin.h>
#include "header.h"

char				get_opp(int i)
{
  if (i == 10)
    return ('(');
  if (i == 11)
    return (')');
  if (i == 12)
    return ('%');
  if (i == 13)
    return (0);
  if (i == 14)
    return ('/');
  if (i == 15)
    return ('*');
  if (i == 16)
    return ('-');
  if (i == 17)
    return ('+');
  if (i == 18)
    return ('=');
  if (i == 19)
    return ('.');
  return (0);
}

int				get_nbr(char c)
{
  if (c == '(')
    return (10);
  if (c == ')')
    return (11);
  if (c == '%')
    return (12);
  if (c == 0)
    return (13);
  if (c == '/')
    return (14);
  if (c == '*')
    return (15);
  if (c == '-')
    return (16);
  if (c == '+')
    return (17);
  if (c == '=')
    return (18);
  if (c == '.')
    return (19);
  return (-1);
}

static void			delele_calc(t_sfml *sfml)
{
  t_bunny_position		pos;

  pos.x = 0;
  pos.y = 0;
  bunny_blit(&sfml->img->top_screen->buffer, sfml->img->top_screen_save, &pos);
  free_list(sfml->res);
  sfml->res = new_elem('@');
}

static int			mouse_nbr(t_sfml *sfml, const t_bunny_position *pos)
{
  int				i;

  i = -1;
  while (++i < 20)
  {
    if (sfml->img->boutons_p[i].x <= pos->x && sfml->img->boutons_p[i].x + IMG_X >= pos->x)
      if (sfml->img->boutons_p[i].y <= pos->y && sfml->img->boutons_p[i].y + IMG_Y >= pos->y)
      {
	if (i == 13)
	  delele_calc(sfml);
	else if (i == 18)
	  calc_res(sfml);
	else
	{
	  print_calc(sfml, i);
	  if (i < 10)
	    add_list(sfml->res, i + '0');
	  else
	    add_list(sfml->res, get_opp(i));
	}
	blit_n(sfml, sfml->img->boutons_p[i]);
	return (0);
      }
  }
  return (1);
}

t_bunny_response		mouse(t_bunny_event_state key, t_bunny_mousebutton t, void *data)
{
  t_bunny_position		*pos;
  t_sfml			*sfml;

  if (key == 0)
    return (GO_ON);
  if (t != BMB_LEFT)
    return (GO_ON);
  sfml = (t_sfml *)data;
  pos = (t_bunny_position *)bunny_get_mouse_position();
  pos->y -= SIZE_Y_TOP;
  if (!mouse_nbr(sfml, pos))
    return (GO_ON);
  return (GO_ON);
}
