/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:20 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/11 21:58:07 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_val	*lst_create_elem(int nb)
{
	t_val	*elem;

	if (!(elem = (t_val*)malloc(sizeof(t_val))))
		return (NULL);
	elem->val = nb;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	lst_add_elem_back(t_val **lst, t_val *new)
{
	t_val	*tmp;

	tmp = *lst;
	if (new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
		}
	}
	else
		return ;
}

void	lst_add_elem_front(t_val **lst, t_val *new)
{
	t_val	*tmp;

	tmp = *lst;
	if (new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			new->prev = NULL;
			new->next = (*lst);
			*lst = new;
		}
	}
	else
		return ;
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

void	lst_del_elem(t_val **pile, int val2del)
{
	t_val	*tmp;

	tmp = *pile;
	while (tmp)
	{
		if (tmp->val == val2del)
		{
			if (tmp->next == NULL)
				tmp->prev->next = NULL;
			else if (tmp->prev == NULL)
			{
				(*pile) = tmp->next;
				(*pile)->prev = NULL;
				(*pile)->next = tmp->next->next;
			}
			else
			{
				tmp->prev->next = tmp->next;
				tmp->next->prev = tmp->prev;
			}
			free (tmp);
			return ;
		}
		else
			tmp = tmp->next;
	}
}
