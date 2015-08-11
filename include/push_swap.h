/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/11 19:59:55 by sleli42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_val
{
	int				val;
	struct s_val	*next;
	struct s_val	*prev;
}				t_val;

typedef	struct	s_all
{
	t_val		*a;
	t_val		*b;
	t_val		*already_sort;
	int			median;
	size_t		nb_arg;
	int			ope;
}				t_all;

/*
*** init.c
*/
t_val		*create_stack(int ac, char **av);
t_all		*init_all(int ac, char **av);
/*
*** list.c
*/
t_val		*lst_create_elem(int	nb);
void		lst_add_elem_back(t_val **lst, t_val *new);
void		lst_del_elem(t_val **a, int val2del);
void		sort_list(t_val **pile, int nb_elems);
/*
*** display.c
*/
void		display_pile(t_all *all);
void		display_formatting(t_val *pile);
/*
*** sort.c
*/
void		lulu_sort(t_all *all);
/*
*** tools.c
*/
void		choose_sort(t_all *all);
void		swap_elem(t_val **a, t_val **b);
int			find_median(t_val *sorted, int val2stop);
/*
*** operations.c
*/
void		pb(t_val **b, t_val *elem, t_val **a, int val2del);
/*
*** error.c
*/
void		error(char *err);
void		check_error(t_all *all);
void		check_sort_params(t_val *pile, int nb_arg);
void		check_doublons(t_val *pile, int val);

#endif
