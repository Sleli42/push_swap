/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:02 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/17 04:01:15 by sleli42          ###   ########.fr       */
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
	write(1, "\n", 1);
	ft_putstr("Pile a:\n");
	display_formatting(all->a);
	ft_putstr("Pile b:\n");
	display_formatting(all->b);
	ft_putstr("+ ====================== +\n");
}
