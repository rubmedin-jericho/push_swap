#include "push_swap.h"

void pa(node **stack_a, node **stack_b)
{
  node *node_tmp_b;
  node *node_tmp_a;
  node *stack_tmp_b;

  if((*stack_b) == NULL)
    return ;
  node_tmp_b = (*stack_b)->next;
  node_tmp_a = (*stack_a);
  stack_tmp_b = (*stack_b);

  (*stack_b) = node_tmp_b;
  (*stack_a) = stack_tmp_b;
  (*stack_a)->next = node_tmp_a;
  write(1,"pa\n",3);
}

void pb(node **stack_a, node **stack_b)
{
  node *node_tmp_a;
  node *node_tmp_b;
  node *stack_tmp_a;

  if((*stack_a) == NULL)
    return ;
  node_tmp_a = (*stack_a)->next;
  node_tmp_b = (*stack_b);
  stack_tmp_a = (*stack_a);

  (*stack_a) = node_tmp_a;
  (*stack_b) = stack_tmp_a;
  (*stack_b)->next = node_tmp_b;
  write(1,"pb\n",3);
}


