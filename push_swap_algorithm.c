/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:26:17 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/21 04:35:42 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_optimal_t_node(t_node **stack_b,
		int tmp_cost_a, int tmp_cost_b)
{
	t_node	*tmp;
	t_node	*t_node_b;
	int		tmp_shared;
	int		(*abs)(int);

	abs = checker_and_reverse;
	tmp = (*stack_b);
	t_node_b = (*stack_b);
	calculate_cost_rr_rrr(stack_b);
	while (tmp)
	{
		tmp_cost_a = checker_and_reverse(tmp->cost_a);
		tmp_cost_b = checker_and_reverse(tmp->cost_b);
		tmp_shared = checker_and_reverse(tmp->shared_cost);
		if (tmp_cost_b + tmp_cost_a - tmp_shared < \
			abs(t_node_b->cost_b) + abs(t_node_b->cost_a) - \
			abs(t_node_b->shared_cost))
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
	make_instruction(target, stack_a);
	pa(stack_a, stack_b);
	calculate_position(stack_a);
	calculate_position(stack_b);
}

static void	pre_sort(t_node **stack_a, t_node **stack_b, int size_stack)
{
	int	count;

	count = 0;
	while (count < size_stack && (*stack_a))
	{
		if ((*stack_a)->target <= ((size_stack / 2) - 1))
			pb(stack_a, stack_b);
		else if ((*stack_a)->target > ((size_stack / 2) - 1))
			ra(stack_a);
		count++;
	}
	count = 0;
	size_stack = ft_size_stack(*stack_a);
	while (count < size_stack && (*stack_a) && ft_size_stack(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
		count++;
	}
}

void	fill_node(t_node **stack_a, t_node **stack_b)
{
	find_objective(stack_a, stack_b);
	calculate_cost_stack(stack_a, stack_b, 0);
	calculate_cost_stack(stack_b, stack_b, 1);
}

void	sort_algorithm(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	size_stack;

	i = 0;
	size_stack = ft_size_stack(*stack_a);
	while (i != 3)
	{
		pre_sort(stack_a, stack_b, size_stack);
		i = ft_size_stack(*stack_a);
	}
	case_3(stack_a);
	i = ft_size_stack(*stack_b);
	while (i != 0)
	{
		calculate_position(stack_a);
		calculate_position(stack_b);
		fill_node(stack_a, stack_b);
		next_optimal_move(stack_a, stack_b);
		i--;
	}
}
