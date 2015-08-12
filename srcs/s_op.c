/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/12 21:14:34 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *all, t_val *pile)
{
	swap_elem(&pile, &pile->next);
	// ft_putstr("sa ");
	all->ope++;
}

void	sb(t_all *all, t_val *pile)
{
	swap_elem(&pile, &pile->next);
	// ft_putstr("sb ");
	all->ope++;
}

void	ss(t_all *all, t_val *a, t_val *b)
{
	swap_elem(&a, &a->next);
	swap_elem(&b, &b->next);
	// ft_putstr("ss ");
	all->ope++;
}
