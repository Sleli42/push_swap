/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/13 06:43:37 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		rr(t_all *all, t_val *a, t_val *last_a, t_val *b, t_val *last_b)
{
	swap_elem(&a, &last_a);
	swap_elem(&b, &last_b);
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("rr ");
	return (1);
}

int		rrr(t_all *all, t_val *a, t_val *last_a, t_val *b, t_val *last_b)
{
	swap_elem(&last_a, &a);
	swap_elem(&last_b, &b);
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("rrr ");
	return (1);
}

int		ra(t_all *all, t_val *a, t_val *last_a)
{
	swap_elem(&a, &last_a);
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("ra ");
	return (1);
}

int		rb(t_all *all, t_val *b, t_val *last_b)
{
	swap_elem(&b, &last_b);
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("rb ");
	return (1);
}
