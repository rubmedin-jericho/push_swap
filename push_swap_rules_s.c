/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:37:37 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 11:01:58 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*t_node_tmp;

	t_node_tmp = malloc(sizeof(t_node));
	t_node_tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	t_node_tmp->next = (*stack_a)->next;
	(*stack_a)->next = t_node_tmp;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	t_node	*t_node_tmp;

	t_node_tmp = malloc(sizeof(t_node));
	t_node_tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	t_node_tmp->next = (*stack_b)->next;
	(*stack_b)->next = t_node_tmp;
	write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*t_node_a_tmp;
	t_node	*t_node_b_tmp;

	t_node_a_tmp = malloc(sizeof(t_node));
	t_node_b_tmp = malloc(sizeof(t_node));
	t_node_a_tmp = (*stack_a);
	t_node_b_tmp = (*stack_b);
	(*stack_a) = (*stack_a)->next;
	(*stack_b) = (*stack_b)->next;
	t_node_a_tmp->next = (*stack_a)->next;
	t_node_b_tmp->next = (*stack_b)->next;
	(*stack_a)->next = t_node_a_tmp;
	(*stack_b)->next = t_node_b_tmp;
	write(1, "ss\n", 3);
}
