#include "push_swap.h"

int find_the_last_pos(node **stack_a)
{
  node *tmp;
  int flag;
  int pos;

  flag = 0;
  pos = 0;
  tmp = (*stack_a);
  while(tmp)
  {
    if(tmp->target > flag)
    {
      flag = tmp->target;
      pos = tmp->position;
    }
    tmp = tmp->next;
  }
  return (pos);
}
