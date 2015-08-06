/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/06 05:12:25 by lubaujar         ###   ########.fr       */
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
		// if (av[i][0] <= '0' && av[i][0] >= '9')
		// 	printf("av[i] = %s\n", av[i]), exit(1);
		if (ft_isdigit(av[i][0]) == 0)
			error("NO DIGIT");
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
	all->nb_arg = ac - 1;
	return (all);
}
