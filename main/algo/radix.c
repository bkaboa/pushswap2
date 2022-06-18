/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:16:42 by czang             #+#    #+#             */
/*   Updated: 2022/06/09 15:14:08 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pushswap.h"

void	radix(t_all *all)
{
	t_stack	*temp_a;
	t_stack	*temp_a2;
	int16_t	bit_place;

	bit_place = 1;
	temp_a = all->stk_a;
	temp_a2 = all->last_stk_a;
	while (check_stk(temp_a) == false)
	{
		if ((temp_a->final_index & bit_place) == 0)
			print(pb(all));
		else
			print(ra(all));
		if (temp_a->final_index == temp_a2->final_index)
		{
			temp_a2 = all->last_stk_a;
			while (all->stk_b)
				print(pa(all));
			bit_place *= 2;
		}
		temp_a = all->stk_a;
	}
	while (all->stk_b)
		print(pa(all));
}
