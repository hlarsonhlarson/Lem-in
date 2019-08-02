NAME = test

SRCS = main.c get_next_line/get_next_line.c ft_validate.c ft_check_comment.c ft_check_format_one.c create_graph.c count_num.c

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror ft_printf/libftprintf.a get_next_line/libft/libft.a  $(SRCS) -o $(NAME)

clean:
	rm test

fclean: clean


re: fclean all
