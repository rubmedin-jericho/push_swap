/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:26:17 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/23 19:15:50 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_stack(t_node *stack_a)
{
	int		i;
	t_node	*stack_tmp;

	stack_tmp = stack_a;
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

static t_node	*get_optimal_t_node(t_node **stack_b, int tmp_cost_a, int tmp_cost_b)
{
	t_node	*t_node_b;
	t_node	*tmp;
	int		t_node_b_cost_a;
	int		t_node_b_cost_b;

	t_node_b = (*stack_b);
	tmp = (*stack_b);
	t_node_b_cost_a = checker_and_reverse(t_node_b->cost_a);
	t_node_b_cost_b = checker_and_reverse(t_node_b->cost_b);
	while (tmp)
	{
		tmp_cost_a = checker_and_reverse(tmp->cost_a);
		tmp_cost_b = checker_and_reverse(tmp->cost_b);
		if ((tmp_cost_b + tmp_cost_a) < (t_node_b_cost_b + t_node_b_cost_a))
			t_node_b = tmp;
		tmp = tmp->next;
	}
	return (t_node_b);
}

static void	next_optimal_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*target;
	int		a_void;
	int		b_void;

	a_void = 0;
	b_void = 0;
	target = get_optimal_t_node(stack_b, a_void, b_void);
	if (target->position != 0)
		prepare_stacks(target, stack_a, stack_b);
	make_instruction(target, stack_a, stack_b);
	pa(stack_a, stack_b);
	calculate_position(stack_a);
	calculate_position(stack_b);
}

void sort_algorithm(t_node **stack_a, t_node **stack_b)
{
  int i;

  i = 0; 
	printf("\n&&&&&&& PUSH_B &&&&&&\n");
	while(i != 3)
	{
		pb(stack_a, stack_b);
		i = ft_size_stack(*stack_a);
	}
	printf("\n&&&&&&& STACK_A INIT &&&&&&\n");
	print_list(*stack_a);
	printf("\n&&&&&&& STACK_B INIT &&&&&&\n");
	print_list(*stack_b);
	printf("\n&&&&&&& CASE_3 &&&&&&\n");
  case_3(stack_a);
  i = ft_size_stack(*stack_b);
  while(i != 0)
  {
    calculate_position(stack_a);
    calculate_position(stack_b);
	fill_node(stack_a, stack_b);
	printf("\n&&&&&&& STACK_A &&&&&&\n");
	print_list(*stack_a);
	printf("\n&&&&&&& STACK_B &&&&&&\n");
	print_list(*stack_b);
    next_optimal_move(stack_a, stack_b);
	printf("\n&&&&&&& STACK_A FINISH &&&&&&\n");
	print_list(*stack_a);
	printf("\n&&&&&&& STACK_B FINISH &&&&&&\n");
	print_list(*stack_b);
    i--;
  }
}

void	find_objective(t_node **stack_a, t_node **stack_b)
{
	t_node *tmp_b;

	tmp_b = (*stack_b);
	while(tmp_b)
	{
		tmp_b->objective = find_pos(stack_a, tmp_b);
		printf("\n---tmp_b_target: %i---\n---objective_target: %i\n", tmp_b->target, tmp_b->objective->target);
		tmp_b = tmp_b->next;
	}
}

void	calculate_cost_stack(t_node **stack_a, t_node **stack_b, int flag)
{
	if(flag == 0)
		cost_a(stack_a, stack_b);
	else
		cost_b(stack_b);
}

void	fill_node(t_node **stack_a, t_node **stack_b)
{
	find_objective(stack_a, stack_b);
	calculate_cost_stack(stack_a, stack_b, 0);
	calculate_cost_stack(stack_b, stack_b, 1);
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
