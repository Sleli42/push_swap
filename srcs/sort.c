/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/11 23:42:06 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lulu_sort(t_all *all)
{
	t_val	*tmp;

	tmp = all->a;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->val <= all->median && tmp->prev == NULL) /* PUSH B FCT */
				pb(all, lst_create_elem(tmp->val), tmp->val);
			else
				break ;
			tmp = tmp->next;
		}
		if (len_lst(all->a) > len_lst(all->b))
		{
			if (need2swap(all) == 1)
				lulu_sort(all);
		}
		else
			return ;
	}
}


void	sort_list(t_val **pile, int nb_elem)
{
	t_val	*tmp;

	tmp = *pile;
	while (nb_elem > 0)
	{
		while (tmp->next)
		{
			if (tmp->val > tmp->next->val)
				swap_elem(&tmp, &tmp->next);
			tmp = tmp->next;
		}
		nb_elem--;
		tmp = *pile;
	}
}
