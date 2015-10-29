/*
** the_lib.h for bistromathique in /home/morty/rendu/Piscine_C_bistromathique/lib/includes
**
** Made by Nicolas Goudal
** Login   <goudal_n@epitech.net>
**
** Started on  Thu Oct 29 20:36:12 2015 Nicolas Goudal
** Last update Thu Oct 29 20:36:28 2015 Nicolas Goudal
*/

#ifndef THE_LIB_H_
# define THE_LIB_H_

# include <stdlib.h>

# define ERR_MSG_MALLOC		"error: malloc failed\n"
# define ERR_MSG_READ		"error: read failed\n"
# define ERR_MSG_WRITE		"error: write failed\n"


ssize_t			the_read(int fd, void *buf, size_t count);
ssize_t			the_write(int fd, const void *buf, size_t count);
void			*the_malloc(size_t size);
void			the_exit(int const exit_value, char const *str);

void			the_putchar(int const fd, char const c);
void			the_putstr(int const fd, char const *str);
void			the_putnbr(int const fd, int nbr);

unsigned int		the_strlen(char const *str);
int			the_strcmp(char const *s1, char const *s2);
int			the_atoi(char const *str);

#endif /* !THE_LIB_H_ */
