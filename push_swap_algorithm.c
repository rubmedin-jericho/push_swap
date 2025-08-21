/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:26:17 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/23 19:15:50 by rubmedin         ###   ########.fr       */
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

void	calculate_position(t_node **stack)
{
	t_node	*tmp;
	int		pos;

	pos = 0;
	tmp = (*stack);
	while (tmp)
	{
		tmp->position = pos++;
		tmp = tmp->next;
	}
}

int	rr_calculate(int tmp_cost_a, int tmp_cost_b)
{
	int	count;

	count = 0;
	while(tmp_cost_a > 0 && tmp_cost_b > 0)
	{
		count++;
		tmp_cost_a--;
		tmp_cost_b--;
	}
	return (count);
}

int	rrr_calculate(int tmp_cost_a, int tmp_cost_b)
{
	int	count;

	count = 0;
	while(tmp_cost_a < 0 && tmp_cost_b < 0)
	{
		count--;
		tmp_cost_a++;
		tmp_cost_b++;
	}
	return (count);
}

void	calculate_cost_rr_rrr(t_node **stack_b)
{
	t_node *tmp_b;
	int	tmp_cost_a;
	int	tmp_cost_b;
	int	count;

	tmp_b = (*stack_b);
	while(tmp_b)
	{
		count = 0;
		tmp_cost_a = tmp_b->cost_a;
		tmp_cost_b = tmp_b->cost_b;
		if(tmp_cost_a > 0 && tmp_cost_b > 0)
			count = rr_calculate(tmp_cost_a, tmp_cost_b);
		else if(tmp_cost_a < 0 && tmp_cost_b < 0)
			count = rrr_calculate(tmp_cost_a, tmp_cost_b);
		tmp_b->shared_cost = count;
		tmp_b = tmp_b->next;
	}
}

static t_node	*get_optimal_t_node(t_node **stack_b, int tmp_cost_a, int tmp_cost_b)
{
	t_node	*tmp;
	t_node	*t_node_b;
	//int		cost_a;
	//int		cost_b;
	//int		shared;
	int		tmp_shared;
	int		(*abs)(int);

	abs = checker_and_reverse;
	tmp = (*stack_b);
	t_node_b = (*stack_b);
	calculate_cost_rr_rrr(stack_b);
	//cost_a = checker_and_reverse((*stack_b)->cost_a);
	//cost_b = checker_and_reverse((*stack_b)->cost_b);
	//shared = checker_and_reverse((*stack_b)->shared_cost);
	while (tmp)
	{
		tmp_cost_a = checker_and_reverse(tmp->cost_a);
		tmp_cost_b = checker_and_reverse(tmp->cost_b);
		tmp_shared = checker_and_reverse(tmp->shared_cost);
		//if (((tmp_cost_b + tmp_cost_a) - shared) < ((cost_b + cost_a) - shared))
		if (tmp_cost_b + tmp_cost_a - tmp_shared < \
			abs(t_node_b->cost_b) + abs(t_node_b->cost_a) - abs(t_node_b->shared_cost))
			t_node_b = tmp;
		tmp = tmp->next;
	}
	return (t_node_b);
}


static void	next_optimal_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*target;
	int		a_void;
	int		b_void;

	a_void = 0;
	b_void = 0;
	target = get_optimal_t_node(stack_b, a_void, b_void);
	if (target->position != 0)
		prepare_stacks(target, stack_a, stack_b);
	make_instruction(target, stack_a);
	pa(stack_a, stack_b);
	calculate_position(stack_a);
	calculate_position(stack_b);
}

void	sort_3_reverse(t_node **stack)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = (*stack)->num;
	num_2 = (*stack)->next->num;
	num_3 = (*stack)->next->next->num;
	if ((num_1 < num_2) && (num_2 < num_3))
	{
		ra(stack);
		sa(stack);
	}
	if ((num_1 > num_2) && (num_1 < num_3))
		rra(stack);
	else if ((num_1 > num_2) && (num_2 < num_3) && (num_1 > num_3))
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if ((num_1 < num_2) && (num_2 > num_3) && (num_1 < num_3))
		ra(stack);
	else if ((num_1 < num_2) && (num_2 > num_3) && (num_1 > num_3))
		sa(stack);
}

