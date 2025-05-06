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
#include <stdio.h>

int	push_swap(char **argv, int argc)
{
  stack *stack_a; 

  stack_a = NULL;
  create_linked_list(&stack, argv, argc);
	return (0);
}

int	verify_arg(char **arg, int argc)
{
	int	i;

	i = 1;
	while(i < argc)
	{
		if(is_not_n(arg[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if(argc < 2)
	{
		write(1,"Error, few args\n",16);
		return (1);
	}
	if(verify_arg(argv, argc))
	{
		write(1,"Error args\n",11);
		return (1);
	}
	push_swap(argv, argc);
	return (0);
}
