/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 20:15:41 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define A (all->a->head)
#define B (all->b->head)
#define LAST_A (all->a->tail)
#define LAST_B (all->b->tail)
#define MIN -1
#define MAX 1

int		a_is_sort(t_node *a)
{
	t_node	*tmp;

	tmp = a;
	if (tmp)
	{
		while (tmp && tmp->next)
		{
			if (tmp->data > tmp->next->data)
				return (0);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int		count_moves(t_node *a, int val2find)
{
	t_node	*tmp;
	int		move;

	tmp = a;
	move = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->data == val2find)
				return (move);
			tmp = tmp->next;
			move++;
		}
	}
	return (-1);
}

void	medium_sort(t_all *all)
{
	if (all->opt->v && all->nb_arg < 42)
		display_pile(all);
	if (!A || a_is_sort(A))
	{
		while (B)
			pa(all);
		return ;
	}
	if (count_moves(A, all->min) > (int)(all->a->lenght / 2))
		while (A->data != all->min)
			rra(all);
	else
		while (A->data != all->min)
			ra(all);
	pb(all);
	all->min = find_min_value(A);
	medium_sort(all);
}

void	op_mini_sort(t_all *all)
{
	if (A->data > A->next->data)
	{
		if (A->data > LAST_A->data)
			ra(all);
		else
			sa(all);
	}
	else
	{
		if (A->data > LAST_A->data)
			ra(all);
		else
			pb(all);
	}
	mini_sort(all);
}

void	mini_sort(t_all *all)
{
	if (all->opt->v && all->nb_arg < 42)
		display_pile(all);
	if (!A || a_is_sort(A))
	{
		while (B)
		{
			pa(all);
			if (A->data > A->next->data)
				op_mini_sort(all);
		}
		return ;
	}
	op_mini_sort(all);
}
