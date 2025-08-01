/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:15:36 by rubmedin          #+#    #+#             */
/*   Updated: 2025/05/05 16:55:47 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recuento_del_stack(t_node *stack_a)
{
	t_node	*tmp;
	int		i;
	int		size_stack;

	i = 0;
	size_stack = ft_size_stack(stack_a);
	tmp = stack_a;
	while(tmp)
	{
		if (i == tmp->target)
			i++;
		tmp = tmp->next;
	}
	if(i == ft_size_stack(stack_a))
		printf("\n********* OK ********\n");
	else	
		printf("\n********* MAL KO TARGET: %i ********\n", i);
}

static int	verify_num(t_node *stack_a)
{
	t_node	*t_node_tmp;
	t_node	*t_node_count;

	t_node_count = stack_a;
	while (t_node_count)
	{
		t_node_tmp = t_node_count->next;
		while (t_node_tmp)
		{
			if (t_node_tmp->num == t_node_count->num)
			{
				write(1, "Error, num duplicate\n", 21);
				return (1);
			}
			t_node_tmp = t_node_tmp->next;
		}
		t_node_count = t_node_count->next;
	}
	return (0);
}

static int	push_swap(char **argv, int argc)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (create_linked_list(&stack_a, argv, argc))
		return (1);
	if (verify_num(stack_a))
		return (1);
	if (argc > 6)
		sort_algorithm(&stack_a, &stack_b);
	else if (argc == 3)
		case_2(&stack_a);
	else if (argc == 4)
		case_3(&stack_a);
	else if (argc == 5)
		case_4(&stack_a, &stack_b);
	else if (argc == 6)
		case_5(&stack_a, &stack_b);
	reposition_stack(&stack_a);
	printf("\n********* FINISH *********\n");
	printf("\nSTACK_A\n");
	print_list(stack_a);
	printf("\nSTACK_B\n");
	print_list(stack_b);
	recuento_del_stack(stack_a);
	free_list(stack_a);
	return (0);
}

static int	verify_arg(char **arg, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_not_n(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error few args\n", 15);
		return (2);
	}
	if (verify_arg(argv, argc))
	{
		write(1, "Error with args\n", 16);
		return (2);
	}
	if (push_swap(argv, argc))
		return (1);
	return (0);
}
