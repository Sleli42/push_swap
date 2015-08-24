/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 02:39:23 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_all *all)
{
	int		tmp;

	tmp = all->a->head->data;
	all->a = dlst_del_one(all->a, all->a->head->data);
	all->a = dlst_add_back(all->a, dlst_new(tmp));
	all->ope++;
	if (all->nb_arg < 42 && all->silent == 0)
	{
		if (all->opt->c)
			putcolor("ra");
		else
			ft_putstr("ra ");
	}
}

void		rra(t_all *all)
{
	int		tmp;

	tmp = all->a->tail->data;
	all->a = dlst_del_one(all->a, all->a->tail->data);
	all->a = dlst_add_front(all->a, dlst_new(tmp));
	all->ope++;
	if (all->nb_arg < 42 && all->silent == 0)
	{
		if (all->opt->c)
			putcolor("rra");
		else
			ft_putstr("rra ");
	}
}

void		rb(t_all *all)
{
	int		tmp;

	tmp = all->b->head->data;
	all->b = dlst_del_one(all->b, all->b->head->data);
	all->b = dlst_add_back(all->b, dlst_new(tmp));
	all->ope++;
	if (all->nb_arg < 42 && all->silent == 0)
	{
		if (all->opt->c)
			putcolor("rb");
		else
			ft_putstr("rb ");
	}
}

void		rrb(t_all *all)
{
	int		tmp;

	tmp = all->b->tail->data;
	all->b = dlst_del_one(all->b, all->b->tail->data);
	all->b = dlst_add_front(all->b, dlst_new(tmp));
	all->ope++;
	if (all->nb_arg < 42 && all->silent == 0)
	{
		if (all->opt->c)
			putcolor("rrb");
		else
			ft_putstr("rrb ");
	}
}

// void		rr(t_all *all)
// {
// 	all->silent = 1;
// 	ra(all);
// 	rb(all);
// 	all->ope--;
// 	if (all->nb_arg < 42 && all->silent == 1)
// 		ft_putstr("rr ");
// 	all->silent = 0;
// }

// void		rrr(t_all *all)
// {
// 	all->silent = 1;
// 	rra(all);
// 	rrb(all);
// 	all->ope--;
// 	if (all->nb_arg < 42 && all->silent == 1)
// 		ft_putstr("rrr ");
// 	all->silent = 0;
// }
