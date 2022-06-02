PMAINP		=	main/
PUTILSP		=	utils/
PPARSING	=	$(PMAINP)parsing/
PSORT		=	$(PMAINP)algo/
POPERATOR	=	$(PMAINP)operator/

SRCS		=	$(PMAINP)pushswap.c			\
				$(PMAINP)first_sort.c		\
				$(PMAINP)free.c				\
				$(PMAINP)print_stack.c		\
				$(PMAINP)init_struct.c		\
				$(PMAINP)print_stack.c		\
				$(POPERATOR)operator1.c		\
				$(POPERATOR)operator2.c		\
				$(PUTILSP)small_utils.c		\
				$(PUTILSP)split.c			\
				$(PPARSING)parsing.c		\
				$(PPARSING)print_error.c	\
				$(PSORT)sort3.c				\
				$(PSORT)sort_under100.c		\
				$(PSORT)sort_upper500.c		\
				$(PSORT)algo_utils.c

