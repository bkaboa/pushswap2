/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:16:56 by czang             #+#    #+#             */
/*   Updated: 2022/06/09 19:24:14 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pushswap.h"

void	sort_under_100(t_all *all)
{
	u_int16_t	pos;
	u_int16_t	index;

	index = 1;
	while (all->total_index > 3)
	{
		pos = check_pos_first_arg(all, index);
		if (pos == 1)
		{
			print(sa(all));
			--pos;
		}
		if (pos == 0)
		{
			print(pb(all));
			++index;
		}
		else if ((all->total_index / pos) < 2)
			do_rra(all, pos);
		else
			do_ra(all, pos);
	}
	sort_3_num(all);
	while (all->stk_b)
		print(pa(all));
}
