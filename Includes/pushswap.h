/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:55:00 by czang             #+#    #+#             */
/*   Updated: 2022/06/18 19:04:22 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <limits.h>

/*
 *
 ******************************	define			***
 */

# define MAX_ERRNO			4
# define MAX_CHAR_INT		11
# define ONL_INT_ARG		"error : only number are expected in arguments\n"
# define INV_ARG			"error : Invalid number of argument\n"
# define ARG_TOO_BIG_SMALL	"errror : arg must be between INT_MIN and INT_MAX\n"
# define ALREADY_SORT		"all arg already sort\n"
# define SAME_ARG			"error : two arg can not have the same value\n"
# define MAX_BIT_PLACE		0x2000

typedef char*	t_string;

/*
 *
 ******************************	structure		***
 */
typedef struct s_stack
{
	int16_t				final_index;
	struct s_stack		*next;
	struct s_stack		*previous;
}	t_stack;

typedef struct s_all
{
	t_stack		*stk_a;
	t_stack		*last_stk_a;
	t_stack		*stk_b;
	t_stack		*last_stk_b;
	char		**argv;
	char		**num;
	int32_t		*num2;
	int32_t		*f_index;
	u_int16_t	total_index;
}	t_all;

/*
 *
 ******************************	pushswap_main	***
 */
bool		check_arg(t_all *all);

/*
 *
 ******************************	free			***
 */
void		free_db_pointer(void **ptr);
void		free_stk(t_stack *stk);
bool		free_all(t_all *all);
bool		free_num_2(int **num2);
bool		free_num(char	***str);

/*
 *
 ******************************	struct			***
 */
void		init_struct(t_all *all);

/*
 *
 ******************************	error			***
 */
int			print_error(void);

/*
 *
 ******************************	first_sort		***
 */
int32_t		*first_sort(int32_t *arg, int16_t last_num);

/*
 *
 ******************************	operations		***
 */
t_string	ra(t_all *all);
t_string	rb(t_all *all);
t_string	sa(t_all *all);
t_string	sb(t_all *all);
t_string	rrb(t_all *all);
t_string	rra(t_all *all);
t_string	pa(t_all *all);
t_string	pb(t_all *all);
t_string	rrr(t_all *all);
t_string	rr(t_all *all);
t_string	ss(t_all *all);

/*
 *
 ******************************	utils_functions	***
 */
u_int16_t	ft_strlen(char *str);
bool		ft_atoi(t_string str, int *num2);
char		*ft_strjoin(t_string s1, t_string s2);
void		print(t_string str);

/*
 *
 ******************************	split			***
 */
char		**ft_split(t_string s, char set);

/*
 *
 ******************************	algo			***
 */
void		sort_2_num(t_all *all);
void		sort_3_num(t_all *all);
void		sort_under_100(t_all *all);
void		radix(t_all *all);

/*
 *
 ******************************	algo_utils		***
 */
bool		check_stk(t_stack *stk);
u_int16_t	check_pos_first_arg(t_all *all, u_int16_t index);
void		do_ra(t_all *all, u_int16_t pos);
void		do_rra(t_all *all, u_int16_t pos);

#endif
