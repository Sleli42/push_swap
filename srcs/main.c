/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/17 05:31:26 by sleli42          ###   ########.fr       */
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
		//test(all);
		test2(all);
		// display_pile(all);
		// choose_sort(all);
	}
	return (0);
}

void	test2(t_all *all)
{
	display_pile(all);
	//pb(all, lst_create_elem(all->a->val));
	//pb(all, lst_create_elem(all->a->val));
	//pb(all, lst_create_elem(all->a->val));
	rra(all);
	display_pile(all);
	rra(all);
	display_pile(all);
	//ra(all);
	//ra(all);
	//ra(all);
	//rra(all); 
	//rra(all);
	rra(all);
	display_pile(all);
//	rra(all);
	rra(all);
	//exit(3);
	//rrr(all);
	//rrr(all);
	display_pile(all);
	rra(all);
	display_pile(all);
	rra(all);
	display_pile(all);
	exit(1);
	ra(all);
	rb(all);
	display_pile(all);
	exit(1);
}
/*
int		check_double(t_all *all, t_val *a, t_val *b)
{
	if (!a || !b)
		return (0);
	if (len_lst(a) > 1 && len_lst(b) > 1)
	{
		if (a->val > a->next->val && a->val > goto_last(a)->val
			&& b->val < b->next->val && b->val > goto_last(b)->val)
			return (ss(all, a, b));
		else if (a->val > a->next->val && a->val < goto_last(a)->val
			&& b->val < b->next->val && b->val < goto_last(b)->val)
			return (rr(all, a, goto_last(a), b, goto_last(b)));
	}
	return (0);
}

void	check_a(t_all *all, t_val *a)
{
	if (a == NULL)
		return ;
	else if (len_lst(a) > 1)
	{
		if (a->val > a->next->val && a->val > goto_last(a)->val)
		{
			sa(all, a);
			check_a(all, a);
		}
		else if ((a->val > a->next->val && a->val < goto_last(a)->val)
			|| (a->val < a->next->val && a->val < goto_last(a)->val))
		{
			ra(all, a, goto_last(a));
			check_a(all, a);
		}
	}
	return ;
}

void	check_b(t_all *all, t_val *b)
{
	if (b == NULL)
		return ;
	if (len_lst(b) > 1)
	{
		if (b->val > b->next->val && b->val < goto_last(b)->val)
		{
			sb(all, b);
			check_b(all, b);
		}
		else if ((b->val > b->next->val && b->val > goto_last(b)->val)
			|| (b->val < b->next->val && b->val > goto_last(b)->val))
		{
			rb(all, b, goto_last(b));
			check_b(all, b);
		}
		else
			pa(all, lst_create_elem(b->val));
	}
	return ;
}

void	check_push(t_all *all, t_val *a, t_val *b)
{
	if (len_lst(a) > 1 && len_lst(b) >= 1)
	{
		if (len_lst(b) == 1)
		{
			if (a->val < a->next->val)
				pb(all, lst_create_elem(a->val));
		}
		else if (a->val < a->next->val && a->val > b->val && b->val > b->next->val)
				pb(all, lst_create_elem(a->val));
		else
			test(all);
	}
	else if (len_lst(a) > 1 && b == NULL)
	{
		pb(all, lst_create_elem(a->val));
		return ;
	}
	else if (len_lst(b) > 1 && len_lst(a) >= 1)
	{
		if (len_lst(a) == 1)
		{
			if (b->val > b->next->val)
				pa(all, lst_create_elem(b->val));
		}
		else if (b->val > b->next->val && b->val < a->val && a->val < a->next->val)
			pa(all, lst_create_elem(b->val));
		else
			test(all);
	}
	else if (len_lst(b) > 1 && a == NULL)
	{
		pa(all, lst_create_elem(b->val));
		return ;
	}
}

void	test(t_all *all)
{
	display_pile(all);
	if (check_double(all, all->a, all->b) != 0)
		test(all);
	else
	{
		check_a(all, all->a);
		check_b(all, all->b);
	}
	if (is_sort(all->a, 'a') && len_lst(all->a) == (int)all->nb_arg)
		exit (1);
	else
	{
		check_push(all, all->a, all->b);
		display_pile(all);
	}
	// pb(all, lst_create_elem(all->a->val));
	// pb(all, lst_create_elem(all->a->val));
	// display_pile(all);
	// if ((all->a->val > all->a->next->val && all->b->val < all->b->next->val))
	// 	ss(all, all->a, all->b);
	// // if (all->a->val > goto_last(all->a)->val && all->b->val < goto_last(all->b)->val)
	// // 	rr(all, all->a, goto_last(all->a), all->b, goto_last(all->b));
	// display_pile(all);
	// pa(all, lst_create_elem(all->b->val));
	// display_pile(all);
}
*/
/*
Pile a:
	[ 7 ]
	[ 8 ]
	[ 5 ]
	[ 2 ]
	[ 3 ]
	[ 6 ]
Pile b:
	[ 36 ]
	[ 22 ]

+ ====================== +
*/
