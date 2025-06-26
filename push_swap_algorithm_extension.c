#include "push_swap.h"

void cost_b(node **stack_b)
{
  node *tmp_b;
  int cost;

  tmp_b = (*stack_b);
  while(tmp_b)
  {
    if(tmp_b->position <= (ft_size_stack(stack_b) / 2))
      tmp_b->cost_b = tmp_b->position;
    else if(tmp_b->position > (ft_size_stack(stack_b) / 2))
    {
      cost = tmp_b->position - ft_size_stack(stack_b);
      cost = -cost;
      tmp_b->cost_b = cost;
    }
    tmp_b = tmp_b->next;
  }
}

//static int cost_calculate(node **stack, int target)
//{
//  node *tmp;
//  int i;
//
//  tmp = (*stack);
//  i = 0;
//  while(tmp)
//  {
//    if(tmp->target > target)
//      i++;
//    tmp = tmp->next;
//  }
//  return (i);
//}

void cost_a(node **stack_a, node **stack_b)
{
  node *tmp_b;
  int cost;

  tmp_b = (*stack_b);
  while(tmp_b)
  {
    if(tmp_b->target <= (ft_size_stack(stack_a) / 2))
      tmp_b->cost_a = tmp_b->target;
    else if(tmp_b->target > (ft_size_stack(stack_a) / 2))
    {
     // cost = cost_calculate(stack_a, tmp_b->target);
      cost = (ft_size_stack(stack_a) - tmp_b->target) * -1;
      tmp_b->cost_a = cost;
    }
    tmp_b = tmp_b->next;
  }
}

void repeat_instruction(node *target, node **stack_a)
{
  int i;

  i = 0;
  if(target->cost_a <= 0)
  {
    while(i++ < target->cost_a)
      ra(stack_a);
  }
  else
  {
    while(i++ < -(target->cost_a))
      rra(stack_a);
  }

  //if(target->target < (ft_size_stack(stack_a) / 2))
  //else if(target->target > (ft_size_stack(stack_a) / 2) && (last->target > target->target))
}

