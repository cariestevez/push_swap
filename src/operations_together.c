/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_together.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:10:31 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 21:12:59 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	ft_printf("ss\n");
}

void	rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	stack->rotate_a--;
	stack->rotate_b--;
	ft_printf("rr\n");
}

void	rrr(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	stack->rev_rot_a--;
	stack->rev_rot_b--;
	ft_printf("rrr\n");
}
