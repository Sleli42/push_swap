/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:02 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/18 03:19:54 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_formatting(t_dlist *pile)
{
	t_node	*tmp;

	tmp = pile->head;
	if (tmp == NULL)
		ft_putstr("\tempty pile\n");
	else
	{
		while (tmp)
		{
			ft_putstr("\t[ ");
			ft_putnbr(tmp->data);
			ft_putstr(" ]\n");
			tmp = tmp->next;
		}
	}
}

void	display_pile(t_all *all)
{
	write(1, "\n", 1);
	ft_putstr("+ ====================== +\n");
	ft_putstr("Pile a:\n");
	display_formatting(all->a);
	ft_putstr("Pile b:\n");
	display_formatting(all->b);
	ft_putstr("+ ====================== +\n");
}
