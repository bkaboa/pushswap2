/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upper500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:04:38 by czang             #+#    #+#             */
/*   Updated: 2022/06/02 21:53:56 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pushswap.h"

static int16_t	need_to_push(t_all *all, u_int16_t half_stack)
{
	u_int16_t		i;
	u_int16_t		j;
	t_stack			*temp_stk;

	i = 0;
	j = 0;
	temp_stk = all->stk_a;
	while (temp_stk->final_index > half_stack)
	{
		temp_stk = temp_stk->next;
		++i;
	}
	temp_stk = all->last_stk_a;
	while (temp_stk->final_index > half_stack)
	{
		temp_stk = temp_stk->previous;
		++j;
	}
	if (i < j)
		return (i *= -1);
	return (j);
}

static void	do_ra_or_rra(t_all *all, int16_t index)
{
	if (index < 0)
		do_ra(all, index * -1);
	else
		do_rra(all, index);
}

static void	check_operation_stk_b(t_all *all)
{
	if (all->stk_b->next == NULL)
		return ;
	if (all->stk_b->arg > all->last_stk_b->arg)
		rrb(all);
	else if (all->stk_b->arg > all->stk_b->next->arg)
		sb(all);
}

void	big_first_sort(t_all *all)
{
	u_int16_t	half_stack;

	half_stack = (all->total_index / 2) - 1;
	dprintf(2, "%d\n",half_stack);
	while (all->first_index < half_stack)
	{
		do_ra_or_rra(all, need_to_push(all, half_stack));
		pb(all);
		printf("pb\n");
		check_operation_stk_b(all);
	}
	return ;
}
