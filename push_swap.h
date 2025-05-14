#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct stack {
  int num;
  struct stack *next;
} node;

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int is_not_n(char *str);
int ft_strlen(char *str);
#endif
