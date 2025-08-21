/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:04:54 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/21 04:36:09 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_stack_a(t_node *target, t_node **stack_a)
{
	if (target->cost_a <= (ft_size_stack(*stack_a) / 2))
	{
		while (target->position != 0)
		{
			ra(stack_a);
			calculate_position(stack_a);
		}
	}
	else if (target->cost_a > (ft_size_stack(*stack_a) / 2))
	{
		while (target->position != 0)
		{
			rra(stack_a);
			calculate_position(stack_a);
		}
	}
}

void	prepare_stack_b(t_node *target, t_node **stack_b)
{
	if (target->cost_b <= (ft_size_stack(*stack_b) / 2))
	{
		while (target->position != 0)
		{
			ra(stack_b);
			calculate_position(stack_b);
		}
	}
	else if (target->cost_b > (ft_size_stack(*stack_b) / 2))
	{
		while (target->position != 0)
		{
			rra(stack_b);
			calculate_position(stack_b);
		}
	}
}

int	rr_calculate(int tmp_cost_a, int tmp_cost_b)
{
	int	count;

	count = 0;
	while (tmp_cost_a > 0 && tmp_cost_b > 0)
	{
		count++;
		tmp_cost_a--;
		tmp_cost_b--;
	}
	return (count);
}

int	rrr_calculate(int tmp_cost_a, int tmp_cost_b)
{
	int	count;

	count = 0;
	while (tmp_cost_a < 0 && tmp_cost_b < 0)
	{
		count--;
		tmp_cost_a++;
		tmp_cost_b++;
	}
	return (count);
}

void	calculate_cost_rr_rrr(t_node **stack_b)
{
	t_node	*tmp_b;
	int		tmp_cost_a;
	int		tmp_cost_b;
	int		count;

	tmp_b = (*stack_b);
	while (tmp_b)
	{
		count = 0;
		tmp_cost_a = tmp_b->cost_a;
		tmp_cost_b = tmp_b->cost_b;
		if (tmp_cost_a > 0 && tmp_cost_b > 0)
			count = rr_calculate(tmp_cost_a, tmp_cost_b);
		else if (tmp_cost_a < 0 && tmp_cost_b < 0)
			count = rrr_calculate(tmp_cost_a, tmp_cost_b);
		tmp_b->shared_cost = count;
		tmp_b = tmp_b->next;
	}
}
