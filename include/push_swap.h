/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/24 23:58:37 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "colors.h"

typedef struct		s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_dlist
{
	size_t			lenght;
	struct s_node	*head;
	struct s_node	*tail;
}					t_dlist;

typedef struct		s_opt
{
	int				c;
	int				v;
	int				i;
}					t_opt;

typedef	struct		s_all
{
	t_dlist			*a;
	t_dlist			*b;
	t_opt			*opt;
	int				min;
	int				silent;
	size_t			nb_arg;
	int				ope;
}					t_all;

typedef struct		s_action
{
	char			*op;
	void			(*f)(t_all *);
}					t_action;
/*
*** ========= BONUS =========
*/
int					check_interactive_error(t_all *all, char *s);
int					get_op(t_all *all, char *buff);
void				display_interactive_start(void);
void				interactive_mode(t_all *all);
/*
*** init.c
*/
int					add_opt(t_opt *opt, char *s);
int					check_opt(t_opt *opt, char **av);
void				init_stack(t_all *all, t_dlist *lst, int ac, char **av);
t_opt				*init_opt(void);
t_all				*init_all(int ac, char **av);
/*
*** list.c
*/
t_dlist				*create_dlst(void);
t_node				*dlst_new(int data);
t_dlist				*dlst_add_back(t_dlist *lst, t_node *node);
t_dlist				*dlst_add_front(t_dlist *lst, t_node *node);
t_dlist				*dlst_del_one(t_dlist *lst, int data2del);
/*
*** display.c
*/
void				display_pile(t_all *all);
void				display_formatting(t_dlist *pile);
void				putaction(char *s);
void				putcolor(char *toput, char *color);
/*
*** sort.c
*/
int					a_is_sort(t_node *a);
int					count_moves(t_node *a, int val2find);
void				medium_sort(t_all *all);
void				op_mini_sort(t_all *all);
void				mini_sort(t_all *all);
/*
*** tools.c
*/
void				sort_parser(t_all *all);
void				swap_elem(t_node **first, t_node **next);
int					update_list(t_dlist *lst, t_node *elem);
int					find_min_value(t_node *a);
void				dlist_del(t_dlist **alst);
/*
*** r_op.c
*/
void				ra(t_all *all);
void				rra(t_all *all);
void				rb(t_all *all);
void				rrb(t_all *all);
/*
*** p_op.c
*/
void				pb(t_all *all);
void				pa(t_all *all);
/*
*** s_op.c
*/
void				sa(t_all *all);
void				sb(t_all *all);
/*
*** error.c
*/
void				error(char *err);
void				check_error(t_all *all);
void				check_doublons(t_node *pile, int val);

#endif
