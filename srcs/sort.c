/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/11 00:19:40 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/23 08:49:02 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define A (all->a->head)
#define B (all->b->head)
#define LAST_A (all->a->tail)
#define LAST_B (all->b->tail)
#define MIN -1
#define MAX 1

int		search_value(t_all *all)
{
	t_node	*tmp;

	tmp = all->a->head;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->data == all->min)
			{
				all->push_min++;
				all->val2push = MIN;
				break ;
			}
			if (tmp->data == all->max)
			{
				all->push_max++;
				all->val2push = MAX;
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (tmp->data);
}

int		count_moves(t_node *a, int val2find)
{
	t_node	*tmp;
	int		move;

	tmp = a;
	move = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->data == val2find)
				return (move);
			tmp = tmp->next;
			move++;
		}
	}
	return (-1);
}

int		define_nb_moves_in_b(t_node *b, int val2insert)
{
	t_node	*tmp;
	int		move;

	tmp = b;
	move = 0;
	if (tmp)
	{
		while (tmp)
		{
			if (val2insert < b->data)
				move++;
			else
				break ;
			tmp = tmp->next;
		}
	}
	return (move);
}

void	push_value(t_all *all)
{
	int		move2b;
	int		tmp;

	move2b = 0;
	tmp = 0;
	if (!B)
		pb(all);
	else if (B && !B->next)
	{
		pb(all);
		if (B->data < B->next->data)
			sb(all);
	}
	else
	{
		if (all->push_min <= 1)
		{
			pb(all);
			rb(all);
		}
		else
		{
			if (all->val2push == MIN)
			{
				while (++tmp < all->push_min)
					rrb(all);
				display_pile(all);
				pb(all);
				while (tmp-- > 0)
					rb(all);
			}
			// if ((move2b = define_nb_moves_in_b(B, A->data)))
			// {
			// 	printf("move2b: %d\n", move2b);
			// 	if (move2b > (int)(all->b->lenght / 2))
			// 	{
			// 		while (tmp++ < move2b)
			// 			rrb(all);
			// 		display_pile(all);
			// 		pb(all);
			// 		while (tmp-- > 0)
			// 			rb(all);
			// 	}
			// 	else
			// 	{
			// 		while (tmp++ < move2b)
			// 			rb(all);
			// 		display_pile(all);
			// 		pb(all);
			// 		while (tmp-- > 0)
			// 			rrb(all);
			// 	}
			// }
		}
	}
}

void	try_sort(t_all *all)
{
	int		nb_moves;
	int		val2find;
	static int i = 0;

	display_pile(all);
	val2find = search_value(all);
	if ((nb_moves = count_moves(A, val2find)) != -1)
	{
		// printf("val2find: %d\n", val2find);
		// printf("push_min: %d\n", all->push_min);
		if (nb_moves > (int)(all->a->lenght / 2))
			while (A->data != val2find)
				rra(all);
		else
			while (A->data != val2find)
				ra(all);
	}
	push_value(all);
	all->min = find_min_value(A);
	all->max = find_max_value(A);
	all->val2push = 0;
	i++;
	if (i == 7)
		return ;
	try_sort(all);
}


