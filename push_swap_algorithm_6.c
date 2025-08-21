/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.6.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 05:05:00 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/21 05:05:12 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_index_down_actually(t_node **stack_a, int target)
{
	t_node	*tmp;
	int		target_rtn;

	target_rtn = 0;
	tmp = (*stack_a);
	while (tmp)
	{
		if (tmp->target > target_rtn && tmp->target < target)
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
	while (tmp)
	{
		if (tmp->target < target_rtn)
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

void	selector_smaller_bigger(t_node **best_smaller,
	t_node **smallest_bigger, t_node *tmp, t_node *target)
{
	if (tmp->target < target->target)
	{
		if ((!*best_smaller) || (tmp->target > (*best_smaller)->target))
			*best_smaller = tmp;
	}
	else if (tmp->target > target->target)
	{
		if ((!*smallest_bigger) || (tmp->target > (*smallest_bigger)->target))
			*smallest_bigger = tmp;
	}
}

t_node	*search_node(t_node *head, t_node *target)
{
	t_node	*tmp;
	t_node	*best_smaller;
	t_node	*smallest_bigger;

	tmp = head;
	best_smaller = NULL;
	smallest_bigger = NULL;
	while (tmp)
	{
		selector_smaller_bigger(&best_smaller, &smallest_bigger, tmp, target);
		tmp = tmp->next;
	}
	if (best_smaller)
		return (best_smaller);
	else
		return (smallest_bigger);
}
