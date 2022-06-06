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

u_int16_t	get_the_first_index(t_stack *stk)
{
	t_stack		*temp_stk;
	t_stack		*temp_stk2;
	u_int16_t	i;

	temp_stk = stk;
	temp_stk2 = stk;
	while (temp_stk)
	{
		i = 0;
		temp_stk2 = stk;
		while (temp_stk2)
		{
			if (temp_stk->final_index > temp_stk2->final_index)
				++i;
			temp_stk2 = temp_stk2->next;
		}
		if (i == 0)
			return (temp_stk->final_index);
		temp_stk = temp_stk->next;
	}
	return (-1);
}

void	do_ra(t_all *all, u_int16_t pos)
{
	while (pos > 0)
	{
		print(ra(all));
		pos--;
	}
}

void	do_rra(t_all *all, u_int16_t pos)
{
	while (pos < all->total_index_a)
	{
		print(rra(all));
		++pos;
	}
}
