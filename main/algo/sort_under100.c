#include "../../Includes/pushswap.h"

static void	do_ra(t_all *all, u_int16_t pos)
{
	while (pos > 0)
	{
		ra(all);
		print("ra\n");
		pos--;
	}
}

static void	do_rra(t_all *all, u_int16_t pos)
{
	while (pos < all->total_index)
	{
		rra(all);
		print("rra\n");
		++pos;
	}
}

static void	do_sa(t_all *all)
{
	sa(all);
	print("sa\n");
}

void	sort_under_100(t_all *all)
{
	u_int16_t	pos;
	t_stack		*temp_b;

	while (all->total_index > 3)
	{
		pos = check_pos_first_arg(all);
		if (pos == 1)
			do_sa(all);
		else if (((double) all->total_index / pos) <= 2)
			do_rra(all, pos);
		else
			do_ra(all, pos);
		pb(all);
		print("pb\n");
	}
	sort_3_num(all);
	temp_b = all->stk_b;
	while (temp_b)
	{
		temp_b = temp_b->next;
		print("pa\n");
		pa(all);
	}
}
