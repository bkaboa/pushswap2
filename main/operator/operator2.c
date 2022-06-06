#include "../../Includes/pushswap.h"

string	sa(t_all *all)
{
	t_stack	*temp_stk1;
	t_stack	*temp_stk2;

	temp_stk1 = all->stk_a->next;
	temp_stk2 = all->stk_a->next->next;
	temp_stk2->previous = all->stk_a;
	all->stk_a->next = temp_stk2;
	all->stk_a->previous = temp_stk1;
	temp_stk1->next = all->stk_a;
	temp_stk1->previous = NULL;
	all->stk_a = temp_stk1;
	return ("sa\n");
}

string	sb(t_all *all)
{
	t_stack	*temp_stk1;
	t_stack	*temp_stk2;

	temp_stk1 = all->stk_b->next;
	temp_stk2 = all->stk_b->next->next;
	temp_stk2->previous = all->stk_b;
	all->stk_b->next = temp_stk2;
	all->stk_b->previous = temp_stk1;
	temp_stk1->next = all->stk_b;
	temp_stk1->previous = NULL;
	all->stk_b = temp_stk1;
	return ("sb\n");
}

string	rb(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->stk_b->next;
	temp_stk->previous = NULL;
	all->stk_b->next = NULL;
	all->stk_b->previous = all->last_stk_b;
	all->last_stk_b->next = all->stk_b;
	all->last_stk_b = all->stk_b;
	all->stk_b = temp_stk;
	return ("rb\n");
}

string	ra(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->stk_a->next;
	temp_stk->previous = NULL;
	all->stk_a->next = NULL;
	all->stk_a->previous = all->last_stk_a;
	all->last_stk_a->next = all->stk_a;
	all->last_stk_a = all->stk_a;
	all->stk_a = temp_stk;
	return ("ra\n");
}
