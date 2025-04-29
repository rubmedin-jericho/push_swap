/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:15:36 by rubmedin          #+#    #+#             */
/*   Updated: 2025/04/29 20:15:39 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	push_swap(char **argv)
{
	int	i = 0;
	while(argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if(argc <= 1)
		return (1);
	push_swap(argv);
	return (0);
}
