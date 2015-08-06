/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 00:13:12 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/06 05:12:21 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *err)
{
	if (ft_strcmp(err, "NO DIGIT") == 0)
		ft_putstr("Error\nmore infos: Params not digit\n"), exit(1);
	if (ft_strcmp(err, "DOUBLONS") == 0)
		ft_putstr("Error\nmore infos: Doublons\n"), exit(1);
}

void	check_error(t_all *all)
{
	t_val	*tmp;
	int		i;

	tmp = all->a;
	i = 0;
	if (tmp)
	{
		while (i < (int)all->nb_arg)
		{
			check_doublons(all->a, tmp->val);
			i++;
			tmp = tmp->next;
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
