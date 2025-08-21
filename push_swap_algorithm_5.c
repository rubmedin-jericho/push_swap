/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_5.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 04:34:35 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/21 05:03:43 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	prepare_stacks(t_node *target, t_node **stack_a, t_node **stack_b)
{
	(void)stack_a;
	if (target->cost_b > 0)
		prepare_stack_normal(target, stack_a, stack_b);
	else if (target->cost_b < 0)
		prepare_stack_reverse(target, stack_a, stack_b);
}

void	positive_mov(t_node *target, t_node **stack_a, t_node **stack_b)
{
	if (target->shared_cost != 0)
	{
		rr(stack_a, stack_b);
		target->cost_a -= 1;
		target->cost_b -= 1;
		target->shared_cost -= 1;
	}
	else if (target->cost_a > 0)
	{
		ra(stack_a);
		target->cost_a -= 1;
	}
	else if (target->cost_b > 0)
	{
		rb(stack_b);
		target->cost_b -= 1;
	}
}

void	negative_mov(t_node *target, t_node **stack_a, t_node **stack_b)
{
	if (target->shared_cost != 0)
	{
		rrr(stack_a, stack_b);
		target->cost_a += 1;
		target->cost_b += 1;
		target->shared_cost += 1;
	}
	else if (target->cost_a < 0)
	{
		rra(stack_a);
		target->cost_a += 1;
	}
	else if (target->cost_b < 0)
	{
		rrb(stack_b);
		target->cost_b += 1;
	}
}

t_node	*find_pos(t_node **stack_a, t_node *target)
{
	t_node	*tmp;
	t_node	*t_node_return;
	t_node	*node_tmp;

	node_tmp = search_node((*stack_a), target);
	t_node_return = (*stack_a);
	tmp = (*stack_a);
	while (tmp)
	{
		if (target->target == 0)
			t_node_return = find_the_last_pos(stack_a);
		else if (tmp->target == node_tmp->target)
			t_node_return = tmp;
		tmp = tmp->next;
	}
	return (t_node_return);
}
