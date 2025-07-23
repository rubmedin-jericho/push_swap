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

int	search_low_index(t_node **stack_a)
{
	t_node	*tmp;
	int		target_rtn;

	target_rtn = (*stack_a)->target;
	tmp = (*stack_a);
	while(tmp)
	{
		//ESTA FUNCION PETA AQUI.
		if(tmp->target < target_rtn)
			target_rtn = tmp->target;
		tmp = tmp->next;
	}
	return (target_rtn);
}

t_node	*find_pos(t_node **stack_a, t_node *target)
{
	t_node	*tmp;
	//int		flag;
	t_node	*t_node_return;

	t_node_return = (*stack_a);
	tmp = (*stack_a);
	//flag = 0;
	while (tmp)
	{
		//else if (tmp->target >= flag && tmp->target < target->target)
		if (target->target == 0)
			t_node_return = find_the_last_pos(stack_a);
		//LA LINIA DE ABAJO ES LA QUE TIENES QUE CAMBIAR, ESTA CAMBIADA PERO NO FUNCIONA PUEDE SER POR LA FUNCION.
		else if (tmp->target == search_low_index(stack_a))
		{
			//flag = tmp->target;
			t_node_return = tmp;
		}
		tmp = tmp->next;
	}
	return (t_node_return);
}

void	cost_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		size_stack;

	tmp = (*stack_b);
	size_stack = ft_size_stack(stack_a);
	while (tmp)
	{
		calculate_position(stack_a);
		if (tmp->objective->position <= (size_stack / 2) && tmp->objective->position >= 0)
		{
			tmp->cost_a = tmp->objective->position;
			//editar la linia de abajo cuando la struct en vez de usar el objective use el t_node
			if (tmp->objective->target < tmp->target)
				tmp->cost_a += 1;
		}
		else if (tmp->objective->position > (size_stack / 2))
		{
			tmp->cost_a = tmp->objective->position - size_stack;
			if(tmp->cost_a == -1)
				tmp->cost_a = 0;
		}
		printf("\n--- TARGET_B: %i\n--- OBJETIVO_POS: %i\n", tmp->target, tmp->objective->position);
		tmp = tmp->next;
	}
}

void	prepare_stacks(t_node *target, t_node **stack_a, t_node **stack_b)
{
	//if (target->cost_b <= (ft_size_stack(stack_b) / 2))
	//else if (target->cost_b > (ft_size_stack(stack_b) / 2))
	if (target->cost_b > 0)
		prepare_stack_normal(target, stack_a, stack_b);
	else if (target->cost_b < 0)
		prepare_stack_reverse(target, stack_a, stack_b);
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
