/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:26:26 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/23 20:01:18 by rubmedin         ###   ########.fr       */
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
		if (tmp_b->position <= (ft_size_stack(*stack_b) / 2))
			tmp_b->cost_b = tmp_b->position;
		else if (tmp_b->position > (ft_size_stack(*stack_b) / 2))
		{
			cost = tmp_b->position - ft_size_stack(*stack_b);
			//cost = -cost;
			tmp_b->cost_b = cost;
		}
		tmp_b = tmp_b->next;
	}
}

//int	find_pos(t_node **stack_a, t_node *target)

int	search_index_down_actually(t_node **stack_a, int target)
{
	t_node	*tmp;
	int		target_rtn;

	target_rtn = 0;
	tmp = (*stack_a);
	while(tmp)
	{
		if(tmp->target > target_rtn && tmp->target < target)
			target_rtn = tmp->target;
		tmp = tmp->next;
	}
	return (target_rtn);
}

int	search_low_index(t_node **stack_a)
{
	t_node	*tmp;
	int		target_rtn;

	target_rtn = (*stack_a)->target;
	tmp = (*stack_a);
	while(tmp)
	{
		if(tmp->target < target_rtn)
			target_rtn = tmp->target;
		tmp = tmp->next;
	}
	return (target_rtn);
}

void	restart_vars(t_node **tmp, t_node **node_rtn, t_node *stack_a)
{
		*tmp = stack_a;
		*node_rtn = stack_a;
}

//t_node	*search_node(t_node **stc_a,t_node *n_rtn,t_node *flag, t_node *target)
//{
//	t_node	*tmp;
//
//	tmp = (*stc_a);
//	while(tmp)
//	{
//		if(tmp->target < target->target && tmp->target >= flag->target)
//		{
//			n_rtn = tmp;
//			flag = tmp;
//		}
//		tmp = tmp->next;
//	}
//	if (n_rtn == NULL)
//		restart_vars(&tmp, &n_rtn, (*stc_a));
//	//while(tmp)
//	//{
//	//	//if(tmp->target > target->target && tmp->target < n_rtn->target)
//	//	if(tmp->target > target->target && tmp->target > n_rtn->target)
//	//		n_rtn = tmp;
//	//	tmp = tmp->next;
//	//}
//	return (n_rtn);
//}

t_node *search_node(t_node *head, t_node *target)
{
	t_node *tmp = head;
	t_node *best_smaller = NULL;
	t_node *smallest_bigger = NULL;

	while (tmp)
	{
		if (tmp->target < target->target)
		{
			if (!best_smaller || tmp->target > best_smaller->target)
				best_smaller = tmp;
		}
		else if (tmp->target > target->target)
		{
			if (!smallest_bigger || tmp->target < smallest_bigger->target)
				smallest_bigger = tmp;
		}
		tmp = tmp->next;
	}
	if (best_smaller)
		return best_smaller;
	else
		return smallest_bigger;
}

t_node	*find_pos(t_node **stack_a, t_node *target)
{
	t_node	*tmp;
	t_node	*t_node_return;
	t_node	*node_tmp;

	node_tmp = search_node((*stack_a), target);
	t_node_return = (*stack_a);
	tmp = (*stack_a);
	while (tmp)
	{
		if (target->target == 0)
			t_node_return = find_the_last_pos(stack_a);
		else if (tmp->target == node_tmp->target)
			t_node_return = tmp;
		tmp = tmp->next;
	}
	return (t_node_return);
}

void	cost_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		size_stack;

	tmp = (*stack_b);
	size_stack = ft_size_stack(*stack_a);
	while (tmp)
	{
		calculate_position(stack_a);
		if (tmp->objective->position <= (size_stack / 2))
		{
			tmp->cost_a = tmp->objective->position + 1;
			if (tmp->objective->target < tmp->target)
				tmp->cost_a += 1;
			else if (tmp->objective->target > tmp->target)
				tmp->cost_a -= 1;
		}
		else if (tmp->objective->position > (size_stack / 2))
		{
			tmp->cost_a = ((tmp->objective->position) - size_stack);
			if(tmp->cost_a == -1)
				tmp->cost_a = 0;
		}
		if(tmp->target == 15)
			printf("\ntmp: 15 --- tmp-cost_a: %i\n",  );
		tmp = tmp->next;
	}
}

void	prepare_stacks(t_node *target, t_node **stack_a, t_node **stack_b)
{
	(void)stack_a;
	if (target->cost_b > 0)
		prepare_stack_normal(target, stack_b);
	else if (target->cost_b < 0)
		prepare_stack_reverse(target, stack_b);
}

void	make_instruction(t_node *target, t_node **stack_a, t_node **stack_b)
{
	int	i;

	(void)stack_b;
	i = 0;
	if (target->cost_a > 0)
	{
		while (i++ < target->cost_a)
		{
			ra(stack_a);
			calculate_position(stack_a);
			//calculate_cost_stack(stack_a, stack_b, 0);
		}

	}
	else if (target->cost_a < 0)
	{
		target->cost_a = -(target->cost_a);
		while (i++ < target->cost_a)
		{
			rra(stack_a);
			calculate_position(stack_a);
			//calculate_cost_stack(stack_a, stack_b, 0);
		}
	}
}
