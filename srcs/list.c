/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:20 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/18 03:34:27 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*create_dlst(void)
{
	t_dlist	*new;

	new = (t_dlist*)malloc(sizeof(t_dlist));
	if (new != NULL)
	{
		new->lenght = 0;
		new->head = NULL;
		new->tail = NULL;
	}
	return (new);
}

t_dlist		*dlst_del_one(t_dlist *lst, int data2del)
{
	t_node	*tmp;
	int		found;

	tmp = lst->head;
	found = 0;
	if (lst)
	{
		while (tmp && !found)
		{
			if (tmp->data == data2del)
			{
				if (!tmp->next && tmp->prev)
				{
					lst->tail = tmp->prev;
					lst->tail->next = NULL;
				}
				else if (!tmp->prev && tmp->next)
				{
					lst->head = tmp->next;
					lst->head->prev = NULL;
				}
				else if (!tmp->next && !tmp->prev)
				{
					free(lst);
					lst = create_dlst();
					return (lst);
				}
				free(tmp);
				lst->lenght--;
				found = 1;
			}
			else
				tmp = tmp->next;
		}
	}
	return (lst);
}

t_node		*dlst_new(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new)
	{
		new->data = data;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

t_dlist		*dlst_add_back(t_dlist *lst, t_node *node)
{
	if (lst && node)
	{
		if (lst->tail == NULL)
		{
			lst->head = node;
			lst->tail = node;
		}
		else
		{
			lst->tail->next = node;
			node->prev = lst->tail;
			lst->tail = node;
		}
		lst->lenght++;
	}
	return (lst);
}

t_dlist		*dlst_add_front(t_dlist *lst, t_node *node)
{
	if (lst && node)
	{
		if (lst->tail == NULL)
		{
			lst->head = node;
			lst->tail = node;
		}
		else
		{
			lst->head->prev = node;
			node->next = lst->head;
			lst->head = node;
		}
		lst->lenght++;
	}
	return (lst);
}
