/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:16:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/14 01:23:58 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sort(t_all *all)
{
	if (all->nb_arg > 1 && all->nb_arg <= 6)
		mini_sort(all);
	display_pile(all);
	printf("nb ope: %d\n", all->ope);
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

t_val	*goto_last(t_val *pile)
{
	t_val	*tmp;

	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
