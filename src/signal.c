/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 19:37:59 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/18 22:16:22 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			sig_exit(int i)
{
	SING->sig = 1;
	reset(SING->term);
		ft_putendl("toto");
	exit(0);

	(void)i;
}
void			ft_z(int i)
{
	struct termios term;

	term = SING->term;
	char		arg[2];

	arg[0] = term.c_cc[VSUSP];
	arg[1] = '\0';
	if (isatty(FD))
	{
		tputs(tgetstr("ke", NULL), FD, tputs_putchar);
		tputs(tgetstr("te", NULL), FD, tputs_putchar);
		tputs(tgetstr("ve", NULL), FD, tputs_putchar);
		signal(SIGTSTP, SIG_DFL);
//		ioctl(FD, TIOCSTI, arg);
	 ioctl(FD, TIOCSTI, "\032");
	}
	(void)i;
}

void			ft_fg(int i)
{
	struct termios term;
	term = SING->term;
	modif_term(SING->term);
	signal(SIGTSTP, ft_z);
	print_list(SING->first, SING->last);
	(void)i;
}

void			ft_resize(int i)
{
	t_select	*s;

	s = SING;
	print_list(s->first, s->last);
	(void)i;
}	
