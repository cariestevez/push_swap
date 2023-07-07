/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:04:59 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 21:07:30 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// possible cases.		ra rb||ra 0||	ra rrb
//					rra rb	||rra 0||rra rrb
//						0 rb||0 0 ||0 rrb
int	combine_rotations(t_stack *stack)
{
	if ((stack->rotate_a != 0 && stack->rotate_b != 0)
		|| (stack->rev_rot_a != 0 && stack->rev_rot_b != 0))
		return (combine_rotations_2(stack));
	if (stack->rotate_a != 0 && stack->rev_rot_b != 0)
		return (stack->rotate_a + stack->rev_rot_b);
	if (stack->rotate_a != 0 && stack->rotate_b == 0 && stack->rev_rot_b == 0)
		return (stack->rotate_a);
	if (stack->rev_rot_a != 0 && stack->rotate_b != 0)
		return (stack->rev_rot_a + stack->rotate_b);
	if (stack->rev_rot_a != 0 && stack->rotate_b == 0 && stack->rev_rot_b == 0)
		return (stack->rev_rot_a);
	if (stack->rotate_a == 0 && stack->rev_rot_a == 0 && stack->rotate_b != 0)
		return (stack->rotate_b);
	if (stack->rotate_a == 0 && stack->rev_rot_a == 0 && stack->rev_rot_b != 0)
		return (stack->rev_rot_b);
	else
		return (0);
}

int	combine_rotations_2(t_stack *stack)
{
	if (stack->rotate_a != 0 && stack->rotate_b != 0)
	{
		if (stack->rotate_a >= stack->rotate_b)
			return (stack->rotate_a);
		else
			return (stack->rotate_b);
	}
	else
	{
		if (stack->rev_rot_a >= stack->rev_rot_b)
			return (stack->rev_rot_a);
		else
			return (stack->rev_rot_b);
	}
}
