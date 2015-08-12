/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/12 09:02:50 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_val *pile)
{
	swap_elem(&pile, &pile->next);
	// ft_putstr("sa ");
}

void	sb(t_val *pile)
{
	swap_elem(&pile, &pile->next);
	// ft_putstr("sb ");
}

void	ss(t_val *a, t_val *b)
{
	swap_elem(&a, &a->next);
	swap_elem(&b, &b->next);
	// ft_putstr("ss ");
}