#include "../Includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_all	all;

	errno = 1;
	if (argc <= 2)
		return (perso_errno_msg());
	argv[argc] = NULL;
	all.argv = argv;
	all.total_index = argc - 1;
	if (check_arg(&all) == FALSE)
		return (perso_errno_msg());
	all.f_index = first_sort(all.num2, all.total_index);
	return (0);
}
