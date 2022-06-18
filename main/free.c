/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 21:54:37 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 20:51:05 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

bool	free_num(char	***str)
{
	free_db_pointer((void **) *str);
	return (false);
}

bool	free_num_2(int **num2)
{
	free(*num2);
	return (false);
}

bool	free_all(t_all *all)
{
	free_db_pointer((void **) all->num);
	free(all->num);
	return (false);
}
