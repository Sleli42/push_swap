/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/17 02:49:21 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
	if (is_sort(all->a, 'a') == 1)
	{
		if (len_lst(all->a) == (int)all->nb_arg)
			return ;
		else
		{
			if (is_sort(all->b, 'b') == 1 && all->b->val < all->a->val)
			{
				while (all->b != NULL)
					pa(all, lst_create_elem(all->b->val));
				return ;
			}
		}
	}
	if (check_stack_swap(all, all->a, all->b) == 1
		|| check_stack_rot(all, all->a, all->b) == 1)
		mini_sort(all);
	check_stack_push(all, all->a, all->b);
	mini_sort(all);
}

int	check_stack_rot(t_all *all, t_val *a, t_val *b)
{
	if (len_lst(a) > 1 && len_lst(b) > 1)
		if (a->val > goto_last(a)->val && b->val < goto_last(b)->val)
			return (rr(all, a, goto_last(a), b, goto_last(b)));
	if (len_lst(b) > 1)
		if (b->val < goto_last(b)->val)
			return (rb(all, b, goto_last(b)));
	if (len_lst(a) > 1)
		if (a->val > goto_last(a)->val)
			return (ra(all, a, goto_last(a)));
	return (0);
}

int	check_stack_swap(t_all *all, t_val *a, t_val *b)
{
	if (len_lst(a) > 1 && len_lst(b) > 1)
		if ((a->val > a->next->val && b->val < b->next->val))
			return (ss(all, a, b));
	if (len_lst(b) > 1)
		if (b->val < b->next->val)
		{
			if (b->val < goto_last(b)->val)
				return (0);
			return (sb(all, b));
		}
	if (len_lst(a) > 1)
		if (a->val > a->next->val)
		{
			if (a->val > goto_last(a)->val)
				return (0);
			return (sa(all, a));
		}
	return (0);
}

void	check_stack_push(t_all *all, t_val *a, t_val *b)
{
	if (b && all->it_to_b > 2)
	{
		if (b->val > b->next->val && b->val < a->val)
		{
			display_pile(all);
			pa(all, lst_create_elem(b->val));
		}
	}
	if (a)
	{
		if (a->val < a->next->val && all->it_to_b <= 2)
			pb(all, lst_create_elem(a->val));
		else if (a->val < a->next->val && a->val < b->val)
			pb(all, lst_create_elem(a->val));
	}
}

void	lulu_sort(t_all *all)
{
	int		ct;
	t_val	*tmp;

	ct = 0;
	tmp = all->a;
	if (tmp)
	{
		//printf("median : %d\n", all->median);
		while (ct < ((int)all->nb_arg / 2))
		{
			//printf("tmp->val: %d\n", tmp->val);
			pb(all, lst_create_elem(tmp->val));
			tmp = tmp->next;
			ct++;
		}
	}
	mini_sort(all);
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
*/