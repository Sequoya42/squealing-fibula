/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:47:19 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/18 22:14:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static t_member		*set_n(int i, char **t)
{
	t_member		*n;

	if (!(n = malloc(sizeof(t_member))))
		ft_exit("Failed malloc\n");
	n->name = ft_strdup(t[i]);
	n->next = NULL;
	n->prev = NULL;
	n->current = 0;
	n->selected = 0;
	return (n);
}

static void			fill_list(char **t, t_select *s)
{
	int				i;
	t_member		*n;

	i = 1;
	while (t[i])
	{
		n = set_n(i, t);
		if (i == 1)
		{
			n->current = 1;
			s->first = n;
			s->last = n;
			s->cur = s->first;
		}
		else
		{
			s->last->next = n;
			n->prev = s->last;
			s->last = n;
		}
		i++;
	}
}

static void		make_circular(t_select *s)
{
	s->last->next = s->first;
	s->first->prev = s->last;
}

t_select		*ft_init(char **av)
{
	t_select	*s;

	s = SING;
	fill_list(av, s);
	make_circular(s);
	if ((s->fd = open("/dev/tty", O_RDWR)) == -1)
		ft_exit("Bad file decriptor struct\n");
	s->sig = 0;
	return (s);
}


