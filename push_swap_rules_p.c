#include "push_swap.h"

void pa(node **stack_a, node **stack_b)
{
  node *node_tmp; 

  if((*stack_b) == NULL)
    return ;
  node_tmp = malloc(sizeof(node));
  node_tmp = (*stack_a);
  (*stack_a) = (*stack_b);
  (*stack_a)->next = node_tmp;
  (*stack_b) = (*stack_b)->next;
  write(1,"pa\n",3);
}

void pa(node **stack_a, node **stack_b)
{
  node *node_tmp;

  if((*stack_a) == NULL)
    return ;
  node_tmp = malloc(sizeof(node));
  node_tmp = (*stack_b);
  (*stack_b) = (*stack_a);
  (*stack_b)->next = node_tmp;
  (*stack_a) = (*stack_a)->next;
  write(1,"pb\n",3);
}


