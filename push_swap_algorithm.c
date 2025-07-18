/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:26:17 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 10:26:18 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_stack(t_node **stack_a)
{
	int		i;
	t_node	*stack_tmp;

	stack_tmp = *stack_a;
	i = 0;
	while (stack_tmp)
	{
		i++;
		stack_tmp = stack_tmp->next;
	}
	return (i);
}

void	calculate_position(t_node **stack)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = (*stack);
	while (tmp)
	{
		tmp->position = pos++;
		tmp = tmp->next;
	}
}

static t_node	*get_optimal_t_node(t_node **stack_b)
{
	t_node	*t_node_r;
	t_node	*tmp;

	t_node_r = (*stack_b);
	tmp = (*stack_b);
	while (tmp)
	{
		if ((tmp->cost_b + tmp->cost_a) < (t_node_r->cost_b + t_node_r->cost_a))
			t_node_r = tmp;
		tmp = tmp->next;
	}
	return (t_node_r);
}

static void	next_optimal_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*target;

	target = get_optimal_t_node(stack_b);
	printf("\n********* TARGET: %i*********\n", target->target);
	if (target->position != 0)
		prepare_stacks(target, stack_a, stack_b);
	make_instruction(target, stack_a);
	pa(stack_a, stack_b);
	calculate_position(stack_a);
	calculate_position(stack_b);
}


void sort_algorithm(t_node **stack_a, t_node **stack_b)
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
	printf("\n********* RECALCULATING *********\n");
    calculate_position(stack_a);
    calculate_position(stack_b);
	printf("\nSTACK_A\n");
	print_list(*stack_a);
	printf("\nSTACK_B\n");
	print_list(*stack_b);
	printf("\n********* COSTES *********\n");
    cost_b(stack_b);
    cost_a(stack_a, stack_b);
	printf("\n********* MOVIMIENTOS *********\n");
    next_optimal_move(stack_a, stack_b);
	printf("\nSTACK_A\n");
	print_list(*stack_a);
	printf("\nSTACK_B\n");
	print_list(*stack_b);
    i--;
  }
}

/*
void	sort_algorithm(t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (i != 3)
	{
		pb(stack_a, stack_b);
		i = ft_size_stack(stack_a);
	}
	case_3(stack_a);
	i = ft_size_stack(stack_b);
	while (i != 0)
	{
		calculate_position(stack_a);
		calculate_position(stack_b);
		cost_b(stack_b);
		cost_a(stack_a, stack_b);
		next_optimal_move(stack_a, stack_b);
		i--;
	}
	reposition_stack(stack_a);
}
*/
