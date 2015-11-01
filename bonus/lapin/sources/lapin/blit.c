/*
** blit.c for lapin in /home/hamon_e/Piscine/Piscine_C_bistromathique/lapin
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  mer. oct. 28 22:07:18 2015 Benoit Hamon
** Last update mer. oct. 28 22:07:18 2015 Benoit Hamon
*/

#include <lapin.h>
#include <unistd.h>
#include "the_lapin.h"

void			loop(void *data)
{
  t_sfml		*sfml;
  t_bunny_position	pos;

  sfml = (t_sfml *)data;
  pos.x = 0;
  pos.y = SIZE_Y_TOP;
  bunny_blit(&sfml->img->windows->buffer, sfml->img->bot_screen, &pos);
  pos.y = 0;
  bunny_blit(&sfml->img->windows->buffer, sfml->img->top_screen, &pos);
  bunny_display(sfml->img->windows);
}

void			blit_n(t_sfml *sfml, t_bunny_position pos)
{
  bunny_blit(&sfml->img->bot_screen->buffer, sfml->img->cadre, &pos);
  loop(sfml);
  usleep(100000);
  bunny_blit(&sfml->img->bot_screen->buffer, sfml->img->cadre1, &pos);
  loop(sfml);
}
