#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

struct stack
{
	int	num;
	struct stack *next;
};

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>


int	is_not_n(char *str);
int	ft_strlen(char *str);
#endif
