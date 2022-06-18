/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:17:34 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 20:51:05 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pushswap.h"

static bool	check_sort(int32_t *arg, u_int16_t total_num)
{
	int32_t	*tmp;

	tmp = arg;
	while ((arg + 1 - tmp) < total_num && arg[0] < arg[1])
		arg++;
	if ((arg + 1 - tmp) == total_num)
		return (false);
	return (true);
}

static void	choose_sort(t_all *all)
{
	if (all->total_index == 2)
		sort_2_num(all);
	if (all->total_index == 3)
		sort_3_num(all);
	if (all->total_index < 100)
		sort_under_100(all);
	if (all->total_index >= 100)
		radix(all);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc <= 1)
		return (print_error());
	argv[argc] = NULL;
	all.argv = argv;
	all.total_index = argc - 1;
	all.num = NULL;
	if (check_arg(&all) == false)
		return (print_error());
	if (check_sort(all.num2, all.total_index) == false)
	{
		free(all.num2);
		return (1);
	}
	all.f_index = first_sort(all.num2, all.total_index);
	init_struct(&all);
	choose_sort(&all);
	free(all.f_index);
	free(all.num2);
	free_stk(all.stk_a);
	return (0);
}
