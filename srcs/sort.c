/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/12 05:54:53 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_stack(t_all *all, t_val *a, t_val *b, t_val *end_a, t_val *end_b)
{
	if (a->val > end_a->val && b->val < end_b->val)
	{
		rr(all, a, end_a, b, end_b);
		return (1);
	}
	if (a->val < end_a->val && b->val > end_b->val)
	{
		rrr(all, a, end_a, b, end_b);
		return (1);
	}
	if (a->val > end_a->val && b->val > end_b->val)
	{
		ra(all, a, end_a);
		return (1);
	}
	if (a->val < end_a->val && b->val < end_b->val)
	{
		rb(all, b, end_b);
		return (1);
	}
	return (0);
}

void	lulu_sort(t_all *all)
{
	t_val	*tmp;

	tmp = all->a;
	if (tmp)
	{
		//printf("median: %d\n", all->median);
		//display_pile(all);
					/* equilibrer les piles */
		while (tmp && len_lst(tmp) > (int)(all->nb_arg / 2))
		{
			if (tmp->val <= all->median && tmp->prev == NULL)
				pb(all, lst_create_elem(tmp->val));
			if (len_lst(all->b) > 2)
			{
				if (check_stack(all, all->a, all->b,
					goto_last_elem(all->a), goto_last_elem(all->a)) == 1)
					lulu_sort(all);
			}
			else if (need2swap_or_rotate(all, goto_last_elem(all->a)))
				lulu_sort(all);
			else
				pb(all, lst_create_elem(tmp->val));
			tmp = tmp->next;
		}
					/* check all les opes */
		// if (check_stack(all, all->a, all->b,
		// 	goto_last_elem(all->a), goto_last_elem(all->a)) == 1)
		// {
		// 	printf("WOUHOU\n");
		// }
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
