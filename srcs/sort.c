/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/13 06:48:50 by lubaujar         ###   ########.fr       */
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
	// printf("%d && %d\n", ct, nb_arg);
	return (1);
}

void	mini_sort(t_all *all)
{
	static int		stop = 0;

	//printf("stop: %d\n", stop);
	// while (tmp)
	// {
	// 	printf("val: %d\n", tmp->val);
	// 	lst_del_elem(tmp);
	// 	tmp = tmp->next;
	// }
	// return ;
	// while (stop < (int)all->nb_arg || all->a != NULL)
	// {
	// 	stop += pb(all, lst_create_elem(all->a->val));
	// }
	//return ;
	if (is_sort(all->a, 'a') && len_lst(all->b) <= 2)
	{
		if (len_lst(all->b) == 1)
			pa(all, lst_create_elem(all->b->val));
		else
		{
			if (is_sort(all->b, 'b'))
			{
				while (all->b)
					pa(all, lst_create_elem(all->b->val)), all->b = all->b->next;
			}
			else
				mini_sort(all);
		}
		return ;
	}
	if (stop == 700000)
		return ;
	//write(1, "segfault\n", 9);
	if (check_stack_swap(all, all->a, all->b) == 0)
	{
		if (check_stack_push(all, all->a, all->b) == 1)
			stop++;
	}
	else
	{
		stop++;
		//write(1, "segfault\n", 9);
	}
	mini_sort(all);
}

int		check_stack_swap(t_all *all, t_val *a, t_val *b)
{
	if (len_lst(a) > 1 && len_lst(b) > 1)
	{
		if ((a->val > a->next->val && b->val < b->next->val))
			return (ss(all, a, b));
	}
	if (len_lst(b) > 1)
	{
		//write(1, "yolo0\n", 6);
		if (b->val < b->next->val)
		{
			if (b->val < goto_last(b)->val)
				return (rb(all, b, goto_last(b)));
			else
				return (sb(all, b));
		}
		else
		{
			if (b->val < goto_last(b)->val)
				return (rb(all, b, goto_last(b)));
		}
	}
	if (a->val > a->next->val)
	{
	//	write(1, "yolo1\n", 6);
		if (a->val > goto_last(a)->val)
			return (ra(all, a, goto_last(a)));
		else
		{
		//	write(1, "segfault\n", 9);
			return (sa(all, a));
		}
	}
	else
	{
	//	write(1, "yolo2\n", 6);
		if (a->val > goto_last(a)->val)
			return (ra(all, a, goto_last(a)));
	}
	return (0);
}

int		check_stack_push(t_all *all, t_val *a, t_val *b)
{
	if (b && b->next && is_sort(all->a, 'a'))
	{
		if (b->val > b->next->val && b->val < a->val)
			return (pa(all, lst_create_elem(b->val)));
	}
	if (a && a->next)
	{
		if (a->val < a->next->val)
			return (pb(all, lst_create_elem(a->val)));
	}
	return (0);
}

int		check_stack_rotate(t_all *all, t_val *a, t_val *b)
{
	if (a && b)
	{
		if (a->val > goto_last(a)->val && b->val < goto_last(b)->val)
			return (rr(all, a, goto_last(a), b, goto_last(b)));
		if (a->val < goto_last(a)->val && b->val < goto_last(b)->val)
			return (rrr(all, a, goto_last(a), b, goto_last(b)));
	}
	else if (a)
	{
		if (a->val > goto_last(a)->val)
			return (ra(all, a, goto_last(a)));
	}
	else if (b)
	{
		if (b->val < goto_last(b)->val)
			return (rb(all, b, goto_last(b)));
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
