/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:00:38 by rubmedin          #+#    #+#             */
/*   Updated: 2025/08/21 03:10:05 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long		i;
	long		result;
	long		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		(i)++;
	}
	if (result >= INT_MAX || result <= INT_MIN)
		return (INT_MIN);
	return (result *= sign);
}

int	ft_isdupli(int argc, char **argv)
{
	int		count;
	int		count2;
	long	num1;
	long	num2;

	count = 1;
	while (count < argc)
	{
		count2 = count + 1;
		num1 = ft_atoi(argv[count]);
		if(num1 == INT_MIN)
			return (1);
		while (count2 < argc)
		{
			num2 = ft_atoi(argv[count2]);
			if (num1 == num2 || num2 == INT_MIN)
				return (1);
			count2++;
		}
		count++;
	}
	return (0);
}
