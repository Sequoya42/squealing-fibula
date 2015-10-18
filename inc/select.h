/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 13:04:44 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/18 22:15:32 by rbaum            ###   ########.fr       */
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

// Ctrl-C (in older Unixes, DEL) sends an INT
 // signal (SIGINT); by default, this causes the process to terminate.
// Ctrl-Z sends a TSTP signal (SIGTSTP); by default, 
// this causes the process to suspend execution.
/* • isatty */
/* • ttyname */
/* • ttyslot */
/* • ioctl */
/* • getenv */
/* • tcsetattr */
/* • tcgetattr */
/* • tgetent */
/* • tgetflag */
/* • tgetnum */
/* • tgetstr */
/* • tgoto */
/* • tputs */
/* • signal */

# define SING		singleton()
# define FD			(SING->fd)

# define CD			(buf[0] == 4 && buf[1] == 0 && buf[2] == 0)
# define ESC		(buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
# define DEL		(buf[0] == 127 && buf[1] == 0 && buf[2] == 0)
# define DEL2		(buf[0] == 126 && buf[1] == 0 && buf[2] == 0)
# define SPACE		(buf[0] == 32 && buf[1] == 0 && buf[2] == 0)
# define RET		(buf[0] == 10 && buf[1] == 0 && buf[2] == 0)
# define LEFT		(buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
# define UP			(buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
# define DOWN		(buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
# define RIGHT		(buf[0] == 27 && buf[1] == 91 && buf[2] == 07)

typedef struct		s_member
{
	char			*name;
	struct s_member	*next;
	struct s_member	*prev;
	int				selected;
	int				current;
}					t_member;

typedef struct		s_select
{
	t_member		*first;
	t_member		*last;
	t_member		*cur;
	int				sort;
	struct termios	term;
	int				height;
	int				width;
	int				fd;
	int				sig;
}					t_select;

void				print_list(t_member *f, t_member *l);
void				print_key(char buf[3]);
void				sig_exit(int i);
void				ft_z(int i);
void				ft_fg(int i);
void				ft_resize(int i);

int					tputs_putchar(int c);
int					modif_term(struct termios term);
int					reset(struct termios term);
int					get_key(t_select *s);
int					print_selected(t_select *s);

t_select			*ft_init(char **av);
t_select			*singleton(void);
int				catch_events(t_select *s);
#endif
