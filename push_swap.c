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

static int verify_num(node *stack_a) {
  node *node_tmp;
  node *node_count;

  node_count = stack_a;
  while (node_count) {
    node_tmp = node_count->next;
    while (node_tmp) {
      if (node_tmp->num == node_count->num) {
        write(1, "Error, num duplicate\n", 21);
        return (1);
      }
      node_tmp = node_tmp->next;
    }
    node_count = node_count->next;
  }
  return (0);
}

static int push_swap(char **argv, int argc) {
  node *stack_a;
  node *stack_b;

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
  free_list(stack_a);
  return (0);
}

static int verify_arg(char **arg, int argc) {
  int i;

  i = 1;
  while (i < argc) {
    if (is_not_n(arg[i]))
      return (1);
    i++;
  }
  return (0);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    write(1, "Error, args\n", 12);
    return (1);
  }
  if (verify_arg(argv, argc)) {
    write(1, "Error args\n", 11);
    return (1);
  }
  if (push_swap(argv, argc))
    return (1);
  return (0);
}
