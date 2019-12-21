NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = counters.c counters2.c counters3.c d_printers.c dprintspaces.c\
	   dprintspaces2.c ft_printf.c lib.c mprintspaces.c mprintspaces2.c\
	   num_finders.c num_finderutils.c printf_utils.c printf_utils2.c\
	   printf_utils3.c printflib.c printflib2.c printspaces.c\
	   printspaces2.c whichspaces.c zdprintspaces.c zdprintspaces2.c\
	   zprintspaces.c zprintspaces2.c\

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS)
	@ar -rc $(NAME) *.o
	@ranlib $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
