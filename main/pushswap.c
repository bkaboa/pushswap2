#include "../Includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_all		all;

	errno = 1;
	if (argc <= 2)
		return (perso_errno_msg());
	argv[argc] = NULL;
	all.argv = argv;
	all.first_index = 1;
	all.total_index_a = argc - 1;
	all.total_index_b = 0;
	if (check_arg(&all) == FALSE)
		return (perso_errno_msg());
	all.f_index = first_sort(all.num2, all.total_index_a);
	init_struct(&all);
	if (all.total_index_a >= 100)
		big_first_sort(&all);
	free_stk(all.stk_a);
	free_stk(all.stk_b);
	return (0);
}
