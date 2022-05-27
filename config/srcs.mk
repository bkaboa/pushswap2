PMAINP		=	main/
PUTILSP		=	utils/
PSTRUCT		=	$(PMAINP)struct/
PPARSING	=	$(PMAINP)parsing/
PSORT		=	$(PMAINP)algo/
POPERATOR	=	$(PMAINP)operator/

SRCS		=	$(PMAINP)pushswap.c			\
				$(PMAINP)first_sort.c		\
				$(PMAINP)free.c				\
				$(PMAINP)print_stack.c		\
				$(PUTILSP)small_utils.c		\
				$(PUTILSP)split.c			\
				$(PPARSING)parsing.c		\
				$(PPARSING)print_error.c	\

