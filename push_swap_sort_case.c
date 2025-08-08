/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_case.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:37:41 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 10:58:50 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_2(t_node **stack)
{
	if ((*stack)->num > (*stack)->next->num)
		sa(stack);
}

void	case_3(t_node **stack)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = (*stack)->num;
	num_2 = (*stack)->next->num;
	num_3 = (*stack)->next->next->num;
	if ((num_1 > num_2) && (num_2 < num_3) && (num_1 < num_3))
		sa(stack);
	else if ((num_1 > num_2) && (num_2 > num_3))
	{
		sa(stack);
		rra(stack);
	}
	else if ((num_1 > num_2) && (num_2 < num_3) && (num_1 > num_3))
		ra(stack);
	else if ((num_1 < num_2) && (num_2 > num_3) && (num_1 < num_3))
	{
		sa(stack);
		ra(stack);
	}
	else if ((num_1 < num_2) && (num_2 > num_3) && (num_1 > num_3))
		rra(stack);
}

static void	case_4_5(t_node **stack_a, int target)
{
	if ((*stack_a)->next->target == target)
		sa(stack_a);
	else if ((*stack_a)->next->next->target == target)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (target == 0)
	{
		if ((*stack_a)->next->next->next->target == target)
			rra(stack_a);
		else if (target == 1)
		{
			if ((*stack_a)->next->next->next->target == target)
			{
				rra(stack_a);
				rra(stack_a);
			}
		}
	}
}

void	case_4(t_node **stack_a, t_node **stack_b)
{
	case_4_5(stack_a, 0);
	pb(stack_a, stack_b);
	case_3(stack_a);
	pa(stack_a, stack_b);
}

void	init_case_5(t_node **stack_a, t_node **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	case_3(stack_a);
}

void	move_stack(t_node **stack_a, t_node **stack_b, t_node *tmp_node)
{
	int	size_stack;

	size_stack = ft_size_stack(*stack_a);
	while(tmp_node->position == 0)
	{
		calculate_position(stack_a);
		if (tmp_node->position <= (size_stack / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
	pa(stack_a, stack_b);
}

void	case_5(t_node **stack_a, t_node **stack_b, int argc)
{
	int	count;

	count = 0;
	while (count < argc)
	{
		if ((*stack_a)->target == 0 || (*stack_a)->target == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		count++;
	}
	if ((*stack_b)->target < (*stack_b)->next->target)
		sb (stack_b);
	if (argc == 6)
		case_3(stack_a);
	else if (argc == 5)
	{
		if ((*stack_a)->target > (*stack_a)->next->target)
			sa (&(*stack_a));
	}
	while ((*stack_b) != NULL)
		pa (&(*stack_a), &(*stack_b));
}
//void	case_5(t_node **stack_a, t_node **stack_b)
//{
//	t_node *tmp_b;
//	t_node *tmp_a;
//	t_node *node_tmp;
//
//	node_tmp = (*stack_a);
//	printf("\nSTACK_A\n");
//	print_list(*stack_a);
//	printf("\nSTACK_B\n");
//	print_list(*stack_b);
//	init_case_5(stack_a, stack_b);
//	tmp_a = (*stack_a);
//	tmp_b = (*stack_b);
//	printf("\nSTACK_A\n");
//	print_list(*stack_a);
//	printf("\nSTACK_B\n");
//	print_list(*stack_b);
//	while(tmp_b)
//	{
//		tmp_a = (*stack_a);
//		while(tmp_a)
//		{
//			calculate_position(stack_a);
//			if(tmp_a->target < tmp_b->target)
//				node_tmp = tmp_a;		
//			tmp_a = tmp_a->next;
//		}
//		move_stack(stack_a, stack_b, node_tmp);
//		tmp_b = tmp_b->next;
//	}
//	printf("\nSTACK_A\n");
//	print_list(*stack_a);
//	printf("\nSTACK_B\n");
//	print_list(*stack_b);
//}

//void	case_5(t_node **stack_a, t_node **stack_b)
//{
//	case_4_5(stack_a, 1);
//	pb(stack_a, stack_b);
//	case_4_5(stack_a, 0);
//	pb(stack_a, stack_b);
//	case_3(stack_a);
//	if ((*stack_b)->target < (*stack_b)->next->target)
//		sb(stack_b);
//	pa(stack_a, stack_b);
//	pa(stack_a, stack_b);
//}
