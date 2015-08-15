/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/15 19:33:41 by lubaujar         ###   ########.fr       */
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
	all->it_to_b++;
	if (all->nb_arg < 42)
		ft_putstr("pb ");
	return (1);
}

int		pa(t_all *all, t_val *elem)
{
	lst_add_elem_front(&all->a, elem);
	lst_del_elem(&all->b);
	all->ope++;
	all->it_to_a++;
	if (all->nb_arg < 42)
		ft_putstr("pa ");
	return (1);
}
