#include "push_swap.h"

void case_3(node **stack)
{
  if((*stack)->num > (*stack)->next->num)
    sa(stack);
}

void case_4(node **stack)
{
  int i;
  node *tmp;

  tmp = *stack;
  i = 0;
  while(i < 3)
  {
    if((tmp->num > tmp->next->num) && (tmp->num < tmp->next->next->num))
      sa(stack);
    else if(tmp->num > tmp->next->next->num)
      ra(stack);
    tmp = tmp->next;
    i++;
  }
}
  
void case_5(node **stack_a, node **stack_b)
{
  pb(stack_a, stack_b);
}
