#include "push_swap.h"

void ra(node **stack_a)
{
  node *tmp;
  node *init;
  node *last;

  if((*stack_a) == NULL)
    return ;
  last = (*stack_a);
  init = (*stack_a);
  while(last->next != NULL)
  {
    if(last->next->next == NULL)
      tmp = last;
    last = last->next;
  }
  last->next = init->next;
  (*stack_a) = last;
  tmp->next = init;
  init->next = NULL;
  write(1,"ra\n",2);
}

void rb(node **stack_b)
{
  node *node_tmp;
  node *cursor;

  if((*stack_b) == NULL)
    return ;
  node_tmp = malloc(sizeof(node));
  cursor = malloc(sizeof(node));
  cursor = (*stack_b);
  node_tmp = (*stack_b);
  node_tmp->next = NULL; 
  while(cursor->next != NULL)
    cursor = cursor->next;
  cursor->next = node_tmp;
  write(1,"rb\n",1);
}
  
static void ra_modify(node **stack_a)
{
  node *node_tmp;
  node *cursor;

  if((*stack_a == NULL))
    return ;
  node_tmp = malloc(sizeof(node));
  cursor = malloc(sizeof(node));
  cursor = (*stack_a);
  node_tmp = (*stack_a);
  node_tmp->next = NULL; 
  while(cursor->next != NULL)
    cursor = cursor->next;
  cursor->next = node_tmp;
}

static void rb_modify(node **stack_b)
{
  node *node_tmp;
  node *cursor;

  if((*stack_b) == NULL)
    return ;
  node_tmp = malloc(sizeof(node));
  cursor = malloc(sizeof(node));
  cursor = (*stack_b);
  node_tmp = (*stack_b);
  node_tmp->next = NULL; 
  while(cursor->next != NULL)
    cursor = cursor->next;
  cursor->next = node_tmp;
}

void rr(node **stack_a, node **stack_b)
{
  ra_modify(stack_a);
  rb_modify(stack_b);
  write(1,"rr\n",1);
}
