/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:04:54 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 17:09:14 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void prepare_stack_a(t_node *target, t_node **stack_a)
{
	if (target->cost_a <= (ft_size_stack(stack_a) / 2))
	{
		while (target->position != 0)
		{
			ra(stack_a);
			calculate_position(stack_a);
		}
	}
	else if (target->cost_a > (ft_size_stack(stack_a) / 2))
	{
		while (target->position != 0)
		{
			rra(stack_a);
			calculate_position(stack_a);
		}
	}
}

void prepare_stack_b(t_node *target, t_node **stack_b)
{
	if (target->cost_b <= (ft_size_stack(stack_b) / 2))
	{
		while (target->position != 0)
		{
			ra(stack_b);
			calculate_position(stack_b);
		}
	}
	else if (target->cost_b > (ft_size_stack(stack_b) / 2))
	{
		while (target->position != 0)
		{
			rra(stack_b);
			calculate_position(stack_b);
		}
	}
}

