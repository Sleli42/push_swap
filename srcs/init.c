/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/18 03:20:03 by lubaujar         ###   ########.fr       */
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

	all = NULL;
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		printf("Malloc error (init_all)\n"), exit(0);
	all->a = create_dlst();
	all->b = create_dlst();
	init_stack(all->a, ac, av);
	all->nb_arg = ac - 1;
	all->ope = 0;
	all->silent = 0;
	return (all);
}
