/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/11 21:35:19 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lulu_sort(t_all *all)
{
	t_val	*tmp;
	int		ct;

	tmp = all->a;
	ct = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->val < all->median && tmp->prev == NULL)
				pb(&all->b, lst_create_elem(tmp->val), &all->a, tmp->val);
			tmp = tmp->next;
		}
	}
	display_pile(all);
}
