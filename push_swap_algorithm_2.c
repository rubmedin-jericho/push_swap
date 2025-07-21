/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_extension.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:26:26 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 10:26:30 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_b(t_node **stack_b)
{
	t_node	*tmp_b;
	int		cost;

	tmp_b = (*stack_b);
	while (tmp_b)
	{
		if (tmp_b->position <= (ft_size_stack(stack_b) / 2))
			tmp_b->cost_b = tmp_b->position;
		else if (tmp_b->position > (ft_size_stack(stack_b) / 2))
		{
			cost = tmp_b->position - ft_size_stack(stack_b);
			//cost = -cost;
			tmp_b->cost_b = cost;
		}
		tmp_b = tmp_b->next;
	}
}

//int	find_pos(t_node **stack_a, t_node *target)
int	find_pos(t_node **stack_a, t_node *target)
{
	t_node	*tmp;
	int		flag;
	int		pos;

	pos = 0;
	tmp = (*stack_a);
	flag = 0;
	while (tmp)
	{
		if (target->target == 0)
			pos = find_the_last_pos(stack_a);
		else if (tmp->target >= flag && tmp->target < target->target)
		{
			flag = tmp->target;
			pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (pos);
}

/*void	cost_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp_b;
	int		pos_less_than_b;
	int		size_stack;
	int		cost;
	int		select_z;

	cost = 0;
	tmp_b = (*stack_b);
	size_stack = ft_size_stack(stack_a);
	while (tmp_b)
	{
		pos_less_than_b = find_pos(stack_a, tmp_b);
		printf("\n************** POS: %i **************\n", pos_less_than_b);
		select_z = target_z_selector(pos_less_than_b, stack_a, tmp_b);
		if (select_z == 1)
			tmp_b->cost_a = (pos_less_than_b + 1);
		else if (select_z == 2)
			tmp_b->cost_a = 0;
		else if (select_z == 3)
			tmp_b->cost_a = pos_less_than_b - size_stack;
		else if (select_z == 4)
			tmp_b->cost_a = (pos_less_than_b + 1) - size_stack;
		tmp_b = tmp_b->next;
	}
}
*/
void	cost_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		size_stack;

	tmp = (*stack_b);
	size_stack = ft_size_stack(stack_a);
	while (tmp)
	{
		printf("\ntmp: %i, objective: %i\n",tmp->target, tmp->objective);
		if (tmp->objective <= (size_stack / 2) && tmp->objective > 0)
			tmp->cost_a = (tmp->objective + 1);
		else if (tmp->objective > (size_stack / 2))
		{
			tmp->cost_a = tmp->objective - size_stack;
			if(tmp->cost_a == -1)
				tmp->cost_a = 0;
		}
		tmp = tmp->next;
	}
}

void	prepare_stacks(t_node *target, t_node **stack_a, t_node **stack_b)
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
	prepare_stack_b(target, stack_b);
	prepare_stack_a(target, stack_a);
}

void	make_instruction(t_node *target, t_node **stack_a)
{
	int	i;

	i = 0;
	if (target->cost_a > 0)
	{
		while (i++ < target->cost_a)
			ra(stack_a);
	}
	else if (target->cost_a < 0)
	{
		target->cost_a = -(target->cost_a);
		while (i++ < target->cost_a)
			rra(stack_a);
	}
}
