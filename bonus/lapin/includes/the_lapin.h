/*
** header.h for lapin in /home/hamon_e/Piscine/Piscine_C_bistromathique/lapin
** 
** Made by Benoit Hamon
** Login   <hamon_e@epitech.net>
** 
** Started on  mer. oct. 28 22:09:49 2015 Benoit Hamon
** Last update mer. oct. 28 22:09:49 2015 Benoit Hamon
*/

#ifndef HEADER_H_
# define HEADER_H_

# define NBRS_X		64
# define NBRS_Y		92
# define D_NBRS_X	60
# define D_NBRS_Y	60

# define SIZE_X		1245
# define SIZE_Y		857
# define SIZE_Y_TOP	199

# define BASE_X		42
# define BASE_Y		20
# define WHITE_X	29
# define WHITE_Y	20
# define IMG_X		265
# define IMG_Y		105

typedef struct		s_list
{
  char			data;
  struct s_list		*next;
}			t_list;

typedef struct		s_img
{
  t_bunny_window	*windows;
  t_bunny_picture	*top_screen;
  t_bunny_picture	*top_screen_save;
  t_bunny_picture	*bot_screen;
  t_bunny_picture	*cadre;
  t_bunny_picture	*cadre1;
  t_bunny_position	boutons_p[20];
  t_bunny_picture	*boutons_img[20];
}			t_img;

typedef struct		s_sfml
{
  t_list		*res;
  t_img			*img;
}			t_sfml;

t_list			*new_elem(char c);
void			free_list(t_list *res);
void			add_list(t_list *res, char c);
char			*list_to_str(t_list *res);

t_bunny_response	keyboard(t_bunny_event_state key,
				 t_bunny_keysym t,
				 void *data);
t_bunny_response	mouse(t_bunny_event_state key,
			      t_bunny_mousebutton t,
			      void *data);

void			init(t_sfml *sfml);

void			loop(void *data);
void			blit_n(t_sfml *sfml, t_bunny_position pos);
void			print_calc(t_sfml *sfml, int i);
void			calc_res(t_sfml *sfml);

char			*calc(char *str);

#endif /* !HEADER_H_ */
