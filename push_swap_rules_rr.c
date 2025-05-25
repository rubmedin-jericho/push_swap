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
}
