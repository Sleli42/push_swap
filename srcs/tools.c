/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:16:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/18 03:53:04 by lubaujar         ###   ########.fr       */
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
void	swap_elem(t_node **first, t_node **next)
{
	int		tmp;

	tmp = (*first)->data;
	(*first)->data = (*next)->data;
	(*next)->data = tmp;
}

// int		find_median(t_val *sorted, int val2stop)
// {
// 	while (val2stop-- > 0)
// 		sorted = sorted->next;
// 	return (sorted->val);
// }
