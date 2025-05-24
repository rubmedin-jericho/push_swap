#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct stack {
  int num;
  struct stack *next;
} node;

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>


int     is_not_n(char *str);
int     ft_atoi(char *str);
int     ft_strlen(char *str);
void    free_list(node *stack);
void     add_node_to_list(node **stack, node *node);
node    *create_node(int valor);
int     create_linked_list(node **stack, char **argv, int argc);

void    sa(node **stack_a);
void    sb(node **stack_b);
void    ss(node **stack_a, node **stack_b);
//borrar apartir de aqui son funciones para probar.
void    print_list(node *stack);
#endif
