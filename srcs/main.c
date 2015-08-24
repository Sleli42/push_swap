/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 05:58:10 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_interactive_error(t_all *all, char *s)
{
	if (ft_strcmp(s, "rb") == 0 || ft_strcmp(s, "rrb") == 0)
	{
		if (all->b->lenght < 2)
			return (-1);
	}
	else if (ft_strcmp(s, "ra") == 0 || ft_strcmp(s, "rra") == 0)
	{
		if (all->a->lenght < 2)
			return (-1);
	}
	else if (ft_strcmp(s, "pa") == 0)
	{
		if (all->b->lenght < 1)
			return (-1);
	}
	else if (ft_strcmp(s, "pb") == 0)
	{
		if (all->a->lenght < 1)
			return (-1);
	}
	return (0);
}

int		get_op(t_all *all, char *buff)
{
	int		i;
	t_action	action[] = {
		{"ra", ra},
		{"rb", rb},
		{"rra", rra},
		{"rrb", rrb},
		{"pa", pa},
		{"pb", pb},
		{"sa", sa},
		{"sb", sb},
	};
	i = 0;

	if (check_interactive_error(all, buff) == -1)
		return (0);
	while (i < 8)
	{
		if (ft_strcmp(action[i].op, buff) == 0)
		{
			action[i].f(all);
			return (1);
		}
		i++;
	}
	return (0);
}

void	interactive_mode(t_all *all)
{
	char	*buff;

	buff = NULL;
	ft_putstr("\n\n\t\t\e[1;31mWELCOME TO THE INTERACTIVE MODE\033[0m\n\n");
	ft_putstr("\t\e[1;31mavailable ops:\e[1;32m 'pa' 'pb' 'sa' 'sb' 'ra' 'rb' 'rra' 'rrb'\033[0m\n");
	ft_putstr("\t\e[1;31mUse `'control + C'` to quit\033[0m\n\n");
	display_pile(all);
	while (91)
	{
		if (a_is_sort(all->a->head) && all->a->lenght == all->nb_arg)
		{
			ft_putstr("\n\t\e[1;31mT'ES UN WINNER !!\033[0m");
			ft_putstr("\n\t\e[1;31m8==============D\033[0m\n\n");
			exit (1);
		}
		ft_putstr("\e[0;33mEnter an op:\033[0m ");
		while (get_next_line(0, &buff) > 0)
		{
			if (get_op(all, buff))
				display_pile(all);
			break ;
		}
	}
}

int		main(int ac, char **av)
{
	t_all	*all;

	all = NULL;
	if (ac > 1)
	{
		all = init_all(ac, av);
		check_error(all);
		if (all->opt->i)
			interactive_mode(all);
		else
		{
			sort_parser(all);
			ft_putstr("-> operations: [\e[1;31m ");
			ft_putnbr(all->ope);
			ft_putstr("\033[0m ]\n");
		}
		dlist_del(&all->a);
		dlist_del(&all->b);
	}
	return (0);
}
