/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_operations2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:35:41 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 20:51:18 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = temp;
}

void	reverse_rotate_b(t_stack *stack)
{
	int	i;
	int	temp;

	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
}
