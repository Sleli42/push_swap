/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/14 01:28:43 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort(t_val *pile, int tri)
{
	t_val	*tmp;

	tmp = pile;
	if (tri == 'a')
	{
		while (tmp && tmp->next)
		{
			if (tmp->val < tmp->next->val)
				tmp = tmp->next;
			else
				return (0);
		}
	}
	if (tri == 'b')
	{
		while (tmp && tmp->next)
		{
			if (tmp->val > tmp->next->val)
				tmp = tmp->next;
			else
				return (0);
		}
	}
	return (1);
}

void	mini_sort(t_all *all)
{
	if (is_sort(all->a, 'a'))
	{
		if ((all->b == NULL && all->it_to_b > 1)
			|| (all->it_to_a == 0 && all->it_to_b == 0))
		{
			write(1, "\n", 1);
			return ;
		}
		if (all->b)
			pa(all, lst_create_elem(all->b->val));
	}
	else if (check_stack_swap_or_rot(all, all->a, all->b) == 0)
		if (check_stack_push(all, all->a, all->b) == 1)
			;
	mini_sort(all);
}

int		check_stack_swap_or_rot(t_all *all, t_val *a, t_val *b)
{
	if (len_lst(a) > 1 && len_lst(b) > 1)
		if ((a->val > a->next->val && b->val < b->next->val))
			return (ss(all, a, b));
	if (len_lst(b) > 1)
	{
		if (b->val < b->next->val)
		{
			if (b->val < goto_last(b)->val)
				return (rb(all, b, goto_last(b)));
			else
				return (sb(all, b));
		}
		else
			if (b->val < goto_last(b)->val)
				return (rb(all, b, goto_last(b)));
	}
	if (a->val > a->next->val)
	{
		if (a->val > goto_last(a)->val)
			return (ra(all, a, goto_last(a)));
		else
			return (sa(all, a));
	}
	else
		if (a->val > goto_last(a)->val)
			return (ra(all, a, goto_last(a)));
	return (0);
}

int		check_stack_push(t_all *all, t_val *a, t_val *b)
{
	if (all->it_to_b > (int)(all->nb_arg))
		if ((b->val > b->next->val && b->val < a->val))
			return (pa(all, lst_create_elem(b->val)));
	if (a && a->next)
	{
		if (b)
			if (a->val < a->next->val && a->val > b->val)
				return (pb(all, lst_create_elem(a->val)));
		if (a->val < a->next->val)
			return (pb(all, lst_create_elem(a->val)));
	}
	return (0);
}

void	lulu_sort(t_all *all)
{
	t_val	*tmp;

	tmp = all->a;
	if (tmp)
	{

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
