/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 23:46:17 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_all *all)
{
	swap_elem(&all->a->head, &all->a->head->next);
	if (all->nb_arg < 42)
	{
		if (all->opt->c)
		{
			putcolor("s", BOLD_CYAN);
			putcolor("a", BOLD_LIGHT_GREY);
			write(1, " ", 1);
		}
		else
			ft_putstr("sa ");
	}
	all->ope++;
}

void		sb(t_all *all)
{
	swap_elem(&all->b->head, &all->b->head->next);
	if (all->nb_arg < 42)
	{
		if (all->opt->c)
		{
			putcolor("s", BOLD_CYAN);
			putcolor("b", BOLD_LIGHT_GREY);
			write(1, " ", 1);
		}
		else
			ft_putstr("sb ");
	}
	all->ope++;
}
