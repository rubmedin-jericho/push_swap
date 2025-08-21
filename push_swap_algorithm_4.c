/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:30:35 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/23 14:31:42 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_stack(t_node *stack_a)
{
	int		i;
	t_node	*stack_tmp;

	stack_tmp = stack_a;
	i = 0;
	while (stack_tmp)
	{
		i++;
		stack_tmp = stack_tmp->next;
	}
	return (i);
}

int	checker_and_reverse(int nbr)
{
	if (nbr < 0)
		nbr = -(nbr);
	return (nbr);
}

void	find_objective(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_b;

	tmp_b = (*stack_b);
	while (tmp_b)
	{
		tmp_b->objective = find_pos(stack_a, tmp_b);
		tmp_b = tmp_b->next;
	}
}

void	calculate_cost_stack(t_node **stack_a, t_node **stack_b, int flag)
{
	if (flag == 0)
		cost_a(stack_a, stack_b);
	else
		cost_b(stack_b);
}
