/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 00:13:12 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/11 04:48:38 by lubaujar         ###   ########.fr       */
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
	t_val	*tmp;
	int		i;

	tmp = all->a;
	i = 0;
	if (tmp)
	{
		check_sort_params(tmp, all->nb_arg);
		while (i < (int)all->nb_arg)
		{
			check_doublons(all->a, tmp->val);
			i++;
			tmp = tmp->next;
		}
	}
}

void	check_sort_params(t_val *pile, int nb_arg)
{
	int		i;

	i = 0;
	if (pile)
	{
		while (pile->next)
		{
			if (pile->val < pile->next->val)
				i++;
			if (i == (nb_arg - 1) && pile->val < pile->next->val)
				error("SORT ON");
			pile = pile->next;
		}
	}
}

void	check_doublons(t_val *pile, int val)
{
	int		ret;

	ret = 0;
	if (pile)
	{
		while (pile)
		{
			if (pile->val == val)
				ret++;
			pile = pile->next;
		}
	}
	if (ret >= 2)
		error("DOUBLONS");
}
