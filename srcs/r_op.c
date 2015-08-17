/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/17 04:05:07 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rr(t_all *all, t_val *a, t_val *b)
{
	(void)a;
	(void)b;
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("rr ");
	return (1);
}

int		rrr(t_all *all, t_val *a, t_val *b)
{
	(void)a;
	(void)b;
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("rrr ");
	return (1);
}

int		ra(t_all *all)
{
	lst_add_elem_back(&all->a, lst_create_elem(all->a->val));
	lst_del_elem(&all->a);
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("ra ");
	return (1);
}

int		rb(t_all *all)
{
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("rb ");
	return (1);
}
