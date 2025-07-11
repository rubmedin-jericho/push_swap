#include "push_swap.h"

int ft_size_stack(node **stack_a)
{
  int i;
  node *stack_tmp;

  stack_tmp = *stack_a;
  i = 0;
  while(stack_tmp)
  {
    i++;
    stack_tmp = stack_tmp->next;
  }
  return (i);
}

void calculate_position(node **stack)
{
  node *tmp;
  int pos;

  pos = 0;
  tmp = (*stack);
  while(tmp)
  {
    tmp->position = pos++;
    tmp = tmp->next;
  }
}

static node *get_optimal_node(node **stack_b)
{
  node *node_return;
  node *tmp;

  node_return = (*stack_b);
  tmp = (*stack_b);
  while(tmp)
  {
    if((tmp->cost_b + tmp->cost_a) < (node_return->cost_b + node_return->cost_a))
      node_return = tmp;
    tmp = tmp->next;
  }
  return (node_return);
}

static void next_optimal_move(node **stack_a, node **stack_b)
{
  node *target;

  target = get_optimal_node(stack_b);
  if(target->position != 0)
    prepare_stack_b(target, stack_b);
  make_instruction(target, stack_a); 
  pa(stack_a, stack_b);
  calculate_position(stack_a);
  calculate_position(stack_b);
}

//void sort_algorithm(node **stack_a, node **stack_b)
//{
//  int i;
//
//  i = 0; 
//  while(i != 3)
//  {  
//    pb(stack_a, stack_b);
//    i = ft_size_stack(stack_a);
//  }
//  case_3(stack_a);
//  i = ft_size_stack(stack_b);
//  while(i != 0)
//  {
//    calculate_position(stack_a);
//    calculate_position(stack_b);
//    cost_b(stack_b);
//    cost_a(stack_a, stack_b);
//    printf("\nSTACK_A\n");
//    print_list((*stack_a));
//    printf("\n");
//    printf("\nSTACK_B\n");
//    print_list((*stack_b));
//    next_optimal_move(stack_a, stack_b);
//    printf("\nSTACK_A_AFTER\n");
//    print_list((*stack_a));
//    printf("\n");
//    printf("\nSTACK_B_AFTER\n");
//    print_list((*stack_b));
//    i--;
//   // i = ft_size_stack(stack_b);
//    printf("\n********************************\n");
//  }
//	reposition_stack(stack_a);
//    printf("STACK_A_FINISH\n");
//    print_list((*stack_a));
//    printf("STACK_B_FINISH\n");
//    print_list((*stack_b));
//}
void sort_algorithm(node **stack_a, node **stack_b)
{
	int i;

	i = 0; 
	while(i != 3)
	{  
		pb(stack_a, stack_b);
		i = ft_size_stack(stack_a);
	}
	case_3(stack_a);
	i = ft_size_stack(stack_b);
	while(i != 0)
	{
		calculate_position(stack_a);
		calculate_position(stack_b);
		cost_b(stack_b);
		cost_a(stack_a, stack_b);
		next_optimal_move(stack_a, stack_b);
		i--;
	}
	reposition_stack(stack_a);
    //printf("STACK_A_FINISH\n");
    //print_list((*stack_a));
    //printf("STACK_B_FINISH\n");
    //print_list((*stack_b));
}
