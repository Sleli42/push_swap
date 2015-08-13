/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/13 06:43:58 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pb(t_all *all, t_val *elem)
{
	lst_add_elem_front(&all->b, elem);
	// printf("elemcreate: %d\n", all->b->val);
	// printf("val2del: %d\n", all->a->val);
	// printf("first val: %d\n", all->a->val);
	lst_del_elem(&all->a);
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("pb ");
	return (1);
}

int		pa(t_all *all, t_val *elem)
{
	lst_add_elem_front(&all->a, elem);
	lst_del_elem(&all->b);
	all->ope++;
	if (all->nb_arg < 42)
		ft_putstr("pa ");
	return (1);
}

int		need2swap_or_rotate(t_all *all, t_val *last)
{
	t_val	*tmp;;

	tmp = all->a;
	//printf("%d && %d\n", tmp->val, tmp->next->val);
	if (tmp->val > tmp->next->val)
	{
		swap_elem(&tmp, &tmp->next);
		all->ope++;
		ft_putstr("sa");
		return (1);
	}
	else if (tmp->val > last->val)
	{
		swap_elem(&tmp, &last);
		all->ope++;
		ft_putstr("ra");
		return (1);
	}
	return (0);
}
