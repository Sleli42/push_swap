/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:08 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 02:46:32 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_opt(t_opt *opt, char **av)
{
	int		i;
	int		ret;

	i = 1;
	ret = 1;
	while (av[i] && av[i][0] == '-' && ft_isdigit(av[1][1]) == 0)
	{
		if (av[i][1] == 'c' && opt->c != 1)
		{
			if (av[i][2] == 'v' && opt->v != 1)
				opt->v = 1;
			opt->c = 1, ret++;
		}
		else if (av[i][1] == 'v' && opt->v != 1)
		{
			if (av[i][2] == 'c' && opt->c != 1)
				opt->c = 1;
			opt->v = 1, ret++;
		}
		else
			error("BAD OPT");
		i++;
	}
	return (ret);
}

void	init_stack(t_all *all, t_dlist *lst, int ac, char **av)
{
	int	i;

	i = check_opt(all->opt, av);
	if (i == ac)
		error("NO ENTRY");
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

t_opt	*init_opt(void)
{
	t_opt	*opt;

	opt = NULL;
	if (!(opt = (t_opt *)malloc(sizeof(t_opt))))
		error("MALLOC");
	opt->c = 0;
	opt->v = 0;
	return (opt);
}


t_all	*init_all(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (!(all = (t_all *)malloc(sizeof(t_all))))
		error("MALLOC");
	all->a = create_dlst();
	all->b = create_dlst();
	all->opt = init_opt();
	init_stack(all, all->a, ac, av);
	all->nb_arg = ac - 1;
	all->ope = 0;
	all->min = find_min_value(all->a->head);
	all->silent = 0;
	return (all);
}
