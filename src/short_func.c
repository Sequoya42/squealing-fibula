/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 18:20:32 by rbaum             #+#    #+#             */
/*   Updated: 2015/10/17 19:24:50 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_select			*singleton(void)
{
	static t_select	s;

	return (&s);
}

int					tputs_putchar(int c)
{
	write(FD, &c, 1);
	return (1);
}

void				print_key(char buf[3])
{
	ft_putstr(ft_itoa(buf[0]));
	ft_putchar('\t');
	ft_putstr(ft_itoa(buf[1]));
	ft_putchar('\t');
	ft_putstr(ft_itoa(buf[2]));
	ft_putchar('\n');

}
