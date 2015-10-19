/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 13:04:44 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/19 19:34:38 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

#include "libft.h"
#include <termios.h>
#include <curses.h>
#include <term.h>
#include <signal.h>
#include <sys/ioctl.h>

# define SING		singleton()
# define FD			(SING->fd)

# define HEAD_SIZE	14

# define X			(s->w.ws_col)
# define Y			(s->w.ws_row)
# define CD			(buf[0] == 4 && buf[1] == 0 && buf[2] == 0)
# define ESC		(buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
# define DEL		(buf[0] == 127 && buf[1] == 0 && buf[2] == 0)
# define DEL2		(buf[0] == 126 && buf[1] == 0 && buf[2] == 0)
# define SPACE		(buf[0] == 32 && buf[1] == 0 && buf[2] == 0)
# define RET		(buf[0] == 10 && buf[1] == 0 && buf[2] == 0)
# define LEFT		(buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
# define UP			(buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
# define DOWN		(buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
# define RIGHT		(buf[0] == 27 && buf[1] == 91 && buf[2] == 67)

typedef struct		s_member
{
	char			*name;
	struct s_member	*next;
	struct s_member	*prev;
	int				selected;
	int				current;
	unsigned int	len;
	unsigned int	index;
}					t_member;

typedef struct		s_select
{
	t_member		*first;
	t_member		*last;
	t_member		*cur;
	struct winsize	w;
	struct termios	*term;
	unsigned int	co;
	int				fd;
	unsigned int	len_max;
	unsigned int	tx;
	unsigned int	ty;
	unsigned int	total_size;
	unsigned int	nb_elem;
}					t_select;

void				ft_init(char **av, t_select *s);
void				print_list(t_select *s);
void				print_key(char buf[3]);
void				sig_exit(int i);
void				ft_z(int i);
void				ft_fg(int i);
void				ft_resize(int i);
void				get_window_size(t_select *s);
void				window_too_small(void);
void				print_front(t_select *s);
void				ft_move(t_select *s, char buf[3]);
void				move_next(t_select *s);
int					tputs_putchar(int c);
int					modif_term(struct termios *term);
int					reset(struct termios *term);
int					get_key(t_select *s);
int					print_selected(t_select *s);
int					catch_events(t_select *s);

t_select			*singleton(void);

#endif
