/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/22 05:30:50 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void		pb(t_all *all)
{
	int		tmp;

	if (!all->a)
		return ;
	tmp = all->a->head->data;
	all->a = dlst_del_one(all->a, all->a->head->data);
	all->b = dlst_add_front(all->b, dlst_new(tmp));
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("pb ");
}

void		pa(t_all *all)
{
	int		tmp;

	if (!all->b)
		return ;
	tmp = all->b->head->data;
	all->b = dlst_del_one(all->b, all->b->head->data);
	all->a = dlst_add_front(all->a, dlst_new(tmp));
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("pa ");
}
