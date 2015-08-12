/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/12 05:50:55 by lubaujar         ###   ########.fr       */
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

void	rr(t_all *all, t_val *a, t_val *last_a, t_val *b, t_val *last_b)
{
	swap_elem(&a, &last_a);
	swap_elem(&b, &last_b);
	all->ope += 2;
}

void	rrr(t_all *all, t_val *a, t_val *last_a, t_val *b, t_val *last_b)
{
	swap_elem(&last_a, &a);
	swap_elem(&last_b, &b);
	all->ope += 2;
}

void	ra(t_all *all, t_val *a, t_val *last_a)
{
	swap_elem(&a, &last_a);
	all->ope++;
}

void	rb(t_all *all, t_val *b, t_val *last_b)
{
	swap_elem(&b, &last_b);
	all->ope++;
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
