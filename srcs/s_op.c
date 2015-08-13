/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/13 06:44:35 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sa(t_all *all, t_val *pile)
{
	swap_elem(&pile, &pile->next);
	if (all->nb_arg < 42)
		ft_putstr("sa ");
	all->ope++;
	return (1);
}

int		sb(t_all *all, t_val *pile)
{
	swap_elem(&pile, &pile->next);
	if (all->nb_arg < 42)
		ft_putstr("sb ");
	all->ope++;
	return (1);
}

int		ss(t_all *all, t_val *a, t_val *b)
{
	swap_elem(&a, &a->next);
	swap_elem(&b, &b->next);
	if (all->nb_arg < 42)
		ft_putstr("ss ");
	all->ope++;
	return (1);
}
