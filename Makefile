include 	config/srcs.mk

NAME	=	push_swap

IPATH	=	Includes
OPATH	=	.OBJ
MEMFLAGS=	-fsanitize=address -g3
CFLAGS	=	-Wall -Werror -Wextra
IFLAGS	=	-I $(IPATH)
OBJS	=	$(addprefix $(OPATH)/, $(SRCS:.c=.o))
INC		=	$(addprefix $(IPATH)/, pushswap.h)
RMF		=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

re:				fclean all

$(OPATH)/%.o:	%.c $(INC) config/srcs.mk Makefile
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

memoire:		CFLAGS += $(MEMFLAGS)
memoire:		re

clean:
	@$(RM) $(OBJS)
	@$(RMF) $(OPATH)

fclean:			clean
	@$(RM) $(NAME)

PHONY: re clean fclean all
