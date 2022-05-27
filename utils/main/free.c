#include "../Includes/pushswap.h"

void	free_db_pointer(void **ptr)
{
	u_int16_t	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	free_stk(t_stack *stk)
{
	t_stack	*temp;

	temp = stk;
	while (temp)
	{
		stk = temp->next;
		temp->next = NULL;
		free(temp);
		temp = stk;
	}
}
