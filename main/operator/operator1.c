#include "../../Includes/pushswap.h"

void	pa(t_all *all)
{
	t_stack	*temp_b;

	if (!all->stk_b)
		return ;
	temp_b = all->stk_b;
	all->total_index++;
	if (temp_b->next)
	{
		all->stk_b = temp_b->next;
	}
	all->stk_a->previous = temp_b;
	temp_b->next = all->stk_a;
	all->stk_a = temp_b;
}

void	pb(t_all *all)
{
		t_stack	*temp_a;

	temp_a = all->stk_a;
	all->stk_a = all->stk_a->next;
	all->total_index--;
	if (!all->stk_b)
	{
		temp_a->next = NULL;
		all->stk_b = temp_a;
		return ;
	}
	temp_a->next = all->stk_b;
	all->stk_b->previous = temp_a;
	all->stk_b = temp_a;
}

void	ra(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->last_stk_a;
	all->last_stk_a = all->last_stk_a->previous;
	all->last_stk_a->next = NULL;
	all->stk_a->previous = temp_stk;
	temp_stk->next = all->stk_a;
	temp_stk->previous = NULL;
	all->stk_a = temp_stk;
}

void	rb(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->last_stk_b;
	all->last_stk_b = all->last_stk_b->previous;
	all->last_stk_b->next = NULL;
	all->stk_b->previous = temp_stk;
	temp_stk->next = all->stk_b;
	temp_stk->previous = NULL;
	all->stk_b = temp_stk;
}
