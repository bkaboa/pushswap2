#include "../Includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_all	all;

	errno = 1;
	if (argc <= 2)
		return (perso_errno_msg());
	argv[argc] = NULL;
	all.argv = argv;
	all.first_index = 1;
	all.total_index = argc - 1;
	if (check_arg(&all) == FALSE)
		return (perso_errno_msg());
	all.f_index = first_sort(all.num2, all.total_index);
	init_struct(&all);
	if (all.total_index >= 500)
		sort_upper500(&all);
	else if (all->total_index >= 100)
		sort_upper100(&all);
	else if (all->total_index >= 4)
		sort_under_100(&all);
	else
		sort_3_num(&all);
	free_stk(all.stk_a);
	return (0);
}
