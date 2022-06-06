#include "../../Includes/pushswap.h"

string	rrr(t_all *all)
{
	rra(all);
	rrb(all);
	return ("rrr\n");
}

string	rr(t_all *all)
{
	ra(all);
	rb(all);
	return ("rr\n");
}

string	ss(t_all *all)
{
	sa(all);
	sb(all);
	return ("ss\n");
}
