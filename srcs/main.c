/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/25 00:16:39 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac > 1)
	{
		all = init_all(ac, av);
		check_error(all);
		if (all->opt->i)
			interactive_mode(all);
		else
		{
			sort_parser(all);
			ft_putstr("-> operations: [ ");
			putcolor(ft_itoa(all->ope), BOLD_RED);
			ft_putstr(" ]\n");
		}
		dlist_del(&all->a);
		dlist_del(&all->b);
	}
	return (0);
}
