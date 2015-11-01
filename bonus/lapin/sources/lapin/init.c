/*
** init.c for lapin in /home/hamon_e/Piscine/Piscine_C_bistromathique/lapin
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  mer. oct. 28 21:49:15 2015 Benoit Hamon
** Last update Sun Nov  1 22:47:31 2015 lin patrick
*/

#include <lapin.h>
#include <stdio.h>
#include "the_lapin.h"

static void	the_sprintf(char *s1, char *s2, int nb)
{
  int		i;

  i = 0;
  while (s2[i])
  {
    if (s2[i] == '%')
    {
      s1[i] = nb / 10 + '0';
      s1[i + 1] = nb % 10 + '0';
      i++;
    }
    else
      s1[i] = s2[i];
    i++;
  }
  s1[i] = 0;
}

static void	init_img_nbr(t_img *img)
{
  int		i;
  char		*str;

  i = 0;
  str = malloc(sizeof(char) * 17);
  img->top_screen = bunny_load_picture("lapin/img/top_screen.bmp");
  img->top_screen_save = bunny_load_picture("lapin/img/top_screen.bmp");
  img->bot_screen = bunny_load_picture("lapin/img/bot_screen.bmp");
  img->cadre = bunny_load_picture("lapin/img/cadre.png");
  img->cadre1 = bunny_load_picture("lapin/img/cadre1.png");
  while (i < 20)
  {
    if (i != 13 && i != 18)
    {
      the_sprintf(str, "lapin/img/%d.bmp", i);
      img->boutons_img[i] = bunny_load_picture(str);
    }
    else
      img->boutons_img[i] = 0;
    i++;
  }
  free(str);
}

static void	init_pos_nbr(t_img *img)
{
  int		i;
  int		j;
  int		k;

  img->boutons_p[0].x = BASE_X + (IMG_X + WHITE_X) * 0;
  img->boutons_p[0].y = BASE_Y + (IMG_Y + WHITE_Y) * 4;
  k = 1;
  i = 3;
  while (i > 0)
  {
    j = 0;
    while (j < 3)
    {
      img->boutons_p[k].x = BASE_X + (IMG_X + WHITE_X) * j;
      img->boutons_p[k].y = BASE_Y + (IMG_Y + WHITE_Y) * i;
      ++j;
      ++k;
    }
    --i;
  }
}

static void	init_img_opp(t_img *img)
{
  img->boutons_p[10].x = BASE_X + (IMG_X + WHITE_X) * 0;
  img->boutons_p[10].y = BASE_Y + (IMG_Y + WHITE_Y) * 0;
  img->boutons_p[11].x = BASE_X + (IMG_X + WHITE_X) * 1;
  img->boutons_p[11].y = BASE_Y + (IMG_Y + WHITE_Y) * 0;
  img->boutons_p[12].x = BASE_X + (IMG_X + WHITE_X) * 2;
  img->boutons_p[12].y = BASE_Y + (IMG_Y + WHITE_Y) * 0;
  img->boutons_p[13].x = BASE_X + (IMG_X + WHITE_X) * 3;
  img->boutons_p[13].y = BASE_Y + (IMG_Y + WHITE_Y) * 0;
  img->boutons_p[14].x = BASE_X + (IMG_X + WHITE_X) * 3;
  img->boutons_p[14].y = BASE_Y + (IMG_Y + WHITE_Y) * 1;
  img->boutons_p[15].x = BASE_X + (IMG_X + WHITE_X) * 3;
  img->boutons_p[15].y = BASE_Y + (IMG_Y + WHITE_Y) * 2;
  img->boutons_p[16].x = BASE_X + (IMG_X + WHITE_X) * 3;
  img->boutons_p[16].y = BASE_Y + (IMG_Y + WHITE_Y) * 3;
  img->boutons_p[17].x = BASE_X + (IMG_X + WHITE_X) * 3;
  img->boutons_p[17].y = BASE_Y + (IMG_Y + WHITE_Y) * 4;
  img->boutons_p[18].x = BASE_X + (IMG_X + WHITE_X) * 2;
  img->boutons_p[18].y = BASE_Y + (IMG_Y + WHITE_Y) * 4;
  img->boutons_p[19].x = BASE_X + (IMG_X + WHITE_X) * 1;
  img->boutons_p[19].y = BASE_Y + (IMG_Y + WHITE_Y) * 4;
}

void		init_sfml(t_sfml *sfml)
{
  sfml->img = malloc(sizeof(t_img));
  sfml->img->windows = bunny_start(SIZE_X, SIZE_Y, false, "Easystromatik");
  sfml->img->top_screen = bunny_new_picture(SIZE_X, NBRS_Y);
  sfml->img->bot_screen = bunny_new_picture(SIZE_X, 857);
  init_img_nbr(sfml->img);
  init_pos_nbr(sfml->img);
  init_img_opp(sfml->img);
  sfml->res = new_elem('@');
}
