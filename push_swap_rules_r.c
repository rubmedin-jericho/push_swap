#include "push_swap.h"

void ra(node **stack_a)
{
  node *tmp;
  node *init;

  if((*stack_a) == NULL)
    return ;
  tmp = *stack_a;
  init = *stack_a;

  (*stack_a) = init->next;
  while(tmp->next != NULL)
    tmp = tmp->next;
  init->next = NULL;
  tmp->next = init;
  write(1,"ra\n",3);
}

void rb(node **stack_b)
{
  node *tmp;
  node *init;

  if((*stack_b) == NULL)
    return ;
  tmp = *stack_b;
  init = *stack_b;

  (*stack_b) = init->next;
  while(tmp->next != NULL)
    tmp = tmp->next;
  init->next = NULL;
  tmp->next = init;
  write(1,"rb\n",3);
}

static void ra_modify(node **stack_a)
{
  node *tmp;
  node *init;

  if((*stack_a) == NULL)
    return ;
  tmp = *stack_a;
  init = *stack_a;

  (*stack_a) = init->next;
  while(tmp->next != NULL)
    tmp = tmp->next;
  init->next = NULL;
  tmp->next = init;
}

static void rb_modify(node **stack_b)
{
  node *tmp;
  node *init;

  if((*stack_b) == NULL)
    return ;
  tmp = *stack_b;
  init = *stack_b;

  (*stack_b) = init->next;
  while(tmp->next != NULL)
    tmp = tmp->next;
  init->next = NULL;
  tmp->next = init;
}

void rr(node **stack_a, node **stack_b)
{
  ra_modify(stack_a);
  rb_modify(stack_b);
  write(1,"rr\n",1);
}
