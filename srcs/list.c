/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:20 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/13 05:57:29 by lubaujar         ###   ########.fr       */
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

int		len_lst(t_val *lst)
{
	t_val	*tmp;
	int		ret;

	tmp = lst;
	ret = 0;
	if (tmp)
	{
		while (tmp)
		{
			tmp = tmp->next;
			ret++;
		}
	}
	return (ret);
}

void	lst_del_elem(t_val **pile)
{
	t_val	*next;
	t_val	*curr;

	next = NULL;
	curr = *pile;
	if (curr && curr->next)
	{
		next = curr->next;
		next->prev = NULL;
		free(curr);
		curr = NULL;
	}
	*pile = next;
	// printf("[del]current->val: %d\n", (*pile)->val);
	// printf("[del]pile->next->val: %d\n", (*pile)->next->val);
	// if (*pile)
	// {
	// 	next = (*pile)->next;
	// 	free(*pile);
	// 	*pile = NULL;
	// 	printf("[del]next->val: %d\n", next->val);
	// 	printf("[del]pile->val: %d\n", (*pile)->val);
	// 	if ((*pile)->prev->val)
	// 		printf("[del]pile->prev->val: %d\n", (*pile)->prev->val);
	// }
	// *pile = next;
}
