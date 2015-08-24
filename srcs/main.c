/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 02:58:38 by lubaujar         ###   ########.fr       */
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
		sort_parser(all);
		//printf("-> operations: [ %d ]\n", all->ope);
		ft_putstr("-> operations: [\e[1;31m ");
		ft_putnbr(all->ope);
		ft_putstr("\033[0m ]\n");
		dlist_del(&all->a);
		dlist_del(&all->b);
	}
	return (0);
}
