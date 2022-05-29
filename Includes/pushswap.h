
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
#define FALSE				false
#define TRUE				true


# define MAX_ERRNO			4
# define MAX_CHAR_INT		11
# define ONL_INT_ARG		"error : only number are expected in arguments\n"
# define INV_ARG			"error : Invalid number of argument\n"
# define ARG_TOO_BIG_SMALL	"errror : arg must be between INT_MIN and INT_MAX\n"
# define ALREADY_SORT		"all arg already sort\n"
# define SAME_ARG			"error : two arg can not have the same value\n"


typedef char*	string;

/*
 *
 ******************************	new_error		***
 */
static const struct {
	int	code;
	char *msg; 
} s_tsa[] = {
	{0, ONL_INT_ARG},
	{1, INV_ARG},
	{2, ARG_TOO_BIG_SMALL},
	{3, ALREADY_SORT},
	{MAX_ERRNO, SAME_ARG},
};

/*
 *
 ******************************	structure		***
 */

typedef struct	s_stack
{
	int					final_index;
	int					arg;
	struct s_stack		*next;
	struct s_stack		*previous;
}	t_stack;

typedef struct	s_all
{
	t_stack		*stk_a;
	t_stack		*last_stk_a;
	t_stack		*stk_b;
	t_stack		*last_stk_b;
	char		**argv;
	char		**num;
	int32_t		*num2;
	u_int16_t	total_index;
	u_int16_t	first_index;
	int32_t		*f_index;
}	t_all;
/*
 *
 ******************************	pushswap_main	***
 */
bool		check_arg(t_all *all);

/*
 *
 ******************************	algo_utils		***
 */
void	free_db_pointer(void **ptr);
void	free_stk(t_stack *stk);

/*
 *
 ******************************	struct			***
 */
void		init_struct(t_all *all);

/*
 *
 ******************************	error			***
 */
u_int8_t	perso_errno_msg(void);

/*
 *
 ******************************	first_sort		***
 */

int32_t		*first_sort(int32_t *arg, int16_t last_num);

/*
 *
 ******************************	operations		***
 */

void	ra(t_all *all);
void	rb(t_all *all);
void	sa(t_all *all);
void	sb(t_all *all);
void	rrb(t_all *all);
void	rra(t_all *all);
void	pa(t_all *all);
void	pb(t_all *all);
/*
 *
 ******************************	utils_functions	***
 */
u_int16_t	ft_strlen(char *str);
int32_t		ft_atoi(const string str);
char		*ft_strjoin(string s1, string s2);
void		print(string str);

/*
 *
 ******************************	split			***
 */
char		**ft_split(string s, char set);

/*
 *
 ******************************	algo			***
 */
void		sort_3_num(t_all *all);
void	sort_under_100(t_all *all);

/*
 *
 ******************************	algo_utils		***
 */
bool		check_stk(t_stack *stk);
//u_int16_t	take_pos_first_arg(t_all *all);
u_int16_t	check_pos_first_arg(t_all *all);
u_int16_t	check_pos_elem_pos(t_all *all, int elem);

/*
 *
 ******************************	algo_utils		***
 */
void	print_stk(t_stack *stk);

#endif
