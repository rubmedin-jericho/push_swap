#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct stack {
  int     num;
  int     position;
  int     target;
  int     cost_a;
  int     cost_b;
  struct  stack *next;
} node;

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
// borrar esta libreria antes de entregar
#include <stdio.h>

int is_not_n(char *str);
int ft_atoi(char *str);
int ft_strlen(char *str);
void free_list(node *stack);
void add_node_to_list(node **stack, node *node);
node *create_node(int valor);
int create_linked_list(node **stack, char **argv, int argc);
void sort_algorithm(node **stack_a, node **stack_b);
void  index_assign(node **stack);
int ft_size_stack(node **stack_a);
void make_instruction(node *target, node **stack_a);
void calculate_position(node **stack);
int find_pos(node **stack_a, node *target);
void prepare_stack_b(node *target, node **stack_b);
int find_the_last_pos(node **stack_a);
int	target_z_selector(int pos_in_stack_a, node **stack_a, node *target_tmp);

void cost_b(node **stack_b);
void cost_a(node **stack_a, node **stack_b);
void case_2(node **stack);
void case_3(node **stack);
void case_4(node **stack_a, node **stack_b);
void case_5(node **stack_a, node **stack_b);

void sa(node **stack_a);
void sb(node **stack_b);
void ss(node **stack_a, node **stack_b);
void pa(node **stack_a, node **stack_b);
void pb(node **stack_a, node **stack_b);
void ra(node **stack_a);
void rb(node **stack_b);
void rr(node **stack_a, node **stack_b);
void rra(node **stack);
void rrb(node **stack);
void rrr(node **stack_a, node **stack_b);
// borrar apartir de aqui son funciones para probar.
void print_list(node *stack);
#endif
