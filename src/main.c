/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 13:05:52 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/19 19:28:20 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			print_front(t_select *s)
{
	tputs(tgetstr("me", NULL), s->fd, tputs_putchar);
	tputs(tgoto(tgetstr("cm", NULL), 0, 0), s->fd, tputs_putchar);
	tputs(tgetstr("cd", NULL), s->fd, tputs_putchar);
	tputs(tgetstr("us", NULL), s->fd, tputs_putchar);
	ft_putendl_fd("\tFt_select\n", s->fd);
	tputs(tgetstr("me", NULL), s->fd, tputs_putchar);
	ft_putstr_fd("X : \t", s->fd);
	ft_putnbr_fd(X, s->fd);
	ft_putstr_fd("\tY : \t", s->fd);
	ft_putnbr_fd(Y, s->fd);
	ft_putstr_fd("\ncolumn: \t", s->fd);
	ft_putnbr_fd(s->co, s->fd);
	ft_putstr_fd("\nindex:\t", s->fd);
	ft_putnbr_fd(s->cur->index , s->fd);
	ft_putendl_fd("\n-------------\n", s->fd);
}

int				catch_events(t_select *s)
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
