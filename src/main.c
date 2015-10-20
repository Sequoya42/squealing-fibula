/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 13:05:52 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/20 19:29:15 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void				print_front(t_select *s)
{
	int				i;
	int				siz;

	i = 0;
	siz = (X / 2) - 4;
	tputs(tgetstr("me", NULL), s->fd, tputs_putchar);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), s->fd, tputs_putchar);
	tputs(tgetstr("cd", NULL), s->fd, tputs_putchar);
	while (i < siz)
	{
		ft_putstr_fd(" ", s->fd);
		i += 1;
	}
	ft_putstr_fd(KBOLD, s->fd);
	ft_putstr_fd(K42, s->fd);
	ft_putstr_fd(KCYN, s->fd);
	ft_putendl_fd("Ft_select\n", s->fd);
	tputs(tgetstr("me", NULL), s->fd, tputs_putchar);
}

static int			catch_events(t_select *s)
{
	while (1)
	{
		print_list(s);
		if ((get_key(s)) == 0)
			return (1);
	}
	return (0);
}

int					main(int ac, char **av)
{
	t_select		*s;

	if (ac < 2)
		return (-1);
	signal(SIGWINCH, ft_resize);
	s = SING;
	ft_init(av, s);
	signal(SIGTSTP, ft_z);
	signal(SIGCONT, ft_fg);
	signal(SIGINT, sig_exit);
	signal(SIGQUIT, sig_exit);
	catch_events(s);
	return (0);
}
