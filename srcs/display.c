/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:02 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 02:44:15 by lubaujar         ###   ########.fr       */
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

void	putcolor(char *s)
{
	if (ft_strcmp(s, "rra") == 0)
		ft_putstr("\e[1;32mrr\e[1;37ma\033[0m ");
	if (ft_strcmp(s, "ra") == 0)
		ft_putstr("\e[1;32mr\e[1;37ma\033[0m ");
	if (ft_strcmp(s, "rrb") == 0)
		ft_putstr("\e[1;32mrr\e[1;37mb\033[0m ");
	if (ft_strcmp(s, "rb") == 0)
		ft_putstr("\e[1;32mr\e[1;37mb\033[0m ");
	if (ft_strcmp(s, "pa") == 0)
		ft_putstr("\e[1;35mp\e[1;37ma\033[0m ");
	if (ft_strcmp(s, "pb") == 0)
		ft_putstr("\e[1;35mp\e[1;37mb\033[0m ");
	if (ft_strcmp(s, "sa") == 0)
		ft_putstr("\e[1;36ms\e[1;37ma\033[0m ");
	if (ft_strcmp(s, "sb") == 0)
		ft_putstr("\e[1;36ms\e[1;37mb\033[0m ");
}
