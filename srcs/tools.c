/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:16:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/11 23:20:50 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_all *all)
{
	if (all->nb_arg >= 10)
	{
		ft_putstr("\n\nsort >= 10 params:\n\n");
		lulu_sort(all);
	}
	display_pile(all);
}

void	swap_elem(t_val **a, t_val **b)
{
	int		tmp;

	tmp = (*a)->val;
	(*a)->val = (*b)->val;
	(*b)->val = tmp;
}

int		find_median(t_val *sorted, int val2stop)
{
	while (val2stop-- > 0)
		sorted = sorted->next;
	return (sorted->val);
}

int		need2swap(t_all *all)
{
	t_val	*tmp;;

	tmp = all->a;
	if (tmp->val > tmp->next->val)
	{
		swap_elem(&tmp, &tmp->next);
		all->ope++;
		return (1);
		// ft_putstr("sa");
	}
	return (0);
}
