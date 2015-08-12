/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/12 21:41:19 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort(t_val *a, size_t nb_arg)
{
	size_t	ct;
	t_val	*tmp;

	ct = 0;
	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->val < tmp->next->val)
		{
			ct++;
		}
		tmp = tmp->next;
	}
	if (ct == nb_arg)
		return (1);
	return (0);
}

void	mini_sort(t_all *all, int size)
{
	t_val			*tmp;
	static int		ct = 0;

	tmp = all->a;
	if (tmp == NULL)
		return ;
	if (ct == size)
	{
		// if (is_sort(all->a, all->nb_arg) == 1)
		// {
			return ;
		//}
		// else
		// {
		// 	size = size + 5;
		// 	mini_sort(all, size);
		// }
	}
	else
	{
		check_stack_swap(all, all->a, all->b);
		if (check_stack_rotate(all, all->a, all->b))
		{
			ct++;
			mini_sort(all, size);;
		}
		else if (check_stack_push(all, all->a, all->b))
		{
			ct++;
			mini_sort(all, size);
		}
		else
		{
			printf("NO ope\n");
			return ;
		}
	}
}

void	check_stack_swap(t_all *all, t_val *a, t_val *b)
{
	if ((a->val > a->next->val && a->val < goto_last(a)->val)
		&& (b->val < b->next->val && b->val > goto_last(b)->val))
		ss(all, a, b);
	else
	{
		if (len_lst(b) > 1)
		{
			if (a->val > a->next->val && a->val < goto_last(a)->val)
				sa(all, a);
			if (b->val < b->next->val && b->val > goto_last(b)->val)
				sb(all, b);
		}
		else
			return ;
	}
}

int		check_stack_push(t_all *all, t_val *a, t_val *b)
{
	if ((a->val < a->next->val && b == NULL)
		|| (a->val < a->next->val && a->val > b->val))
	{
		pb(all, lst_create_elem(a->val));
		return (1);
	}
	return (0);
}

int		check_stack_rotate(t_all *all, t_val *a, t_val *b)
{
	if (a && b)
	{
		if (a->val > goto_last(a)->val && b->val < goto_last(b)->val)
		{
			rr(all, a, goto_last(a), b, goto_last(b));
			return (1);
		}
		if (a->val < goto_last(a)->val && b->val > goto_last(b)->val)
		{
			rrr(all, a, goto_last(a), b, goto_last(b));
			return (1);
		}
	}
	if (a)
	{
		if (a->val > goto_last(a)->val && b->val > goto_last(b)->val)
		{
			ra(all, a, goto_last(a));
			return (1);
		}
	}
	if (b)
	{
		if (a->val < goto_last(a)->val && b->val < goto_last(b)->val)
		{
			rb(all, b, goto_last(b));
			return (1);
		}
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
				if (check_stack_rotate(all, all->a, all->b) == 1)
					lulu_sort(all);
			}
			else if (need2swap_or_rotate(all, goto_last(all->a)))
				lulu_sort(all);
			else
				pb(all, lst_create_elem(tmp->val));
			tmp = tmp->next;
		}
					/* check all les opes */
		// if (check_stack(all, all->a, all->b,
		// 	goto_last(all->a), goto_last(all->a)) == 1)
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
