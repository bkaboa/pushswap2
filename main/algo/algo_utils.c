/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:16:40 by czang             #+#    #+#             */
/*   Updated: 2022/06/09 18:46:35 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pushswap.h"

bool	check_stk(t_stack *stk)
{
	t_stack		*temp;

	temp = stk;
	while (temp->next && temp->final_index < temp->next->final_index)
		temp = temp->next;
	if (!temp->next)
		return (true);
	return (false);
}

u_int16_t	check_pos_first_arg(t_all *all, u_int16_t index)
{
	u_int16_t	pos;
	t_stack		*temp_a;

	pos = 0;
	temp_a = all->stk_a;
	while (temp_a && temp_a->final_index > index)
	{
		++pos;
		temp_a = temp_a->next;
	}
	return (pos);
}

void	do_ra(t_all *all, u_int16_t pos)
{
	while (pos > 0)
	{
		print(ra(all));
		pos--;
	}
}

void	do_rra(t_all *all, u_int16_t pos)
{
	while (pos < all->total_index)
	{
		print(rra(all));
		++pos;
	}
}
