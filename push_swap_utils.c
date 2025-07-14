/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:03:42 by rubmedin          #+#    #+#             */
/*   Updated: 2025/05/05 13:45:07 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_increment(t_node *t_node_tmp, t_node *stack)
{
	int		index_num;
	t_node	*tmp;

	index_num = 0;
	tmp = stack;
	while (tmp)
	{
		if (t_node_tmp->num > tmp->num)
			index_num++;
		tmp = tmp->next;
	}
	return (index_num);
}

void	index_assign(t_node **stack)
{
	t_node	*t_node_tmp;
	int		index_num;

	t_node_tmp = *stack;
	while (t_node_tmp)
	{
		index_num = index_increment(t_node_tmp, *stack);
		t_node_tmp->target = index_num;
		t_node_tmp = t_node_tmp->next;
	}
}

int	ft_atoi(char *str)
{
	int		sign;
	int		i;
	long	nbr;

	sign = 1;
	i = 0;
	nbr = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	if ((nbr * sign < INT_MIN) || (nbr * sign > INT_MAX))
	{
		write(1, "Error, limits int\n", 18);
		return (1);
	}
	return ((int)(nbr * sign));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_not_n(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if ((str[i] == '-' && flag == 0) || (str[i] == '+' && flag == 0))
		{
			flag = 1;
			i++;
		}
		else if ((str[i] == '-' && flag == 1) || (str[i] == '+' && flag == 1))
			return (1);
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}
