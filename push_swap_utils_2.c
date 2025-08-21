/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:37:47 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/23 18:19:54 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_the_last_pos(t_node **stack_a)
{
	t_node			*tmp;
	int				flag;
	t_node			*t_node_return;

	tmp = (*stack_a);
	flag = 0;
	while (tmp)
	{
		if (tmp->target > flag)
		{
			flag = tmp->target;
			t_node_return = tmp;
		}
		tmp = tmp->next;
	}
	return (t_node_return);
}

void	reposition_stack(t_node **stack_a)
{
	int	size_stack;

	size_stack = ft_size_stack(*stack_a);
	if ((*stack_a)->target <= (size_stack / 2))
		while ((*stack_a)->target != 0)
			rra(stack_a);
	else if ((*stack_a)->target > (size_stack / 2))
		while ((*stack_a)->target != 0)
			ra(stack_a);
}

void	prepare_stack_normal(t_node *target, t_node **stack_a, t_node **stack_b)
{
	while (target->position != 0)
	{
		positive_mov(target, stack_a, stack_b);
		calculate_position(stack_b);
	}
}

void	prepare_stack_reverse(t_node *target, t_node **stack_a, \
	t_node **stack_b)
{
	while (target->position != 0)
	{
		negative_mov(target, stack_a, stack_b);
		calculate_position(stack_b);
	}
}
