/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_cases_single.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:36:44 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/06 16:40:57 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_ra(t_stack *stack)
{
	while (stack->rotate_a > 0)
		ra(stack, 1);
}

void	case_rra(t_stack *stack)
{
	while (stack->rev_rot_a > 0)
		rra(stack, 1);
}

void	case_rb(t_stack *stack)
{
	while (stack->rotate_b > 0)
		rb(stack, 1);
}

void	case_rrb(t_stack *stack)
{
	while (stack->rev_rot_b > 0)
		rrb(stack, 1);
}
