PMAINP		=	main/
PUTILSP		=	utils/
PPARSING	=	$(PMAINP)parsing/
PSORT		=	$(PMAINP)algo/
POPERATOR	=	$(PMAINP)operator/

SRCS		=	$(PMAINP)pushswap.c			\
				$(PMAINP)first_sort.c		\
				$(PMAINP)free.c				\
				$(PMAINP)init_struct.c		\
				$(PPARSING)parsing.c		\
				$(PPARSING)print_error.c	\
				$(POPERATOR)operator1.c		\
				$(POPERATOR)operator2.c		\
				$(POPERATOR)operator3.c		\
				$(PSORT)sort3.c				\
				$(PSORT)sort_under100.c		\
				$(PSORT)radix.c				\
				$(PSORT)algo_utils.c		\
				$(PUTILSP)small_utils.c		\
				$(PUTILSP)split.c

