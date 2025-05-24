#include "push_swap.h"

void sa(node **stack_a)
{
  node *node_tmp;

  node_tmp = malloc(sizeof(node));
  node_tmp = (*stack_a);
  (*stack_a) = (*stack_a)->next;
  node_tmp->next = (*stack_a)->next;
  (*stack_a)->next = node_tmp;
  write(1,"sa\n",3); 
}

void sb(node **stack_b)
{
  node *node_tmp;

  node_tmp = malloc(sizeof(node));
  node_tmp = (*stack_b);
  (*stack_b) = (*stack_b)->next;
  node_tmp->next = (*stack_b)->next;
  (*stack_b)->next = node_tmp;
  write(1,"sb\n",3); 
}

void ss(node **stack_a, node **stack_b)
{
  node *node_a_tmp;
  node *node_b_tmp;

  node_a_tmp = malloc(sizeof(node));
  node_b_tmp = malloc(sizeof(node));
  node_a_tmp = (*stack_a);
  node_b_tmp = (*stack_b);
  (*stack_a) = (*stack_a)->next;
  (*stack_b) = (*stack_b)->next;
  node_a_tmp->next = (*stack_a)->next;
  node_b_tmp->next = (*stack_b)->next;
  (*stack_a)->next = node_a_tmp;
  (*stack_b)->next = node_b_tmp;
  write(1,"ss\n",3);
}
