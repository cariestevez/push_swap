/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_new_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:36:01 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 15:16:22 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	position_in_a(int num, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->size_a - 1;
	find_highest_a(stack);
	find_lowest_a(stack);
	if (num < stack->lowest_a || num > stack->highest_a)
		return (stack->idx_lowest_a);
	if (num < stack->a[i])
	{
		if (num > stack->a[j])
			return (0);
		while (num < stack->a[j] && j >= 0)
			j--;
		return (j + 1);
	}
	else
	{
		while (num > stack->a[i] && i < stack->size_a)
			i++;
		return (i);
	}
}

int	position_in_b(int num, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = stack->size_b - 1;
	find_highest_b(stack);
	find_lowest_b(stack);
	if (num < stack->lowest_b || num > stack->highest_b)
		return (stack->idx_highest_b);
	else if (num > stack->b[i])
	{
		if (num < stack->b[j])
			return (0);
		while (num > j && j >= 0)
			j--;
		return (j + 1);
	}
	else
	{
		while (num < stack->b[i] && i < stack->size_b)
			i++;
		return (i);
	}
}
