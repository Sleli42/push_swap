/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/12 09:02:50 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_all *all, t_val *elem)
{
	lst_add_elem_front(&all->b, elem);
	lst_del_elem(&all->a);
	all->ope++;
	//ft_putstr("pb ");
}

void	pa(t_all *all, t_val *elem)
{
	lst_add_elem_front(&all->a, elem);
	lst_del_elem(&all->b);
	all->ope++;
	//ft_putstr("pb ");
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
		return (1);
		// ft_putstr("sa");
	}
	else if (tmp->val > last->val)
	{
		swap_elem(&tmp, &last);
		all->ope++;
		return (1);
		// ft_putstr("ra");
	}
	return (0);
}
