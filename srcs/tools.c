/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:16:17 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 04:26:48 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_parser(t_all *all)
{
	if (all->nb_arg <= 6)
		mini_sort(all), write(1, "\n", 1);
	else
		medium_sort(all), write(1, "\n", 1);
	if (all->opt->v && all->nb_arg > 6 && all->nb_arg < 42)
		display_pile(all);
}

void	swap_elem(t_node **first, t_node **next)
{
	int		tmp;

	tmp = (*first)->data;
	(*first)->data = (*next)->data;
	(*next)->data = tmp;
}

void	dlist_del(t_dlist **alst)
{
	t_node	*temp;
	t_node	*del;

	temp = (*alst)->head;
	if (*alst && temp)
	{
		while (temp)
		{
			del = temp;
			temp = temp->next;
			free(del);
		}
		free(*alst);
		*alst = NULL;
	}
}

int		find_min_value(t_node *a)
{
	t_node	*tmp;
	int		min;

	tmp = a;
	min = 0;
	if (tmp)
	{
		min = tmp->data;
		tmp = tmp->next;
		while (tmp)
		{
			if (tmp->data < min)
				min = tmp->data;
			tmp = tmp->next;
		}
	}
	return (min);
}
