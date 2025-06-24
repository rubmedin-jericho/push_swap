#include "push_swap.h"

//static int chose_node_less_move(node **stack_a, node **stack_b)
//{
//  //Esta funcion estoy pensando que ire pasando de nodo en nodo 
//  //mirando el numero de movimientos posibles hasta que encuentre
//  //el que menos moviimientos haga y devuelve la posicion donde se encuentre.
//}

//static void init_stack_b(node **stack_b, node **stack_a)
//{
//  int i;
//
//  i = 0;
//  while(i < 2)
//  {
//    pb(stack_a, stack_b);
//    i++;
//  }
//  if((*stack_b)->num < (*stack_b)->next->num)
//    sb(stack_b);
//}

//static int ft_size_stack(node **stack_a)
//{
//  int i;
//  node *stack_tmp;
//
//  stack_tmp = *stack_a;
//  i = 0;
//  while(!stack_tmp)
//  {
//    i++;
//    stack_tmp = stack_tmp->next;
//  }
//  return (i);
//}

//void sort_algorithm(node **stack_a, int argc)
//{
//  node *stack_b;
//  node *stack_tmp;
//  int i;
//
//  i = 1;
//  stack_b = NULL;
//  while(i < argc)
//  {
//    if(ft_size_stack(stack_a) > 3)
//    {
//      if(stack_b == NULL)
//        init_stack_b(&stack_b, stack_a);
//      //chose_node_less_move(stack_a, &stack_b);
//    }
//    i++;
//  }
//  print_list(stack_b);
//  free_list(stack_b);
//}
