#include "../../Includes/pushswap.h"

static bool	check_sort(int32_t *arg, u_int16_t total_num)
{
	int32_t	*tmp;

	tmp = arg;
	errno = 3;
	while ((arg + 1 - tmp) < total_num && arg[0] < arg[1])
		arg++;
	if ((arg + 1 - tmp) == total_num)
		return (FALSE);
	return (TRUE);
}

static bool	check_same_arg(int32_t *arg, u_int16_t total_num)
{
	int32_t		*tmp1;
	int32_t		*tmp2;

	errno = 4;
	tmp1 = arg;
	while ((arg - tmp1) < total_num)
	{
		tmp2 = arg + 1;
		while ((tmp2 - tmp1) < total_num)
		{
			if (*tmp2 == *arg)
				return (FALSE);
			tmp2++;
		}
		arg++;
	}
	return (check_sort(tmp1, total_num));
}

static bool	check_INT(t_all *all)
{
	u_int16_t	i;

	i = 0;
	while (all->num[i])
		++i;
	all->num2 = malloc(sizeof(int32_t) * i);
	i = 0;
	while (all->num[i])
	{
		all->num2[i] = ft_atoi(all->num[i]);
		if (errno == 2)
			return (FALSE);
		i++;
	}
	free_db_pointer((void **)all->num);
	return (check_same_arg(all->num2, all->total_index));
}

bool	check_arg(t_all *all)
{
	string		join;
	u_int16_t	i;

	errno = 0;
	i = 1;
	join = NULL;
	while (all->argv[i])
		join = ft_strjoin(join, all->argv[i++]);
	i = 0;
	i = 0;
	while (join[i])
	{
		if ((join[i] < '0' || join[i] > '9') && join[i] != ' ')
		{
			free(join);
			return (FALSE);
		}
		i++;
	}
	all->num = ft_split(join, ' ');
	free(join);
	return (check_INT(all));
}
