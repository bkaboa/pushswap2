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
	//	printf("%d\n\n\n\n", pos);
	//	printf("stk a\n ; ");
	//	print_stk(all->stk_a);
	//	printf("\n\n\n\n");
	//	printf("final stk a\n ; ");
	//	print_final_stk(all->last_stk_a);
		if (pos == 1)
			do_sa(all);
		else if (((double) all->total_index / pos) <= 2)
		{
			dprintf(2, "1");
			do_rra(all, pos);
			dprintf(2, "2\n");
		}
		else
		{
			dprintf(2, "3");
			do_ra(all, pos);
			dprintf(2, "4\n");
		}
		pb(all);
		print("pb\n");
	//	printf("\n\n\n");
	//	print_stk(all->stk_b);
	//	printf("\n\n\n");
	//	print_stk(all->stk_a);
	//	printf("\n\n\n\n");
	//	print_final_stk(all->last_stk_a);
	//	printf("\n\n\n\n");
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
