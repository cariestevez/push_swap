/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:35:30 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 21:04:45 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_moves_ab(t_stack *stack, int size)
{
	int	i;
	int	temp_idx;
	int	moves;
	int	saved_moves;

	i = 0;
	temp_idx = 0;
	moves = 0;
	saved_moves = 0;
	while (i < size)
	{
		temp_idx = position_in_b(stack->a[i], stack);
		count_rotations_ab(i, temp_idx, stack);
		moves = combine_rotations(stack);
		if (i == 0 || moves < saved_moves)
		{
			saved_moves = moves;
			stack->cheapest_in_a = i;
			stack->new_index_b = temp_idx;
		}
		i++;
	}
	return ;
}

void	count_rotations_ab(int current_idx, int new_idx, t_stack *stack)
{
	stack->rotate_a = 0;
	stack->rev_rot_a = 0;
	stack->rotate_b = 0;
	stack->rev_rot_b = 0;
	if (current_idx <= (stack->size_a / 2))
		stack->rotate_a = current_idx;
	if (current_idx > (stack->size_a / 2))
		stack->rev_rot_a = stack->size_a - current_idx;
	if (new_idx <= (stack->size_b / 2))
		stack->rotate_b = new_idx;
	if (new_idx > (stack->size_b / 2))
		stack->rev_rot_b = stack->size_b - new_idx;
}
