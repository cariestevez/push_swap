/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:36:38 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/06 16:40:20 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reorganize_b(t_stack *stack)
{
	find_highest_b(stack);
	while (stack->idx_highest_b != 0)
	{
		if (stack->idx_highest_b <= stack->size_b / 2)
			rb(stack, 1);
		else
			rrb(stack, 1);
		find_highest_b(stack);
	}
}

void	reorganize_a(t_stack *stack)
{
	find_lowest_a(stack);
	while (stack->idx_lowest_a != 0)
	{
		if (stack->idx_lowest_a <= stack->size_a / 2)
			ra(stack, 1);
		else
			rra(stack, 1);
		find_lowest_a(stack);
	}
}

void	move_together(t_stack *stack)
{
	if (stack->rotate_a != 0 && stack->rotate_b != 0)
		case_rarb(stack);
	else if (stack->rotate_a != 0 && stack->rev_rot_b != 0)
		case_rarrb(stack);
	else if (stack->rotate_a != 0 && stack->rotate_b == 0
		&& stack->rev_rot_b == 0)
		case_ra(stack);
	else if (stack->rev_rot_a != 0 && stack->rotate_b != 0)
		case_rrarb(stack);
	else if (stack->rev_rot_a != 0 && stack->rotate_b == 0
		&& stack->rev_rot_b == 0)
		case_rra(stack);
	if (stack->rev_rot_a != 0 && stack->rev_rot_b != 0)
		case_rrarrb(stack);
	if (stack->rotate_a == 0 && stack->rev_rot_a == 0 && stack->rotate_b != 0)
		case_rb(stack);
	if (stack->rotate_a == 0 && stack->rev_rot_a == 0 && stack->rev_rot_b != 0)
		case_rrb(stack);
	else
		return ;
}
