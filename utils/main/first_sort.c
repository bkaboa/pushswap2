#include "../Includes/pushswap.h"

int32_t	*first_sort(int32_t *arg, int16_t last_num)
{
	int32_t	*f_index;
	int32_t	*tmp1;
	int32_t	*tmp2;
	int16_t	i;

	tmp1 = arg;
	f_index = malloc(sizeof(int) * last_num);
	while ( i < last_num)
	{
		tmp2 = tmp1;
		while ((tmp2 - tmp1) < last_num)
		{
			if (*tmp2 > arg[i])
				f_index[i]++;
			tmp2++;
		}
		i++;
	}
	return (f_index);
}