/*
int		a_is_sort(t_node *a)
{
	t_node	*tmp;

	tmp = a;
	if (tmp)
	{
		while (tmp && tmp->next)
		{
			if (tmp->data < tmp->next->data)
				;
			else
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int		b_is_sort(t_node *b)
{
	t_node	*tmp;

	tmp = b;
	if (tmp)
	{
		while (tmp && tmp->next)
		{
			if (tmp->data > tmp->next->data)
				;
			else
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

void	try_bop(t_all *all)
{
	write(1, "\n", 1);
	printf("head: %d\n", B->data);
	printf("head->next: %d\n", B->next->data);
	printf("last: %d\n", LAST_B->data);
	printf("last->prev: %d\n", LAST_B->prev->data);
	exit(1);
}

void	pa_all(t_all *all)
{
	while (B)
	{
		if (B->data > A->data)
		{
			pa(all);
			if (A->data > A->next->data && A->data < A->next->next->data)
				sa(all);
			try_sort(all);
		}
		else
			pa(all);
	}
}

void	try_sort(t_all *all)
{
	static int	i = 0;
	int			tmp = all->ope;
	if (a_is_sort(A) && all->a->lenght == all->nb_arg)
		return ;
	check_stack_a(all);
	if (all->b->lenght >= 2)
	{
		check_stack_b(all);
		if (a_is_sort(A) && b_is_sort(B))
			pa_all(all);
	}
	if (tmp == all->ope)
	{
		pa(all);
		try_sort(all);
		// display_pile(all);
		// printf("NO OP\n"), exit(1);
	}
//	display_pile(all);
	i++;
	if (i == 1200)
		return ;
	try_sort(all);
}

void	check_stack_b(t_all *all)
{
	if (all->b->lenght == 2 && B->data < B->next->data)
			sb(all);
	else if (B->data < B->next->data)
	{
		if (B->data > LAST_B->data)
			sb(all);
		else if (B->data < LAST_B->data)
			rb(all);
	}
	else
	{
		if (!A || A->data < B->data)
			pa(all);
	}
}

void	check_stack_a(t_all *all)
{
	if (all->a->lenght == 2 && A->data > A->next->data)
		sa(all);
	else if (A->data > A->next->data)
	{
		if (A->data < LAST_A->data)
			sa(all);
		else if (A->data > LAST_A->data)
		{
			if (A->data > LAST_A->prev->data)
				ra(all);
			else
				rra(all);
		}
		else
			sa(all);
	}
	else if (A->data < A->next->data)
	{
		if (A->data > LAST_A->data)
		{
			if (LAST_A->data < LAST_A->prev->data)
				rra(all);
			else
				ra(all);
		}
	}
	else
	{
		if (!B || A->data > B->data)
			pb(all);
	}
}


*/



// void	try_sort(t_all *all)
// {
// 	int		tmp;

// 	tmp = (int)all->nb_arg;
// 	while (tmp-- > 0)
// 	{
// 		if (A->data < all->median)
// 			pb(all);
// 	}
// 	display_pile(all);
// 	check_op(all);
// 	exit(1);
// }

// void	check_op(t_all *all)
// {
// 	static int	i = 0;

// 	if (i == 10 || all->b->lenght == all->nb_arg)
// 		return ;
// 	if (all->a->lenght > 1 && all->b->lenght > 1)
// 		check_double(all);
// 	//display_pile(all);
// 	check_swap_or_rot(all);
// 	//display_pile(all);
// 	check_push(all);
// 	display_pile(all);
// 	i++;
// 	check_op(all);
// 	// check_swap_or_rot(all);
// }

// void	check_push(t_all *all)
// {
// 	if (A->data < A->next->data && A->data > B->data)
// 		pb(all);
// 	else if (A->data > A->next->data && A->data > B->data)
// 		pb(all);
// 	else if (B->data > B->next->data && B->data < A->data)
// 		pa(all);
// 	else if (B->data < B->next->data && B->data < A->data)
// 		pa(all);
// }

// void	check_double(t_all *all)
// {
// 	int	op;

// 	op = 0;
// 	if (A->data > A->next->data && B->data < B->next->data
// 		&& A->data < LAST_A->data && B->data > LAST_B->data)
// 		ss(all), op++;
// 	else if (A->data > A->next->data && B->data < B->next->data
// 		&& A->data > LAST_A->data && B->data < LAST_B->data)
// 		rr(all), op++;
// 	else if (A->data < A->next->data && B->data > B->next->data
// 		&& A->data > LAST_A->data && B->data < LAST_B->data)
// 		rr(all), op++;
// 	else if (LAST_A->data < LAST_A->prev->data && LAST_A->data < A->data
// 		&& LAST_B->data > LAST_B->prev->data && LAST_B->data > B->data)
// 		rrr(all), op++;
// 	if (op >= 1)
// 		check_double(all);
// }

// void	check_swap_or_rot(t_all *all)
// {
// 	int	op = 0;

