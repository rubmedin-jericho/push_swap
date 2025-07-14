/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:35:43 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 11:16:13 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*t_node_tmp_b;
	t_node	*t_node_tmp_a;
	t_node	*stack_tmp_b;

	if ((*stack_b) == NULL)
		return ;
	t_node_tmp_b = (*stack_b)->next;
	t_node_tmp_a = (*stack_a);
	stack_tmp_b = (*stack_b);
	(*stack_b) = t_node_tmp_b;
	(*stack_a) = stack_tmp_b;
	(*stack_a)->next = t_node_tmp_a;
	write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*t_node_tmp_a;
	t_node	*t_node_tmp_b;
	t_node	*stack_tmp_a;

	if ((*stack_a) == NULL)
		return ;
	t_node_tmp_a = (*stack_a)->next;
	t_node_tmp_b = (*stack_b);
	stack_tmp_a = (*stack_a);
	(*stack_a) = t_node_tmp_a;
	(*stack_b) = stack_tmp_a;
	(*stack_b)->next = t_node_tmp_b;
	write(1, "pb\n", 3);
}
