/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/11 00:49:12 by lubaujar          #+#    #+#             */
/*   Updated: 2015/09/11 00:49:13 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*** ========= BONUS =========
*/

int		check_interactive_error(t_all *all, char *s)
{
	if (ft_strcmp(s, "rb") == 0 || ft_strcmp(s, "rrb") == 0)
		if (all->b->lenght < 2)
			return (-1);
	if (ft_strcmp(s, "ra") == 0 || ft_strcmp(s, "rra") == 0)
		if (all->a->lenght < 2)
			return (-1);
	if (ft_strcmp(s, "pa") == 0)
		if (all->b->lenght < 1)
			return (-1);
	if (ft_strcmp(s, "pb") == 0)
		if (all->a->lenght < 1)
			return (-1);
	if (ft_strcmp(s, "sa") == 0)
		if (all->a->lenght <= 1)
			return (-1);
	if (ft_strcmp(s, "sb") == 0)
		if (all->b->lenght <= 1)
			return (-1);
	return (0);
}

int		get_op(t_all *all, char *buff)
{
	int						i;
	static const t_action	action[] =

	{{"ra", ra},
	{"rb", rb},
	{"rra", rra},
	{"rrb", rrb},
	{"pa", pa},
	{"pb", pb},
	{"sa", sa},
	{"sb", sb}};
	i = 0;
	if (check_interactive_error(all, buff) == -1)
		return (0);
	while (i < 8)
	{
		if (ft_strcmp(action[i].op, buff) == 0)
		{
			all->all_ope = ft_strjoin(all->all_ope, action[i].op);
			all->all_ope = ft_strjoin(all->all_ope, " ");
			action[i].f(all);
			return (1);
		}
		i++;
	}
	return (0);
}

void	display_interactive_start(void)
{
	putcolor("\n\n\t\t== WELCOME TO THE INTERACTIVE MODE ==\
\n\n\tavailable ops: ", BOLD_RED);
	putcolor("'pa' 'pb' 'sa' 'sb' 'ra' 'rb' 'rra' 'rrb'\n", BOLD_GREEN);
	putcolor("\tUse `'control + C'` to quit.\n\n", BOLD_RED);
}

void	display_win(t_all *all)
{
	if (all->ope == 0)
	{
		putcolor("\n\t\t\tT'ES UN CONNARD =D !!\n\n", BOLD_RED);
		putcolor("opes: ", BOLD_RED);
		if (all->all_ope)
			ft_putstr(all->all_ope);
		else
			write(1, "\0", 1);
		putcolor("\nnb d'opes: ", BOLD_RED);
		ft_putnbr(all->ope);
		write(1, "\n", 1);
	}
	else
	{
		putcolor("\n\t\t\tT'ES UN WINNER !!\n\n", BOLD_RED);
		putcolor("opes: ", BOLD_RED);
		ft_putstr(all->all_ope);
		putcolor("\nnb d'opes: ", BOLD_RED);
		ft_putnbr(all->ope);
		write(1, "\n", 1);
	}
}

void	interactive_mode(t_all *all)
{
	char	*buff;

	buff = NULL;
	display_interactive_start();
	display_pile(all);
	while (91)
	{
		if (a_is_sort(all->a->head) && all->a->lenght == all->nb_arg)
		{
			display_win(all);
			exit(1);
		}
		putcolor("Enter an op: ", BROWN);
		while (get_next_line(0, &buff) > 0)
		{
			if (get_op(all, buff))
				display_pile(all);
			break ;
		}
	}
}

/*
*** ========= BONUS =========
*/