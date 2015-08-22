/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/22 05:30:52 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_all *all)
{
	swap_elem(&all->a->head, &all->a->head->next);
	if (all->nb_arg < 42)
		ft_putstr("sa ");
	all->ope++;
}

void		sb(t_all *all)
{
	if (all->nb_arg < 42)
		ft_putstr("sb ");
	all->ope++;
}

void		ss(t_all *all)
{
	if (all->nb_arg < 42)
		ft_putstr("ss ");
	all->ope++;
}
