#include "push_swap.h"

void rra(node **stack)
{
  node *node_tmp;
  node *cursor;

  cursor = *stack;  
  while(cursor->next != NULL)
    {
      node_tmp = cursor;
      cursor = cursor->next;
    }
  cursor->next = *stack;
  node_tmp->next = NULL;
  *stack = cursor;
  write(1,"rra\n",4);
}

void rrb(node **stack)
{
  node *node_tmp;
  node *cursor;

  cursor = *stack;  
  while(cursor->next != NULL)
    {
      node_tmp = cursor;
      cursor = cursor->next;
    }
  cursor->next = *stack;
  node_tmp->next = NULL;
  *stack = cursor;
  write(1,"rrb\n",4);
}

void rra_modify(node **stack)
{
  node *node_tmp;
  node *cursor;

  cursor = *stack;  
  while(cursor->next != NULL)
    {
      node_tmp = cursor;
      cursor = cursor->next;
    }
  cursor->next = *stack;
  node_tmp->next = NULL;
  *stack = cursor;
}

void rrb_modify(node **stack)
{
  node *node_tmp;
  node *cursor;

  cursor = *stack;  
  while(cursor->next != NULL)
    {
      node_tmp = cursor;
      cursor = cursor->next;
    }
  cursor->next = *stack;
  node_tmp->next = NULL;
  *stack = cursor;
}

void rrr(node **stack_a, node **stack_b)
{
  rra_modify(stack_a);
  rrb_modify(stack_b);
  write(1,"rrr\n",1);
}
