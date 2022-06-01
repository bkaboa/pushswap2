#include "../../Includes/pushswap.h"

u_int16_t	half_sup(t_all *all, u_int16_t half_stack)
{
	u_int16_t	i;
	t_stack		temp_final_stk;

	temp_final_stk = all->last_stk_a;
	i = 0;
	while (temp_final_stk->final_index > half)
	{
		temp_final_stk = temp_final_stk->previous;
		++i;
	}
	return (i);
}


u_int16_t	down_half(t_all *all, u_int16_t half_stack)
{
	u_int16_t	i;
	t_stack		temp_stk;

	temp_stk = all->stk_a;
	i = 0;
	while (temp->final_index > half_stack)
	{
		temp_stk = temp_stk->next;
		++i;
	}
	return (i);
}

void	push_half_stack(t_all *all)
{
	u_int16_t	half_stack;

	half_stack = all->total_index / 2;
