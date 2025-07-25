/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rules_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:36:22 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 11:14:43 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*init;

	if ((*stack_a) == NULL)
		return ;
	tmp = *stack_a;
	init = *stack_a;
	(*stack_a) = init->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	init->next = NULL;
	tmp->next = init;
	write(1, "ra\n", 3);
}

void	rb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*init;

	if ((*stack_b) == NULL)
		return ;
	tmp = *stack_b;
	init = *stack_b;
	(*stack_b) = init->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	init->next = NULL;
	tmp->next = init;
	write(1, "rb\n", 3);
}

static void	ra_modify(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*init;

	if ((*stack_a) == NULL)
		return ;
	tmp = *stack_a;
	init = *stack_a;
	(*stack_a) = init->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	init->next = NULL;
	tmp->next = init;
}

static void	rb_modify(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*init;

	if ((*stack_b) == NULL)
		return ;
	tmp = *stack_b;
	init = *stack_b;
	(*stack_b) = init->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	init->next = NULL;
	tmp->next = init;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra_modify(stack_a);
	rb_modify(stack_b);
	write(1, "rr\n", 3);
}