//void	pre_sort(t_node **stack_a, t_node **stack_b, int size_stack)
//{
//	t_node *tmp_b;
//	t_node *tmp_a;
//	t_node *mid_stack;
//
//	calculate_position(stack_b);
//	if(ft_size_stack(*stack_b) == 3)
//		sort_3_reverse(stack_b);
//	mid_stack = (*stack_b);
//	tmp_b = (*stack_b);
//	tmp_a = (*stack_a);
//	if (tmp_a->target + 1 <= size_stack && tmp_a->target > tmp_b->target) 
//		rb(stack_b);
//	else if (tmp_a->target + 1 >= size_stack)
//		rrb(stack_b);
//}
void	pre_sort(t_node **stack_a, t_node **stack_b, int size_stack)
{
	int	count;
	
	 count = 0;
	while(count < size_stack && (*stack_a))
	{
		if((*stack_a)->target <= ((size_stack / 2) - 1))
			pb(stack_a, stack_b);
		else if ((*stack_a)->target > ((size_stack / 2) - 1))
			ra(stack_a);
		count++;
	}
	count = 0;
	size_stack = ft_size_stack(*stack_a);
	while(count < size_stack && (*stack_a) && ft_size_stack(*stack_a) > 3 )
	{
		pb(stack_a, stack_b);
		count++;
	}
}

void sort_algorithm(t_node **stack_a, t_node **stack_b)
{
	int	i;
	int	size_stack;

	i = 0; 
	size_stack = ft_size_stack(*stack_a);
	while(i != 3)
	{
		pre_sort(stack_a, stack_b, size_stack);
//		printf("\n&&&&&&& STACK_A &&&&&&\n");
//		print_list(*stack_a);
//		printf("\n&&&&&&& STACK_B &&&&&&\n");
//		print_list(*stack_b);
		i = ft_size_stack(*stack_a);
	}
	case_3(stack_a);
//	printf("\n&&&&& STACK_A &&&&&\n");
//	print_list(*stack_a);
//	printf("\n&&&&& STACK_B &&&&&\n");
//	print_list(*stack_b);
	i = ft_size_stack(*stack_b);
	while(i != 0)
	{
		calculate_position(stack_a);
		calculate_position(stack_b);
		fill_node(stack_a, stack_b);
//		printf("\n&&&&& STACK_A &&&&&\n");
//		print_list(*stack_a);
//		printf("\n&&&&& STACK_B &&&&&\n");
//		print_list(*stack_b);
		next_optimal_move(stack_a, stack_b);
//		printf("\n&&&&& STACK_A &&&&&\n");
//		print_list(*stack_a);
//		printf("\n&&&&& STACK_B &&&&&\n");
//		print_list(*stack_b);
	i--;
	}
}
//void	sort_algorithm(t_node **stack_a, t_node **stack_b)
//{
//	int	i;
//	t_node *tmp_a;
//	int	size_stack;
//
//	i = 0;
//	tmp_a = (*stack_a);
//	size_stack = ft_size_stack(*stack_a);
//	while(i < size_stack)
//	{
//		if(tmp_a->target <= (size_stack / 2))
//			pb(stack_a, stack_b);
//		else
//			ra(stack_a);
//		i++;
//	}
//}

int	check_last_s(t_node *tmp, int size_stack)
{
   	if((tmp->objective->position + (-1 * tmp->cost_a)) >= size_stack)
		return (1);
	return (0);
}
void	find_objective(t_node **stack_a, t_node **stack_b)
{
	t_node *tmp_b;

	tmp_b = (*stack_b);
	while(tmp_b)
	{
		tmp_b->objective = find_pos(stack_a, tmp_b);
//		printf("\n---tmp_b_target: %i---\n---objective_target: %i\n", tmp_b->target, tmp_b->objective->target);
		tmp_b = tmp_b->next;
	}
}

void	calculate_cost_stack(t_node **stack_a, t_node **stack_b, int flag)
{
	if(flag == 0)
		cost_a(stack_a, stack_b);
	else
		cost_b(stack_b);
}

void	fill_node(t_node **stack_a, t_node **stack_b)
{
	find_objective(stack_a, stack_b);
	calculate_cost_stack(stack_a, stack_b, 0);
	calculate_cost_stack(stack_b, stack_b, 1);
}

/*
void	sort_algorithm(t_node **stack_a, t_node **stack_b)
{
	int	i;

	i = 0;
	while (i != 3)
	{
		pb(stack_a, stack_b);
		i = ft_size_stack(stack_a);
	}
	case_3(stack_a);
	i = ft_size_stack(stack_b);
	while (i != 0)
	{
		calculate_position(stack_a);
		calculate_position(stack_b);
		cost_b(stack_b);
		cost_a(stack_a, stack_b);
		next_optimal_move(stack_a, stack_b);
		i--;
	}
	reposition_stack(stack_a);
}
*/
