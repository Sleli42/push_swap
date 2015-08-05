/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubaujar <lubaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/06 00:13:12 by lubaujar          #+#    #+#             */
/*   Updated: 2015/08/06 00:20:24 by lubaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_error(t_val *pile)
{
	if (pile)
	{
		if (check_doublons(pile) == -1)
			return (-1);
	}
}

int		check_doublons(t_val *pile)
{

}
