/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 10:27:09 by rubmedin          #+#    #+#             */
/*   Updated: 2025/07/23 17:34:21 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct stack
{
	int				num;
	int				position;
	int				target;
	int				cost_a;
	int				cost_b;
	struct stack	*objective;
	struct stack	*next;
}	t_node;

int		is_not_n(char *str);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	free_list(t_node *stack);
void	add_t_node_to_list(t_node **stack, t_node *t_node);
t_node	*create_t_node(int valor);
int		create_linked_list(t_node **stack, char **argv, int argc);
void	sort_algorithm(t_node **stack_a, t_node **stack_b);
void	index_assign(t_node **stack);
int		ft_size_stack(t_node *stack_a);
void	make_instruction(t_node *target, t_node **stack_a, t_node **stack_b);
void	calculate_position(t_node **stack);
t_node	*find_pos(t_node **stack_a, t_node *target);
void	prepare_stacks(t_node *target, t_node **stack_a, t_node **stack_b);
t_node	*find_the_last_pos(t_node **stack_a);
int		target_z_selector(int pos_in_stack_a, t_node **stack_a, t_node *target_tmp);
void	reposition_stack(t_node **stack_a);
void	prepare_stack_a(t_node *target, t_node **stack_a);
void	prepare_stack_b(t_node *target, t_node **stack_a);
void	asign_objective(t_node *stack_a, t_node *stack_b);
void	fill_node(t_node **stack_a, t_node **stack_b);
void	find_objective(t_node **stack_a, t_node **stack_b);
void	calculate_cost_stack(t_node **stack_a, t_node **stack_b, int flag);
void	cost_b(t_node **stack_b);
void	cost_a(t_node **stack_a, t_node **stack_b);
void	prepare_stack_normal(t_node *target, t_node **stack_b);
void	prepare_stack_reverse(t_node *target, t_node **stack_b);
int		checker_and_reverse(int	nbr);

void	case_2(t_node **stack);
void	case_3(t_node **stack);
void	case_4(t_node **stack_a, t_node **stack_b);
void	case_5(t_node **stack_a, t_node **stack_b);

void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack);
void	rrb(t_node **stack);
void	rrr(t_node **stack_a, t_node **stack_b);
// borrar apartir de aqui son funciones para probar.
void	print_list(t_node *stack);
#endif
