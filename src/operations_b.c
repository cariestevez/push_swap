/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:12:33 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/06 17:05:56 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack)
{
	int	temp;

	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	ft_printf("sb\n");
}

void	rb(t_stack *stack, int rot_counter)
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
	if (rot_counter == 1)
		stack->rotate_b--;
	ft_printf("rb\n");
}

void	rrb(t_stack *stack, int rot_counter)
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
	if (rot_counter == 1)
		stack->rev_rot_b--;
	ft_printf("rrb\n");
}

void	push_b(t_stack *stack)
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
	ft_printf("pb\n");
	return ;
}
