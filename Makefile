
NAME = philo
SRC =  autentication.c checker.c destroy.c init_arg.c main.c \
		philo_routing.c thread.c utils.c

FLAGS = -Wall -Wextra -Werror -fsanitize=thread

all: $(NAME)

$(NAME):
	@cc $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 