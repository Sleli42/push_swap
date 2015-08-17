/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/17 04:54:00 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_val	*create_stack(int ac, char **av)
{
	t_val	*lst;
	int		i;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] != '-' && ft_isdigit(av[i][0]) == 0)
			error("NO DIGIT");
		if (av[i][0] != '-' && ft_atoi(av[i]) == -1)
			error("OVERFLOW");
		else
			lst_add_elem_back(&lst, lst_create_elem(ft_atoi(av[i]))), i++;
	}
	return (lst);

}

t_all	*init_all(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		printf("Malloc error (init_all)\n"), exit(0);
	all->a = create_stack(ac, av);
	all->b = NULL;
	all->already_sort = create_stack(ac, av);
	//sort_list(&all->already_sort, (ac - 1));
	all->median = find_median(all->already_sort, ((ac - 1) / 2));
	all->nb_arg = ac - 1;
	all->ope = 0;
	all->it_to_b = 0;
	all->it_to_a = 0;
	all->silent = 0;
	return (all);
}
