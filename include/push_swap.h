/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/05 23:55:13 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/05 23:55:15 by lubaujar         ###   ########.fr       */
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
	size_t		nb_arg;
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
// void		display_list(t_val *lst);
/*
*** display.c
*/
void		display_pile(t_all *all);
void		display_formatting(t_val *pile);
/*
*** error.c
*/
int			check_error(t_val *pile);
int			check_doublons(t_val *pile);

#endif
