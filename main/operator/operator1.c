/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:30:36 by czang             #+#    #+#             */
/*   Updated: 2022/06/06 16:33:27 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pushswap.h"

string	pa(t_all *all)
{
	t_stack	*temp_b;

	if (!all->stk_b)
		return (NULL);
	temp_b = all->stk_b;
	all->total_index_a++;
	all->total_index_b--;
	all->first_index++;
	if (temp_b->next)
	{
		all->stk_b = temp_b->next;
		all->stk_b->previous = NULL;
	}
	all->stk_a->previous = temp_b;
	temp_b->next = all->stk_a;
	all->stk_a = temp_b;
	return ("pa\n");
}

string	pb(t_all *all)
{
	t_stack	*temp_a;

	temp_a = all->stk_a;
	all->stk_a = all->stk_a->next;
	all->stk_a->previous = NULL;
	temp_a->previous = NULL;
	all->total_index_a--;
	all->total_index_b++;
	all->first_index++;
	if (!all->stk_b)
	{
		temp_a->next = NULL;
		all->stk_b = temp_a;
		all->last_stk_b = temp_a;
		return ("pb\n");
	}
	temp_a->next = all->stk_b;
	all->stk_b->previous = temp_a;
	all->stk_b = temp_a;
	return ("pb\n");
}

string	rra(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->last_stk_a;
	all->last_stk_a = all->last_stk_a->previous;
	all->last_stk_a->next = NULL;
	all->stk_a->previous = temp_stk;
	temp_stk->next = all->stk_a;
	temp_stk->previous = NULL;
	all->stk_a = temp_stk;
	return ("rra\n");
}

string	rrb(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->last_stk_b;
	all->last_stk_b = all->last_stk_b->previous;
	all->last_stk_b->next = NULL;
	all->stk_b->previous = temp_stk;
	temp_stk->next = all->stk_b;
	temp_stk->previous = NULL;
	all->stk_b = temp_stk;
	return ("rrb\n");
}
