/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:26:26 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/21 05:03:55 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_b(t_node **stack_b)
{
	t_node	*tmp_b;
	int		cost;

	tmp_b = (*stack_b);
	while (tmp_b)
	{
		if (tmp_b->position <= (ft_size_stack(*stack_b) / 2))
			tmp_b->cost_b = tmp_b->position;
		else if (tmp_b->position > (ft_size_stack(*stack_b) / 2))
		{
			cost = tmp_b->position - ft_size_stack(*stack_b);
			tmp_b->cost_b = cost;
		}
		tmp_b = tmp_b->next;
	}
}

static int	upper_node_stack(t_node *stack_a)
{
	int		target_num;
	t_node	*tmp;

	tmp = stack_a;
	target_num = tmp->target;
	while (tmp)
	{
		if (target_num > tmp->target)
			target_num = tmp->target;
		tmp = tmp->next;
	}
	return (target_num);
}

static void	cost_adjustment(t_node *tmp, int size_stack, t_node *stack_a)
{
	if (tmp->objective->position <= (size_stack / 2))
	{
		tmp->cost_a = tmp->objective->position + 1;
		if (tmp->objective->target > tmp->target)
		{
			if (upper_node_stack(stack_a) == tmp->objective->target)
				tmp->cost_a -= 1;
		}
	}
	else if (tmp->objective->position > (size_stack / 2))
	{
		tmp->cost_a = ((tmp->objective->position) - size_stack);
		if (tmp->cost_a == -1 && tmp->objective->target < tmp->target)
			tmp->cost_a = 0;
		else if ((tmp->objective->position - size_stack) == -1 && \
				tmp->objective->target > tmp->target)
			tmp->cost_a = 0;
		else if (tmp->objective->target < tmp->target && \
			(tmp->objective->position + (-1 * tmp->cost_a)) >= size_stack)
			tmp->cost_a += 1;
		else if (tmp->objective->target > tmp->target && tmp->cost_a < 0)
			tmp->cost_a += 1;
	}
}

void	cost_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		size_stack;

	tmp = (*stack_b);
	size_stack = ft_size_stack(*stack_a);
	while (tmp)
	{
		calculate_position(stack_a);
		cost_adjustment(tmp, size_stack, (*stack_a));
		tmp = tmp->next;
	}
}

void	make_instruction(t_node *target, t_node **stack_a)
{
	int	i;

	i = 0;
	if (target->cost_a > 0)
	{
		while (i++ < target->cost_a)
		{
			ra(stack_a);
			calculate_position(stack_a);
		}
	}
	else if (target->cost_a < 0)
	{
		target->cost_a = -(target->cost_a);
		while (i++ < target->cost_a)
		{
			rra(stack_a);
			calculate_position(stack_a);
		}
	}
}
