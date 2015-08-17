/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleli42 <sleli42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/17 04:53:44 by sleli42          ###   ########.fr       */
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
	int			it_to_b;
	int			it_to_a;
	int			silent;
	size_t		nb_arg;
	int			ope;
}				t_all;

# define FIRST_A all->a->val
# define FIRST_B all->b->val
# define NEXT_A all->a->next->val
# define NEXT_B all->b->next->val
# define LAST_A (goto_last(all->a)->val)
# define LAST_B goto_last(all->b)->val

void	test(t_all *all);
int		check_double(t_all *all, t_val *a, t_val *b);
void	check_a(t_all *all, t_val *a);
void	check_b(t_all *all, t_val *b);
void	check_push(t_all *all, t_val *a, t_val *b);

void	test2(t_all *all);

/*
*** init.c
*/
t_val		*create_stack(int ac, char **av);
t_all		*init_all(int ac, char **av);
/*
*** list.c
*/
t_val		*lst_create_elem(int nb);
void		lst_add_elem_back(t_val **lst, t_val *new);
void		lst_add_elem_front(t_val **lst, t_val *new);
void		lst_del_elem(t_val **pile);
int			len_lst(t_val *lst);
/*
*** display.c
*/
void		display_pile(t_all *all);
void		display_formatting(t_val *pile);
/*
*** sort.c
*/
int			is_sort(t_val *pile, int tri);
void		mini_sort(t_all *all);
int			check_stack_swap(t_all *all, t_val *a, t_val *b);
void		check_stack_push(t_all *all, t_val *a, t_val *b);
int			check_stack_rot(t_all *all, t_val *a, t_val *b);
void		lulu_sort(t_all *all);
void		sort_list(t_val **pile, int nb_elems);
/*
*** tools.c
*/
void		choose_sort(t_all *all);
void		swap_elem(t_val **a, t_val **b);
int			find_median(t_val *sorted, int val2stop);
t_val		*goto_last(t_val *pile);
/*
*** r_op.c
*/
int			rr(t_all *all);
int			rrr(t_all *all);
int			ra(t_all *all);
int			rra(t_all *all);
int			rb(t_all *all);
int			rrb(t_all *all);
/*
*** r_op.c
*/
int			pb(t_all *all, t_val *elem);
int			pa(t_all *all, t_val *elem);
/*
*** s_op.c
*/
int			sa(t_all *all, t_val *a);
int			sb(t_all *all, t_val *b);
int			ss(t_all *all, t_val *a, t_val *b);
/*
*** error.c
*/
void		error(char *err);
void		check_error(t_all *all);
void		check_sort_params(t_val *pile, int nb_arg);
void		check_doublons(t_val *pile, int val);

#endif
