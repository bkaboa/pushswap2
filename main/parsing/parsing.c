/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:33:23 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 20:54:51 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pushswap.h"

static bool	check_same_arg(t_all *all)
{
	int32_t		*tmp1;
	int32_t		*tmp2;
	int32_t		*arg;

	tmp1 = all->num2;
	arg = tmp1;
	while ((arg - tmp1) < all->total_index)
	{
		tmp2 = arg + 1;
		while ((tmp2 - tmp1) < all->total_index)
		{
			if (*tmp2 == *arg)
				return (free_num_2(&all->num2));
			tmp2++;
		}
		arg++;
	}
	return (true);
}

static bool	check_int(t_all *all)
{
	u_int16_t	i;

	i = 0;
	if (!(all->num))
		return (false);
	while (all->num[i])
		++i;
	all->num2 = malloc(sizeof(int32_t) * i);
	if (!(all->num2))
		return (free_num(&(all->num)));
	all->total_index = i;
	i = 0;
	while (all->num[i])
	{
		if (ft_atoi(all->num[i], &(all->num2[i])) == false)
		{
			free_num(&all->num);
			return (free_num_2(&all->num2));
		}
		i++;
	}
	free_db_pointer((void **)all->num);
	return (check_same_arg(all));
}

bool	check_arg(t_all *all)
{
	t_string		join;
	u_int16_t		i;

	i = 0;
	join = NULL;
	while (all->argv[++i])
	{
		join = ft_strjoin(join, all->argv[i]);
		if (!join)
			return (false);
	}
	all->num = ft_split(join, ' ');
	free(join);
	return (check_int(all));
}
