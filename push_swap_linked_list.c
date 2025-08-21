/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_linked_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:33:52 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/14 11:26:09 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	print_list(t_node *stack)
{
	while (stack != NULL)
	{
		printf("t_node_num: %d  ---- t_node_pos: %i ----  t_node_index: %i  ----  t_node_cost_b: %i ----  t_node_cost_a: %i ---- t_node_share: %i\n", stack->num, stack->position , stack->target, stack->cost_b, stack->cost_a, stack->shared_cost);
		stack = stack->next;
	}
}

void	free_list(t_node *stack)
{
	t_node	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	add_t_node_to_list(t_node **stack, t_node *t_node_a)
{
	t_node	*t_node_tmp;

	t_node_tmp = *stack;
	while (t_node_tmp->next != NULL)
		t_node_tmp = t_node_tmp->next;
	t_node_tmp->next = t_node_a;
}

t_node	*create_t_node(int valor)
{
	t_node	*t_node_tmp;

	t_node_tmp = malloc(sizeof(t_node));
	if (!t_node_tmp)
		return (NULL);
	t_node_tmp->num = valor;
	t_node_tmp->next = NULL;
	return (t_node_tmp);
}

int	create_linked_list(t_node **stack, char **argv, int argc)
{
	t_node	*t_node_tmp;
	int		i;
	int		num_atoi;

	i = 1;
	while (i < argc)
	{
		num_atoi = ft_atoi(argv[i]);
		if (num_atoi == INT_MIN)
			return (INT_MIN);
		t_node_tmp = create_t_node(num_atoi);
		if (t_node_tmp == NULL)
			return (1);
		if (*stack == NULL)
			*stack = t_node_tmp;
		else
			add_t_node_to_list(stack, t_node_tmp);
		i++;
	}
	index_assign(stack);
	return (0);
}