// 	if (all->a->lenght > 1)
// 	{
// 		if (A->data > A->next->data && A->data < LAST_A->data)
// 			sa(all), op++;
// 		else if (A->data > LAST_A->data && A->data > A->next->data)
// 			ra(all), op++;
// 		else if (LAST_A->data < A->data)
// 			rra(all), op++;
// 	}
// 	if (all->b->lenght > 1)
// 	{
// 		if (B->data < B->next->data && B->data > LAST_B->data)
// 			sb(all), op++;
// 		else if (B->data < B->next->data && B->data < LAST_B->data)
// 			rb(all), op++;
// 		else if (LAST_B->data > B->data)
// 			rrb(all), op++;
// 	}
// 	if (op >= 1)
// 		check_swap_or_rot(all);
// }








/*
int		is_sort(t_val *pile, int tri)
{
	t_val	*tmp;

	tmp = pile;
	if (tri == 'a')
	{
		while (tmp && tmp->next)
		{
			if (tmp->val < tmp->next->val)
				tmp = tmp->next;
			else
				return (0);
		}
	}
	if (tri == 'b')
	{
		while (tmp && tmp->next)
		{
			if (tmp->val > tmp->next->val)
				tmp = tmp->next;
			else
				return (0);
		}
	}
	return (1);
}

void	mini_sort(t_all *all)
{
	if (is_sort(all->a, 'a') == 1)
	{
		if (len_lst(all->a) == (int)all->nb_arg)
			return ;
		else
		{
			if (is_sort(all->b, 'b') == 1 && all->b->val < all->a->val)
			{
				while (all->b != NULL)
					pa(all, lst_create_elem(all->b->val));
				return ;
			}
		}
	}
	if (check_stack_swap(all, all->a, all->b) == 1
		|| check_stack_rot(all, all->a, all->b) == 1)
		mini_sort(all);
	check_stack_push(all, all->a, all->b);
	mini_sort(all);
}

int	check_stack_rot(t_all *all, t_val *a, t_val *b)
{
	if (len_lst(a) > 1 && len_lst(b) > 1)
		if (a->val > goto_last(a)->val && b->val < goto_last(b)->val)
			return (rr(all, a, goto_last(a), b, goto_last(b)));
	if (len_lst(b) > 1)
		if (b->val < goto_last(b)->val)
			return (rb(all, b, goto_last(b)));
	if (len_lst(a) > 1)
		if (a->val > goto_last(a)->val)
			return (ra(all, a, goto_last(a)));
	return (0);
}

int	check_stack_swap(t_all *all, t_val *a, t_val *b)
{
	if (len_lst(a) > 1 && len_lst(b) > 1)
		if ((a->val > a->next->val && b->val < b->next->val))
			return (ss(all, a, b));
	if (len_lst(b) > 1)
		if (b->val < b->next->val)
		{
			if (b->val < goto_last(b)->val)
				return (0);
			return (sb(all, b));
		}
	if (len_lst(a) > 1)
		if (a->val > a->next->val)
		{
			if (a->val > goto_last(a)->val)
				return (0);
			return (sa(all, a));
		}
	return (0);
}

void	check_stack_push(t_all *all, t_val *a, t_val *b)
{
	if (b && all->it_to_b > 2)
	{
		if (b->val > b->next->val && b->val < a->val)
		{
			display_pile(all);
			pa(all, lst_create_elem(b->val));
		}
	}
	if (a)
	{
		if (a->val < a->next->val && all->it_to_b <= 2)
			pb(all, lst_create_elem(a->val));
		else if (a->val < a->next->val && a->val < b->val)
			pb(all, lst_create_elem(a->val));
	}
}

void	lulu_sort(t_all *all)
{
	int		ct;
	t_val	*tmp;

	ct = 0;
	tmp = all->a;
	if (tmp)
	{
		//printf("median : %d\n", all->median);
		while (ct < ((int)all->nb_arg / 2))
		{
			//printf("tmp->val: %d\n", tmp->val);
			pb(all, lst_create_elem(tmp->val));
			tmp = tmp->next;
			ct++;
		}
	}
	mini_sort(all);
}


void	sort_list(t_val **pile, int nb_elem)
{
	t_val	*tmp;

	tmp = *pile;
	while (nb_elem > 0)
	{
		while (tmp->next)
		{
			if (tmp->val > tmp->next->val)
				swap_elem(&tmp, &tmp->next);
			tmp = tmp->next;
		}
		nb_elem--;
		tmp = *pile;
	}
}
*/
