/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:36:33 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/07 23:26:54 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	lowest_a;
	int	idx_lowest_a;
	int	highest_a;
	int	idx_highest_a;
	int	lowest_b;
	int	idx_lowest_b;
	int	highest_b;
	int	idx_highest_b;
	int	cheapest_in_a;
	int	new_index_b;
	int	cheapest_in_b;
	int	new_index_a;
	int	rotate_a;
	int	rev_rot_a;
	int	rotate_b;
	int	rev_rot_b;
}	t_stack;

int		ft_error(void);
void	free_struct(t_stack *stack, int sort_switch);
void	free_exit(t_stack *stack);

int		validate_string(char **argv);
int		validate_argument(char **argv);
long	int	check_atoli(char *arg);

void	sa(t_stack *stack);
void	sb(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	ss(t_stack *stack);
void	ra(t_stack *stack, int rot_counter);
void	rb(t_stack *stack, int rot_counter);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rr(t_stack *stack);
void	rra(t_stack *stack, int rot_counter);
void	rrb(t_stack *stack, int rot_counter);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	rrr(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	push_swap(t_stack *stack);
void	big_sort(t_stack *stack);
void	small_sort(t_stack *stack);
void	sort_three(t_stack *stack);

int		check_order_a(t_stack *stack);
int		check_order_b(t_stack *stack);

void	find_highest_b(t_stack *stack);
void	find_lowest_b(t_stack *stack);
void	find_lowest_a(t_stack *stack);
void	find_highest_a(t_stack *stack);

int		position_in_a(int num, t_stack *stack);
int		position_in_b(int num, t_stack *stack);

void	calculate_moves_ab(t_stack *stack, int size);
void	count_rotations_ab(int current_idx, int new_idx, t_stack *stack);
void	calculate_moves_ba(t_stack *stack, int size);
void	count_rotations_ba(int current_idx, int new_idx, t_stack *stack);
int		combine_rotations(t_stack *stack);
int		combine_rotations_2(t_stack *stack);

void	move_together(t_stack *stack);
void	reorganize_b(t_stack *stack);
void	reorganize_a(t_stack *stack);

void	case_rarb(t_stack *stack);
void	case_rarrb(t_stack *stack);
void	case_ra(t_stack *stack);
void	case_rrarb(t_stack *stack);
void	case_rra(t_stack *stack);
void	case_rrarrb(t_stack *stack);
void	case_rb(t_stack *stack);
void	case_rrb(t_stack *stack);

void	order_stack(t_stack *stack, char *operation);
void	reverse_rotate_or_error(t_stack *stack, char *operation);

#endif