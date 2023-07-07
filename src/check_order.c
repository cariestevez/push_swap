/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:35:36 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/05 20:54:33 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check_order_a in common/common_functions.c
int	check_order_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->size_b)
	{
		if (stack->b[i] < stack->b[i + 1])
			return (1);
		i++;
	}
	return (0);
}
