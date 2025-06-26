
#include "push_swap.h"

void print_list(node *stack){
  while (stack != NULL) {
    printf("node_num: %d  ---- node_pos: %i ----  node_index: %i  ----  node_cost_b: %i ----  node_cost_a: %i\n", stack->num, stack->position , stack->target, stack->cost_b, stack->cost_a);
    stack = stack->next;
  }
}

void free_list(node *stack){
  node *tmp;
  while (stack != NULL) {
    tmp = stack;
    stack = stack->next;
    free(tmp);
  }
}

void add_node_to_list(node **stack, node *node_a){
  node *node_tmp;

  node_tmp = *stack;
  while(node_tmp->next != NULL)
    node_tmp = node_tmp->next;
  node_tmp->next = node_a;
}

node *create_node(int valor){
  node *node_tmp;

  node_tmp = malloc(sizeof(node));
  if(!node_tmp)
    return (NULL);
  node_tmp->num = valor;
  node_tmp->next = NULL;
  return (node_tmp);
}

int create_linked_list(node **stack, char **argv, int argc) {
  node *node_tmp;
  int i; 
  int num_atoi;

  i = 1;
  while(i < argc)
  {
    num_atoi = ft_atoi(argv[i]);
    node_tmp = create_node(num_atoi);
    if(!node_tmp)
        return (1);
    if(*stack == NULL)
      *stack = node_tmp;
    else 
      add_node_to_list(stack, node_tmp);
    i++;
  }
  index_assign(stack);
  return (0);
}
