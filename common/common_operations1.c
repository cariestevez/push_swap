/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_operations1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:35:47 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 20:50:36 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	int	temp;

	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
}

void	swap_b(t_stack *stack)
{
	int	temp;

	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
}

void	rotate_a(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->a[i];
	while (i < (stack->size_a - 1))
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = temp;
}

void	rotate_b(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->b[i];
	while (i < (stack->size_b - 1))
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = temp;
}
