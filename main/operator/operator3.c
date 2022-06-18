/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:15:48 by czang             #+#    #+#             */
/*   Updated: 2022/06/09 14:17:02 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pushswap.h"

t_string	rrr(t_all *all)
{
	rra(all);
	rrb(all);
	return ("rrr\n");
}

t_string	rr(t_all *all)
{
	ra(all);
	rb(all);
	return ("rr\n");
}

t_string	ss(t_all *all)
{
	sa(all);
	sb(all);
	return ("ss\n");
}
