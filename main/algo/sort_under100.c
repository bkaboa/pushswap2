#include "../../Includes/pushswap.h"

void	sort_under_100(t_all *all)
{
	u_int16_t	pos;
	t_stack		*temp_b;

	while (all->total_index_a > 3)
	{
		pos = check_pos_first_arg(all);
		if (pos == 1)
			print(sa(all));
		else if (((double) all->total_index_a / pos) <= 2)
			do_rra(all, pos);
		else
			do_ra(all, pos);
		print(pb(all));
	}
	sort_3_num(all);
	temp_b = all->stk_b;
	while (temp_b)
	{
		temp_b = temp_b->next;
		print(pa(all));
	}
}
