#include "../../Includes/pushswap.h"

bool	check_stk(t_stack *stk)
{
	t_stack		*temp;

	temp = stk;
	while (temp->next && temp->arg < temp->next->arg)
		temp = temp->next;
	if (!temp->next)
		return (true);
	return (false);
}

u_int16_t	check_pos_first_arg(t_all *all)
{
	u_int16_t	pos;
	t_stack		*temp_a;

	pos = 0;
	temp_a = all->stk_a;
	while (temp_a && temp_a->final_index != all->first_index)
	{
		++pos;
		temp_a = temp_a->next;
	}
	all->first_index++;
	return (pos);
}
