#include "../../Includes/pushswap.h"

void	do_rb(t_all *all, u_int16_t pos)
{
	while (pos > 0)
	{
		print(rb(all));
		pos--;
	}
}

void	do_rrb(t_all *all, u_int16_t pos)
{
	while (pos < all->total_index_a)
	{
		print(rrb(all));
		++pos;
	}
}
