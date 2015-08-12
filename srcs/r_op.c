/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/12 09:03:40 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_all *all, t_val *a, t_val *last_a, t_val *b, t_val *last_b)
{
	swap_elem(&a, &last_a);
	swap_elem(&b, &last_b);
	all->ope++;
	// ft_putstr("rr ");
}

void	rrr(t_all *all, t_val *a, t_val *last_a, t_val *b, t_val *last_b)
{
	swap_elem(&last_a, &a);
	swap_elem(&last_b, &b);
	all->ope++;
	// ft_putstr("rrr ");
}

void	ra(t_all *all, t_val *a, t_val *last_a)
{
	swap_elem(&a, &last_a);
	all->ope++;
	// ft_putstr("ra ");
}

void	rb(t_all *all, t_val *b, t_val *last_b)
{
	swap_elem(&b, &last_b);
	all->ope++;
	// ft_putstr("rb ");
}