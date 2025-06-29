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

int  find_pos(node **stack_a, int target_b)
{
  node *tmp;
  int flag;
  int pos;

  flag = 0;
  pos = 0;
  tmp = (*stack_a);
  while(tmp)
  {
    if(tmp->target > flag && tmp->target < target_b)
    {
      flag = tmp->target;
      pos = tmp->position;
    }
    tmp = tmp->next;
  }
  return (pos);
}

void cost_a(node **stack_a, node **stack_b)
{
  node *tmp_b;
  int pos_less_than_b;
  int size_stack;
  int cost;

  cost = 0;
  tmp_b = (*stack_b);
  size_stack = ft_size_stack(stack_a); 
  while(tmp_b)
  {
    pos_less_than_b = find_pos(stack_a, tmp_b->target);
    if(pos_less_than_b <= (size_stack / 2))
      tmp_b->cost_a = pos_less_than_b + 1;
    else
    {
      cost =  pos_less_than_b - (size_stack / 2);
      //cost = -(cost);
      tmp_b->cost_a = cost;  
      printf("\nCOST_A: %i ---- NUM: %i\n",tmp_b->cost_a, tmp_b->num);
      if(tmp_b->cost_a > (size_stack / 2))
        tmp_b->cost_a = -(cost);
    }
    tmp_b = tmp_b->next;
  }
}


void repeat_instruction(node *target, node **stack_a)
{
  int i;
  //int size_stack;
  //int pos;

  //size_stack = ft_size_stack(stack_a);
  //pos = find_pos(stack_a, target->target);
  i = 0;
  //if(pos <= (size_stack / 2))
  if(target->cost_a > 0)
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

