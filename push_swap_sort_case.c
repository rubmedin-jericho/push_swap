/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:37:41 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 10:58:50 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_2(t_node **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	case_3(t_node **stack)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = (*stack)->num;
	num_2 = (*stack)->next->num;
	num_3 = (*stack)->next->next->num;
	if ((num_1 > num_2) && (num_2 < num_3) && (num_1 < num_3))
		sa(stack);
	else if ((num_1 > num_2) && (num_2 > num_3))
	{
		sa(stack);
		rra(stack);
	}
	else if ((num_1 > num_2) && (num_2 < num_3) && (num_1 > num_3))
		ra(stack);
	else if ((num_1 < num_2) && (num_2 > num_3) && (num_1 < num_3))
	{
		sa(stack);
		ra(stack);
	}
	else if ((num_1 < num_2) && (num_2 > num_3) && (num_1 > num_3))
		rra(stack);
}

static void	case_4_5(t_node **stack_a, int target)
{
	if ((*stack_a)->next->target == target)
		sa(stack_a);
	else if ((*stack_a)->next->next->target == target)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (target == 0)
	{
		if ((*stack_a)->next->next->next->target == target)
			rra(stack_a);
		else if (target == 1)
		{
			if ((*stack_a)->next->next->next->target == target)
			{
				rra(stack_a);
				rra(stack_a);
			}
		}
	}
}

void	case_4(t_node **stack_a, t_node **stack_b)
{
	case_4_5(stack_a, 0);
	pb(stack_a, stack_b);
	case_3(stack_a);
	pa(stack_a, stack_b);
}

void	case_5(t_node **stack_a, t_node **stack_b)
{
	case_4_5(stack_a, 1);
	pb(stack_a, stack_b);
	case_4_5(stack_a, 0);
	pb(stack_a, stack_b);
	case_3(stack_a);
	if ((*stack_b)->target < (*stack_b)->next->target)
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
