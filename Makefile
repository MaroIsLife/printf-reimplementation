NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = *.c

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
