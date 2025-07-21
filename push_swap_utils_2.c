/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:37:47 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 10:46:24 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_last_pos(t_node **stack_a)
{
	t_node	*tmp;
	int		flag;
	int		pos;
	int		size_stack;

	pos = 0;
	tmp = (*stack_a);
	flag = tmp->target;
	size_stack = ft_size_stack(stack_a);
	while (tmp)
	{
		if (tmp->target > flag)
		{
			flag = tmp->target;
			pos = tmp->position;
		}
		tmp = tmp->next;
	}
	if (pos > (size_stack / 2))
		return (pos - size_stack);
	return (pos + 1);
}

int	target_z_selector(int pos_target, t_node **stack_a, t_node *node_tmp)
{
	int		i;
	t_node	*tmp;
	int		size_stack;

	i = 0;
	size_stack = ft_size_stack(stack_a);
	tmp = (*stack_a);
	while (i < pos_target && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (pos_target <= (size_stack / 2) && node_tmp->target < tmp->target)
		return (2);
	else if (pos_target > (size_stack / 2) && node_tmp->target < tmp->target)
		return (3);
	else if (pos_target <= (size_stack / 2) && node_tmp->target > tmp->target)
		return (1);
	else if (pos_target > (size_stack / 2) && node_tmp->target > tmp->target)
		return (4);
	return (0);
}

void	reposition_stack(t_node **stack_a)
{
	int	size_stack;

	size_stack = ft_size_stack(stack_a);
	if((*stack_a)->target <= (size_stack / 2))
		while((*stack_a)->target != 0)
			ra(stack_a);
	else if((*stack_a)->target > (size_stack / 2))
		while((*stack_a)->target != 0)
			rra(stack_a);
}
