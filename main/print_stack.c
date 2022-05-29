#include "../Includes/pushswap.h"

void	print_stk(t_stack *stk)
{
	t_stack	*temp;

	temp = stk;
	while (temp)
	{
		dprintf(1, "%d  %d\n", temp->arg, temp->final_index);
		temp = temp->next;
	}
}
