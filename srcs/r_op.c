/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 23:46:20 by lubaujar         ###   ########.fr       */
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
		{
			putcolor("r", BOLD_GREEN);
			putcolor("a", BOLD_LIGHT_GREY);
		}
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
		{
			putcolor("rr", BOLD_GREEN);
			putcolor("a", BOLD_LIGHT_GREY);
		}
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
		{
			putcolor("r", BOLD_GREEN);
			putcolor("b", BOLD_LIGHT_GREY);
		}
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
		{
			putcolor("rr", BOLD_GREEN);
			putcolor("b", BOLD_LIGHT_GREY);
		}
		else
			ft_putstr("rrb ");
	}
}
