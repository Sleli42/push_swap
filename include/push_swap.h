/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/18 03:53:33 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct	s_dlist
{
	size_t			lenght;
	struct s_node	*head;
	struct s_node	*tail;
}				t_dlist;

typedef	struct	s_all
{
	t_dlist		*a;
	t_dlist		*b;
	int			silent;
	size_t		nb_arg;
	int			ope;
}				t_all;

void	test2(t_all *all);

/*
*** init.c
*/
void			init_stack(t_dlist *lst, int ac, char **av);
t_all			*init_all(int ac, char **av);
/*
*** list.c
*/
t_dlist			*create_dlst(void);
t_node			*dlst_new(int data);
t_dlist			*dlst_add_back(t_dlist *lst, t_node *node);
t_dlist			*dlst_add_front(t_dlist *lst, t_node *node);
t_dlist			*dlst_del_one(t_dlist *lst, int data2del);

/*
*** display.c
*/
void			display_pile(t_all *all);
void			display_formatting(t_dlist *pile);
/*
*** sort.c
*/
void			try_sort(t_all *all);
// int			is_sort(t_val *pile, int tri);
// void		mini_sort(t_all *all);
// int			check_stack_swap(t_all *all, t_val *a, t_val *b);
// void		check_stack_push(t_all *all, t_val *a, t_val *b);
// int			check_stack_rot(t_all *all, t_val *a, t_val *b);
// void		lulu_sort(t_all *all);
// void		sort_list(t_val **pile, int nb_elems);
/*
*** tools.c
*/
// void		choose_sort(t_all *all);
void			swap_elem(t_node **first, t_node **next);
// int			find_median(t_val *sorted, int val2stop);
// t_val		*goto_last(t_val *pile);
/*
*** r_op.c
*/
void			rr(t_all *all);
void			rrr(t_all *all);
void			ra(t_all *all);
void			rra(t_all *all);
void			rb(t_all *all);
void			rrb(t_all *all);
/*
*** p_op.c
*/
void			pb(t_all *all);
void			pa(t_all *all);
/*
*** s_op.c
*/
void			sa(t_all *all);
void			sb(t_all *all);
void			ss(t_all *all);
/*
*** error.c
*/
void			error(char *err);
void			check_error(t_all *all);
void			check_sort_params(t_node *pile, size_t lenght);
void			check_doublons(t_node *pile, int val);

#endif
