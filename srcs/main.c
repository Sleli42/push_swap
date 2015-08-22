/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/22 05:48:48 by lubaujar         ###   ########.fr       */
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
		try_sort(all);
		//test(all);
	//	test2(all);
		// display_pile(all);
		// choose_sort(all);
	}
	return (0);
}

void	test2(t_all *all)
{
 	size_t 	i = all->a->lenght + 1;

	display_pile(all);
	//sa(all);
	while (i--)
	{
		rra(all);
		display_pile(all);
	}
	//rr(all);
	//display_pile(all);
}
