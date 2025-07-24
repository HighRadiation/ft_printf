NAME	=	libftprintf.a
CC		=	cc
WFLAGS	=	-Wall -Wextra -Werror -I.
AR		=	ar rcs

# Colors
RED		=	\033[1;91m
YELLOW	=	\033[1;93m
BLUE	=	\033[1;94m
GREEN	=	\033[1;92m
RESET	=	\033[0m

SRCS	=	ft_printf.c \
			ft_format.c \
			utils/ft_putchr.c \
			utils/ft_puthex.c \
			utils/ft_putnbr.c \
			utils/ft_putptr.c \
			utils/ft_putstr.c \
			utils/ft_putunbr.c

OBJS	=	$(SRCS:.c=.o)

# Rule to create .o files from .c files
%.o: %.c
	@$(CC) $(WFLAGS) -c $< -o $@


# all just needs to build the library, not link it
all: $(NAME)
	@printf "$(GREEN)Build successful!$(RESET)\n"

# Rule to create the archive
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) a.out
	@printf	"$(RED)Deleted object files!$(RESET)\n"

fclean:
	@rm -f $(NAME) $(OBJS)
	@printf "$(RED)Deleted object and archive files!$(RESET)\n"

clear:
	@printf "$(YELLOW)Cleaning...$(RESET)\n"
	@rm -rf myprog
	@printf "$(GREEN)All temp files are deleted.$(RESET)\n"

comp:
	@if [ -f main.c ]; then \
		$(CC) main.c libftprintf.a -o myprog && \
		printf "$(GREEN)Compile successful.$(RESET)\n" || \
		printf "$(RED)Compile failed.$(RESET)\n"; \
	else \
		printf "$(RED)Error: main.c not found.$(RESET)\n"; \
	fi

run:
	@if [ -f main.c ]; then \
		printf "$(YELLOW)Running...$(RESET)\n"; \
		./myprog; \
		printf "$(RESET)"; \
	else \
		printf "$(RED)Error: program not found.$(RESET)\n"; \
	fi

re: fclean all

.PHONY: all clean fclean clear comp run  norm re