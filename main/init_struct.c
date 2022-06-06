#include "../Includes/pushswap.h"

static t_stack	*new_stk(void)
{
	t_stack	*new;
	new = malloc(sizeof(t_stack));
	return (new);
}

static void	loop_for_stack(t_all *all)
{
	int		i;
	t_stack	*temp_stk;
	t_stack	*new;

	temp_stk = all->stk_a;
	i = 1;
	while (i < all->total_index_a)
	{
		new = new_stk();
		new->previous = temp_stk;
		temp_stk->next = new;
		temp_stk = new;
		temp_stk->arg = all->num2[i];
		temp_stk->final_index = all->f_index[i];
		++i;
	}
	temp_stk->next = NULL;
	all->last_stk_a = temp_stk;
}

void	init_struct(t_all *all)
{
	all->stk_a = malloc(sizeof(t_stack));
	all->stk_a->previous = NULL;
	all->stk_b = NULL;
	all->stk_a->arg = all->num2[0];
	all->stk_a->final_index = all->f_index[0];
	loop_for_stack(all);
}
