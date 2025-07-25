/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_rr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:37:29 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 11:05:04 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack)
{
	t_node	*t_node_tmp;
	t_node	*cursor;

	cursor = *stack;
	while (cursor->next != NULL)
	{
		t_node_tmp = cursor;
		cursor = cursor->next;
	}
	cursor->next = *stack;
	t_node_tmp->next = NULL;
	*stack = cursor;
	write(1, "rra\n", 4);
}

void	rrb(t_node **stack)
{
	t_node	*t_node_tmp;
	t_node	*cursor;

	cursor = *stack;
	while (cursor->next != NULL)
	{
		t_node_tmp = cursor;
		cursor = cursor->next;
	}
	cursor->next = *stack;
	t_node_tmp->next = NULL;
	*stack = cursor;
	write(1, "rrb\n", 4);
}

void	rra_modify(t_node **stack)
{
	t_node	*t_node_tmp;
	t_node	*cursor;

	cursor = *stack;
	while (cursor->next != NULL)
	{
		t_node_tmp = cursor;
		cursor = cursor->next;
	}
	cursor->next = *stack;
	t_node_tmp->next = NULL;
	*stack = cursor;
}

void	rrb_modify(t_node **stack)
{
	t_node	*t_node_tmp;
	t_node	*cursor;

	cursor = *stack;
	while (cursor->next != NULL)
	{
		t_node_tmp = cursor;
		cursor = cursor->next;
	}
	cursor->next = *stack;
	t_node_tmp->next = NULL;
	*stack = cursor;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra_modify(stack_a);
	rrb_modify(stack_b);
	write(1, "rrr\n", 4);
}
