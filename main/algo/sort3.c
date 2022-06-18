/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:40:03 by czang             #+#    #+#             */
/*   Updated: 2022/06/16 18:30:30 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pushswap.h"

void	sort_2_num(t_all *all)
{
	u_int16_t	second_arg;
	u_int16_t	first_arg;

	first_arg = all->stk_a->final_index;
	second_arg = all->stk_a->next->final_index;
	if (first_arg < second_arg)
		print(sa(all));
}

void	sort_3_num(t_all *all)
{
	u_int8_t	i;
	u_int16_t	second_arg;
	u_int16_t	third_arg;
	u_int16_t	first_arg;

	first_arg = all->stk_a->final_index;
	second_arg = all->stk_a->next->final_index;
	third_arg = all->last_stk_a->final_index;
	if (first_arg < second_arg && second_arg < third_arg)
		return ;
	else if (second_arg < third_arg && first_arg < third_arg)
		i = 3;
	else if (first_arg < second_arg && third_arg < second_arg)
		i = 2;
	else
		i = 1;
	if (i == 1)
		print(ra(all));
	else if (i == 2)
		print(rra(all));
	if (check_stk(all->stk_a) == false)
		print(sa(all));
}
