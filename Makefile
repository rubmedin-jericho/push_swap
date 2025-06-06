CC = cc
FLAGS = -Wall -Werror -Wextra 
NAME = push_swap
HEADER = push_swap.h
SRCS = push_swap.c \
push_swap_utils.c \
push_swap_rules_s.c \
push_swap_rules_r.c \
push_swap_rules_p.c \
push_swap_rules_rr.c \
push_swap_algorithm.c \
push_swap_linked_list.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c Makefile $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
