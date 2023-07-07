/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_highest_lowest.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:35:43 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 20:54:11 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_highest_b(t_stack *stack)
{
	int	i;

	i = 1;
	stack->highest_b = stack->b[0];
	stack->idx_highest_b = 0;
	while (i < stack->size_b)
	{
		if (stack->highest_b < stack->b[i])
		{
			stack->highest_b = stack->b[i];
			stack->idx_highest_b = i;
		}
		i++;
	}
	return ;
}

void	find_lowest_b(t_stack *stack)
{
	int	i;

	i = 1;
	stack->lowest_b = stack->b[0];
	stack->idx_lowest_b = 0;
	while (i < stack->size_b)
	{
		if (stack->lowest_b > stack->b[i])
		{
			stack->lowest_b = stack->b[i];
			stack->idx_lowest_b = i;
		}
		i++;
	}
	return ;
}

void	find_highest_a(t_stack *stack)
{
	int	i;

	i = 1;
	stack->highest_a = stack->a[0];
	stack->idx_highest_a = 0;
	while (i < stack->size_a)
	{
		if (stack->highest_a < stack->a[i])
		{
			stack->highest_a = stack->a[i];
			stack->idx_highest_a = i;
		}
		i++;
	}
	return ;
}

void	find_lowest_a(t_stack *stack)
{
	int	i;

	i = 1;
	stack->lowest_a = stack->a[0];
	stack->idx_lowest_a = 0;
	while (i < stack->size_a)
	{
		if (stack->lowest_a > stack->a[i])
		{
			stack->lowest_a = stack->a[i];
			stack->idx_lowest_a = i;
		}
		i++;
	}
	return ;
}
