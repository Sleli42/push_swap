/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/17 05:12:34 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rr(t_all *all)
{
	all->silent = 1;
	ra(all);
	rb(all);
	all->ope--;
	if (all->nb_arg < 42 && all->silent == 1)
		ft_putstr("rr ");
	all->silent = 0;
	return (1);
}

int		rrr(t_all *all)
{
	all->silent = 1;
	rra(all);
	rrb(all);
	all->ope--;
	if (all->nb_arg < 42 && all->silent == 1)
		ft_putstr("rrr ");
	all->silent = 0;
	return (1);
}

int		ra(t_all *all)
{
	lst_add_elem_back(&all->a, lst_create_elem(all->a->val));
	lst_del_elem(&all->a);
	all->ope++;
	if (all->nb_arg < 42 && all->silent == 0)
		ft_putstr("ra ");
	return (1);
}

int		rra(t_all *all)
{
	t_val	*last;

	last = goto_last(all->a);
	lst_add_elem_front(&all->a, lst_create_elem(last->val));
	lst_del_elem(&last);
	all->ope++;
	if (all->nb_arg < 42 && all->silent == 0)
		ft_putstr("rra ");
	return (1);
}

int		rb(t_all *all)
{
	lst_add_elem_back(&all->b, lst_create_elem(all->b->val));
	lst_del_elem(&all->b);
	all->ope++;
	if (all->nb_arg < 42 && all->silent == 0)
		ft_putstr("rb ");
	return (1);
}

int		rrb(t_all *all)
{
	t_val	*last;

	last = goto_last(all->b);
	lst_add_elem_front(&all->b, lst_create_elem(last->val));
	lst_del_elem(&last);
	all->ope++;
	if (all->nb_arg < 42 && all->silent == 0)
		ft_putstr("rrb ");
	return (1);
}