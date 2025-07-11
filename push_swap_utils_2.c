#include "push_swap.h"

int find_the_last_pos(node **stack_a)
{
	node *tmp;
	int flag;
	int pos;
	int size_stack;

	pos = 0;
	tmp = (*stack_a);
	flag = tmp->target;
	size_stack = ft_size_stack(stack_a);
	while(tmp)
	{
		if(tmp->target > flag)
		{ flag = tmp->target;
			pos = tmp->position;
		}
		tmp = tmp->next;
	}
	if(pos > (size_stack / 2))
		return (pos - size_stack);
	return (pos + 1);
}

int	target_z_selector(int pos_in_stack_a, node **stack_a, node *target_tmp)
{
	int i;
	node *tmp;
	int size_stack;

	i = 0;
	size_stack = ft_size_stack(stack_a);
	tmp = (*stack_a);
	while(i < pos_in_stack_a && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if(pos_in_stack_a <= (size_stack / 2) && target_tmp->target < tmp->target)
		return (2);
	else if(pos_in_stack_a > (size_stack / 2) && target_tmp->target < tmp->target)
		return (3);
	else if(pos_in_stack_a <= (size_stack / 2) && target_tmp->target > tmp->target)
		return (1);
	else if(pos_in_stack_a > (size_stack / 2) && target_tmp->target > tmp->target)
		return (4);
	return (0);
}

void reposition_stack(node **stack_a)
{
	node *stack_a_tmp;
	int pos_zero;
	int size_stack;
	int i;

	
	i = 0;
	size_stack = ft_size_stack(stack_a);
	pos_zero = find_the_last_pos(stack_a);
	stack_a_tmp = (*stack_a);
	while(i < pos_zero)
	{
		if(pos_zero <= (size_stack / 2))
			ra(stack_a);
		else 
			rra(stack_a);
		i++;
	}
}
