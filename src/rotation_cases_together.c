/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cases_together.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:13:57 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/06 16:41:59 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_rarb(t_stack *stack)
{
	if (stack->rotate_a >= stack->rotate_b)
	{
		while (stack->rotate_b > 0)
			rr(stack);
		while (stack->rotate_a > 0)
			ra(stack, 1);
	}
	else
	{
		while (stack->rotate_a > 0)
			rr(stack);
		while (stack->rotate_b > 0)
			rb(stack, 1);
	}
}

void	case_rarrb(t_stack *stack)
{
	while (stack->rotate_a > 0)
		ra(stack, 1);
	while (stack->rev_rot_b > 0)
		rrb(stack, 1);
}

void	case_rrarb(t_stack *stack)
{
	while (stack->rev_rot_a > 0)
		rra(stack, 1);
	while (stack->rotate_b > 0)
		rb(stack, 1);
}

void	case_rrarrb(t_stack *stack)
{
	if (stack->rev_rot_a >= stack->rev_rot_b)
	{
		while (stack->rev_rot_b > 0)
			rrr(stack);
		while (stack->rev_rot_a > 0)
			rra(stack, 1);
	}
	else
	{
		while (stack->rev_rot_a > 0)
			rrr(stack);
		while (stack->rev_rot_b > 0)
			rrb(stack, 1);
	}
}
