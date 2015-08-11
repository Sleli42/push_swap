/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:33:48 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/11 21:45:49 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_val **b, t_val *elem, t_val **a, int val2del)
{
	lst_add_elem_front(b, elem);
	lst_del_elem(a, val2del);
}
