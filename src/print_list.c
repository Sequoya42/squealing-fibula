/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/17 14:50:38 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/19 19:11:11 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void				choose_style(t_member *tmp, int fd)
{
		tputs(tgetstr("me", NULL), fd, tputs_putchar);
		if (tmp->current == 1)
		{
			ft_putstr_fd(KMAG, fd);
			tputs(tgetstr("us", NULL), fd, tputs_putchar);
		}
		if (tmp->selected == 1)
		{
			ft_putstr_fd(KGRN, fd);
			tputs(tgetstr("mr", NULL), fd, tputs_putchar);
		}
		if (tmp->current == 1 && tmp->selected == 1)
			ft_putstr_fd(KYEL, fd);

}

void				print_complete(int s, int f, int fd)
{
	while (s < f)
	{
		ft_putchar_fd('\t', fd);
		s += 4;
	}
}

void				print_format(t_member *tmp, int fd, t_select *s, int *m)
{
	int				n;

	n = 0;
	if (*m == 0)
	{
		*m = s->co;
		ft_putchar_fd('\n', fd);
		s->ty -= 1;
	}
	ft_putstr_fd(tmp->name, fd);
	n = tmp->len % 4;
	if (n != 0)
		ft_putchar_fd('\t', fd);
	print_complete((tmp->len + n), s->len_max, fd);
	*m -= 1;;
}

void			print_list(t_select *s)
{
	t_member	*tmp;
	int			fd;
	int			m;

	tmp = s->first;
	fd = s->fd;
	s->total_size = 0;
	s->tx = X;
	s->ty = Y;
	m = s->co;
	print_front(s);
	while (tmp != NULL)
	{
		choose_style(tmp, fd);
		if (tmp->len > X || X < HEAD_SIZE || Y < (s->nb_elem + 6))
		{
			window_too_small();
			break;
		}
		print_format(tmp, fd, s, &m);
		if (tmp == s->last)
			break ;
		tmp = tmp->next;
	}
}

