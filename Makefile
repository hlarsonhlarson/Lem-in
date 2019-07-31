NAME = test

SRCS = main.c get_next_line/get_next_line.c

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror ft_printf/libftprintf.a get_next_line/libft/libft.a  $(SRCS) -o $(NAME)

clean:
	rm test

fclean: clean


re: fclean all
