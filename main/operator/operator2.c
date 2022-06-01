#include "../../Includes/pushswap.h"

void	sa(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->stk_a->next;
	all->stk_a->next = temp_stk->next;
	temp_stk->next = all->stk_a;
	all->stk_a->previous = temp_stk;
	all->stk_a = temp_stk;
	all->stk_a->previous = NULL;
}

void	sb(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->stk_b->next;
	all->stk_b->next = temp_stk->next;
	temp_stk->next = all->stk_b;
	temp_stk->previous = NULL;
	all->stk_b->previous = temp_stk;
	all->stk_b = temp_stk;
}

void	rb(t_all *all)
{
	t_stack	*temp_stk;

	temp_stk = all->stk_b->next;
	temp_stk->previous = NULL;
	all->stk_b->next = NULL;
	all->stk_b->previous = all->last_stk_b;
	all->last_stk_b->next = all->stk_b;
	all->last_stk_b = all->stk_b;
	all->stk_b = temp_stk;
}

void	ra(t_all *all)
{
	t_stack	*temp_stk;

	printf("\n\n\n");
	print_final_stk(all->last_stk_a);
	printf("\n\n\n");
	temp_stk = all->stk_a->next;
	temp_stk->previous = NULL;
	all->stk_a->next = NULL;
	all->stk_a->previous = all->last_stk_a;
	all->last_stk_a->next = all->stk_a;
	all->last_stk_a = all->stk_a;
	all->stk_a = temp_stk;
	printf("\n\n\n");
	print_final_stk(all->last_stk_a);
	printf("\n\n\n");
}
