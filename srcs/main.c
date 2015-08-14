/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/15 01:10:43 by lubaujar         ###   ########.fr       */
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
		// test(all);
		display_pile(all);
		choose_sort(all);
	}
	return (0);
}


void	test(t_all *all)
{
	display_pile(all);
	pb(all, lst_create_elem(all->a->val));
	pb(all, lst_create_elem(all->a->val));
	display_pile(all);
	if ((all->a->val > all->a->next->val && all->b->val < all->b->next->val))
		ss(all, all->a, all->b);
	// if (all->a->val > goto_last(all->a)->val && all->b->val < goto_last(all->b)->val)
	// 	rr(all, all->a, goto_last(all->a), all->b, goto_last(all->b));
	display_pile(all);
	pa(all, lst_create_elem(all->b->val));
	display_pile(all);
}
