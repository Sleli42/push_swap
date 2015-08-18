/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 00:13:12 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/18 01:24:28 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *err)
{
	if (ft_strcmp(err, "NO DIGIT") == 0)
		ft_putstr("Error\nmore infos: Params not digit\n"), exit(1);
	if (ft_strcmp(err, "DOUBLONS") == 0)
		ft_putstr("Error\nmore infos: Doublons\n"), exit(1);
	if (ft_strcmp(err, "SORT ON") == 0)
		ft_putstr("Error\nmore infos: Sort\n"), exit(1);
	if (ft_strcmp(err, "OVERFLOW") == 0)
		ft_putstr("Error\nmore infos: > int\n"), exit(1);
}

void	check_error(t_all *all)
{
	t_node	*tmp;
	size_t	i;

	tmp = all->a->head;
	i = 0;
	if (tmp)
	{
		check_sort_params(tmp, all->a->lenght);
		while (i < all->a->lenght)
		{
			check_doublons(all->a->head, tmp->data);
			i++;
			tmp = tmp->next;
		}
	}
}

void	check_sort_params(t_node *pile, size_t lenght)
{
	size_t		i;

	i = 0;
	if (pile)
	{
		while (pile->next)
		{
			if (pile->data < pile->next->data)
				i++;
			if (i == (lenght - 1) && pile->data < pile->next->data)
				error("SORT ON");
			pile = pile->next;
		}
	}
}

void	check_doublons(t_node *pile, int val)
{
	int		ret;

	ret = 0;
	if (pile)
	{
		while (pile)
		{
			if (pile->data == val)
				ret++;
			pile = pile->next;
		}
	}
	if (ret >= 2)
		error("DOUBLONS");
}
