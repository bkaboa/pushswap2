/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upper500.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 20:04:38 by czang             #+#    #+#             */
/*   Updated: 2022/06/06 19:10:06 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pushswap.h"

static void	need_to_push(t_all *all, u_int16_t half_stack)
{
	u_int16_t		i;
	t_stack			*temp_stk;

	i = 0;
	temp_stk = all->stk_a;
	while (temp_stk->final_index > half_stack)
	{
		temp_stk = temp_stk->next;
		++i;
	}
	do_ra(all, i);
}

static void	need_to_push_2(t_all *all, u_int16_t half_stack)
{
	u_int16_t		i;
	t_stack			*temp_stk;

	i = 0;
	temp_stk = all->stk_b;
	while (temp_stk->final_index > half_stack)
	{
		temp_stk = temp_stk->next;
	}
	do_rb(all, i);

}

static void	check_operation_stk_b(t_all *all, u_int16_t half_stack)
{
	if (all->stk_b->next == NULL || all->stk_b->next->next == NULL)
		return ;
	if (all->stk_b->arg > all->stk_b->next->next->arg && \
			all->stk_a->final_index > half_stack)
	{
		print(rr(all));
		check_operation_stk_b(all, half_stack);
	}
	if (all->stk_b->arg > all->stk_b->next->next->arg)
	{
		print(rb(all));
		check_operation_stk_b(all, half_stack);
	}
	else if (all->stk_b->arg > all->stk_b->next->arg)
	{
		print(sb(all));
		check_operation_stk_b(all, half_stack);
	}
}

static void	check_operation_stk_a(t_all *all)
{
	if (all->stk_a->final_index == 1)
	{
		print(rra(all));
		all->total_index_a--;
		check_operation_stk_a(all);
	}
	if (all->stk_a->final_index == all->last_stk_a->final_index + 1)
	{
		print(rra(all));
		all->total_index_a--;
		check_operation_stk_a(all);
	}
	if (all->stk_a->final_index > all->stk_a->next->final_index)
		print(sa(all));
	if (all->stk_a->final_index == all->last_stk_a->final_index + 1)
	{
		print(rra(all));
		all->total_index_a--;
		check_operation_stk_a(all);
	}
}

void	big_first_sort(t_all *all)
{
	u_int16_t	half_stack;

		half_stack = (all->total_index_a + all->first_index) / 2;
		while (all->first_index <= half_stack)
		{
			need_to_push(all, half_stack);
			print(pb(all));
			check_operation_stk_b(all, half_stack);
		}
		return ;
		all->first_index = get_the_first_index(all->stk_b);
		half_stack = (all->total_index_b + all->first_index) / 2;
		while (all->first_index <= half_stack)
		{
			need_to_push_2(all, half_stack);
			print(pa(all));
			check_operation_stk_a(all);
		}
		all->first_index = get_the_first_index(all->stk_a);
	return ;
}
