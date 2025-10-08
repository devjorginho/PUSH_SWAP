NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRCS = src/stack_manager/push_elements.c \
	   src/stack_manager/reverse_rotate_elements.c \
	   src/stack_manager/rotate_elements.c \
	   src/stack_manager/swap_elements.c \
	   src/stack_manager/init_stacks.c \
	   src/stack_manager/free_stacks.c \
	   src/arguments_checker/validate_arguments.c \
	   src/general_utils/general_utils.c \
	   src/general_utils/general_utils2.c \
	   src/general_utils/general_utils3.c \
	   src/general_utils/general_utils4.c \
	   src/sort_functions/sort_functions.c \
	   src/sort_functions/exec_sort.c \
	   src/push_swap.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME)

re: fclean all