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
	//int				size_stack;
	//Arregla esta funcion porque a la hora de rellenar con target 0 hace segmentation fault
	tmp = (*stack_a);
	flag = 0;
	//size_stack = ft_size_stack(stack_a);
	while (tmp)
	{
		if (tmp->target > flag)
		{
			flag = tmp->target;
			t_node_return = tmp;
		}
		tmp = tmp->next;
	}
	//if (t_node_return->position > (size_stack / 2))
	//	return (pos - size_stack);
	return (t_node_return);
}

int	target_z_selector(int pos_target, t_node **stack_a, t_node *node_tmp)
{
	int		i;
	t_node	*tmp;
	int		size_stack;

	i = 0;
	size_stack = ft_size_stack(*stack_a);
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

	size_stack = ft_size_stack(*stack_a);
	if((*stack_a)->target <= (size_stack / 2))
		while((*stack_a)->target != 0)
			ra(stack_a);
	else if((*stack_a)->target > (size_stack / 2))
		while((*stack_a)->target != 0)
			rra(stack_a);
}

//void	prepare_stack_normal(t_node *target, t_node **stack_a, t_node **stack_b)
void	prepare_stack_normal(t_node *target, t_node **stack_b)
{
	while (target->position != 0)
	{
		//if(target->cost_b > 0 && target->cost_a > 0)
		//{
		//	rr(stack_a, stack_b);
		//	target->cost_a -= 1;
		//	target->cost_b -= 1;
		//}
		rb(stack_b);
		target->cost_b -= 1;
		calculate_position(stack_b);
	}
}

void	prepare_stack_reverse(t_node *target, t_node **stack_b)
{
	while (target->position != 0)
	{
		//if(target->cost_b < 0 && target->cost_a < 0)
		//{
		//	rrr(stack_a, stack_b);
		//	target->cost_a += 1;
		//	target->cost_b += 1;
		//}
		rrb(stack_b);
		target->cost_b += 1;
		calculate_position(stack_b);
	}
}
