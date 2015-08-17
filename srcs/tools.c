/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:16:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/17 02:50:28 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	choose_sort(t_all *all)
{
	if (all->nb_arg > 1 && all->nb_arg <= 8)
		mini_sort(all);
	else
		lulu_sort(all);
	display_pile(all);
	printf("nb ope: %d\n", all->ope);
}
*/
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
