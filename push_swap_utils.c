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

static int index_increment(node *node_tmp, node *stack)
{
  int index_num;
  node *tmp;

  index_num = 0;
  tmp = stack;
  while(tmp)
  {
    if(node_tmp->num > tmp->num)
      index_num++;
    tmp = tmp->next;
  }
  return (index_num);
}

void  index_assign(node **stack)
{
  node *node_tmp;
  int index_num;

  node_tmp = *stack;
  while(node_tmp)
  {
    index_num = index_increment(node_tmp, *stack);
    node_tmp->target = index_num;
    node_tmp = node_tmp->next;
  }
}

int ft_atoi(char *str)
{
  int sign;
  int i;
  long nbr;

  sign = 1;
  i = 0;
  nbr = 0;

  if(str[i] == '-')
  {
    sign = -1;
    i++;
  }
  while(str[i])
  {
    nbr = (nbr * 10) + (str[i] - '0');
    i++;
  }
  if((nbr * sign < INT_MIN) || (nbr * sign > INT_MAX))
  {
    write(1,"Error, limits int\n",18);
    return (1);
  }
  return ((int)(nbr * sign));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	is_not_n(char *str)
{
	int	i;
	int	flag;
	
	i = 0;
	flag = 0;
	while(str[i])
	{
		if((str[i] == '-' && flag == 0) || (str[i] == '+' && flag == 0))
		{
			flag = 1;
			i++;
		}
		else if((str[i] == '-' && flag == 1) || (str[i] == '+' && flag == 1))
			return (1);
		if(str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}
