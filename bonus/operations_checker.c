/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:34:15 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/07 22:39:22 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss_checker(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
}

void	rr_checker(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
}

void	rrr_checker(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
}

void	push_a_checker(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->size_a;
	while (j > 0)
	{
		stack->a[j] = stack->a[j - 1];
		j--;
	}
	stack->a[0] = stack->b[0];
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->size_a += 1;
	stack->size_b -= 1;
	return ;
}

void	push_b_checker(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->size_b;
	while (j > 0)
	{
		stack->b[j] = stack->b[j - 1];
		j--;
	}
	stack->b[0] = stack->a[0];
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->size_b += 1;
	stack->size_a -= 1;
	return ;
}
