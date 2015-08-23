/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/23 08:29:04 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_dlist *lst, int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-' && ft_isdigit(av[i][0]) == 0)
			error("NO DIGIT");
		if (av[i][0] != '-' && ft_atoi(av[i]) == -1)
			error("OVERFLOW");
		else
			dlst_add_back(lst, dlst_new(ft_atoi(av[i]))), i++;
	}
}

t_all	*init_all(int ac, char **av)
{
	t_all	*all;
	t_dlist	*tmp;

	all = NULL;
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		printf("Malloc error (init_all)\n"), exit(0);
	all->a = create_dlst();
	all->b = create_dlst();
	tmp = create_dlst();
	init_stack(all->a, ac, av);
	init_stack(tmp, ac, av);
	all->nb_arg = ac - 1;
	all->already_sort = sort_list(tmp->head, (int)all->nb_arg);
	all->ope = 0;
	all->median = find_median(all->already_sort, (int)(all->nb_arg / 2));
	all->min = find_min_value(all->a->head);
	all->max = find_max_value(all->a->head);
	all->push_min = 0;
	all->push_max = 0;
	all->val2push = 0;
	all->silent = 0;
// 	printf("min %d && max: %d\n", all->min, all->max);
	return (all);
}

// + ====================== +
// Pile a:
// 	[ 0 ]
// 	[ 91 ]
// 	[ 356 ]
// 	[ 896 ]
// 	[ -42 ]
// 	[ 3 ]
// 	[ 211 ]
// Pile b:
// 	[ 21 ]
// 	[ 12 ]
// 	[ 7 ]
// 	[ -91 ]
// 	[ -411 ]
// + ====================== +
