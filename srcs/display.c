/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:02 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/14 01:11:45 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_formatting(t_val *pile)
{
	if (pile)
	{
		while (pile)
		{
			ft_putstr("\t[ ");
			ft_putnbr(pile->val);
			ft_putstr(" ]\n");
			pile = pile->next;
		}
	}
	else
		ft_putstr("\tempty pile\n");
}

void	display_pile(t_all *all)
{
	ft_putstr("Pile a:\n");
	display_formatting(all->a);
	ft_putstr("Pile b:\n");
	display_formatting(all->b);
	ft_putstr("+ ====================== +\n");
}
