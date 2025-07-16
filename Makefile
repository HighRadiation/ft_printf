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
	@echo "$(YELLOW)Cleaning...$(RESET)\n"
	@rm -rf myprog
	@echo "$(GREEN)All temp files are deleted.$(RESET)\n"

comp:
	@$(CC) main.c libftprintf.a -o myprog && \
	echo "$(GREEN)Compile successful.$(RESET)" || \
	echo "$(RED)Compile failed.$(RESET)"

run:
	@echo "$(YELLOW)Running...$(RESET)\n"
	@./myprog
	@echo "$(RESET)"

re: fclean all

.PHONY: all clean fclean clear comp run re