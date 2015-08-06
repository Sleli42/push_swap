/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:20 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/06 05:12:29 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_val	*lst_create_elem(int nb)
{
	t_val	*elem;

	if (!(elem = (t_val*)malloc(sizeof(t_val))))
		printf("Malloc error (lst_create_elem)\n"), exit(0);
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

void	display_list(t_val *lst)
{
	t_val	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("->%d\n", tmp->val);
		tmp = tmp->next;
	}
}
