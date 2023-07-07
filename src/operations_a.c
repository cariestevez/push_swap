/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:36:17 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/06 17:05:35 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
{
	int	temp;

	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	ft_printf("sa\n");
}

void	ra(t_stack *stack, int rot_counter)
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
	if (rot_counter == 1)
		stack->rotate_a--;
	ft_printf("ra\n");
}

void	rra(t_stack *stack, int rot_counter)
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
	if (rot_counter == 1)
		stack->rev_rot_a--;
	ft_printf("rra\n");
}

void	push_a(t_stack *stack)
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
	ft_printf("pa\n");
	return ;
}
