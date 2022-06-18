/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:28:24 by czang             #+#    #+#             */
/*   Updated: 2022/06/06 21:51:45 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pushswap.h"

int32_t	*first_sort(int32_t *arg, int16_t last_num)
{
	int32_t	*f_index;
	int32_t	*tmp1;
	int32_t	*tmp2;
	int16_t	i;

	i = 0;
	tmp1 = arg;
	f_index = malloc(sizeof(int) * last_num);
	if (!f_index)
		return (NULL);
	while (i < last_num)
	{
		tmp2 = tmp1;
		f_index[i] = 1;
		while ((tmp2 - tmp1) < last_num)
		{
			if (tmp2[0] < arg[i])
				f_index[i]++;
			tmp2++;
		}
		i++;
	}
	return (f_index);
}
