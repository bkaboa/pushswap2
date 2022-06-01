#include "../Includes/pushswap.h"

void	print_stk(t_stack *stk)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stk;
	while (temp)
	{
		dprintf(1, "%d  %d   %d\n", temp->arg, temp->final_index, i);
		++i;
		temp = temp->next;
	}
}

void	print_final_stk(t_stack *stk)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = stk;
	while (temp)
	{
		dprintf(1, "%d  %d   %d\n", temp->arg, temp->final_index, i);
		++i;
		temp = temp->previous;
	}
}
