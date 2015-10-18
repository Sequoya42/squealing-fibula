/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:50:38 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/18 21:55:57 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			print_list(t_member *f, t_member *l)
{
	t_member	*tmp;
	int			fd;

	tmp = f;
	fd = FD;
	tputs(tgetstr("cl", NULL), fd, tputs_putchar);
	while (tmp != NULL)
	{
		tputs(tgetstr("me", NULL), fd, tputs_putchar);
		if (tmp->current == 1)
			tputs(tgetstr("us", NULL), fd, tputs_putchar);
		if (tmp->selected == 1)
			tputs(tgetstr("mr", NULL), fd, tputs_putchar);
		ft_putendl_fd(tmp->name, fd);
		tputs(tgetstr("cr", NULL), fd, tputs_putchar);
		if (tmp == l)
			break ;
		tmp = tmp->next;
	}
}

int			print_selected(t_select *s)
{
	t_member		*tmp;
	int				l;

	tmp = s->first;
	reset(s->term);
	l = 0;
	tputs(tgetstr("me", NULL), FD, tputs_putchar);
	while (tmp != NULL)
	{
		if (tmp->selected == 1)
		{
			l = 1;
			ft_putstr(tmp->name);
			ft_putchar(' ');
		}
		tmp = tmp->next;
		if (tmp == s->last->next)
		{
			if (l == 1)
				ft_putchar('\n');
			break;
		}
	}
	return (0);
}