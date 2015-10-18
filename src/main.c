/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 13:05:52 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/18 22:15:35 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int				catch_events(t_select *s)
{
	while (1)
	{
		print_list(s->first, s->last);
		s->height = tgetnum("li");
		s->width = tgetnum("co");
		if ((get_key(s)) == 0 || s->sig == 1)
			return (1);
	}
	return (0);
}

int					main(int ac, char **av)
{
	t_select		*s;

	if (ac < 2)
		return (-1);
	// signal(SIGWINCH, ft_resize);
	signal(SIGTSTP, ft_z);
	signal(SIGCONT, ft_fg);
	signal(SIGINT, sig_exit);
	signal(SIGQUIT, sig_exit);
	s = ft_init(av);
	if (modif_term(s->term) == -1)
		ft_exit("failed modifying\n");
	catch_events(s);
	return (0);
}
