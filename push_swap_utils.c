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

int ft_atoi(char *str){
  int sign;
  int i;
  int nbr;

  sign = 1;
  i = 0;
  nbr = 0;

  if(str[0] == '-')
    sign = -1;
  while(str[i])
  {
    nbr = (nbr * 10) + (str[i] - '0');
    i++;
  }
  return (nbr * sign);
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
