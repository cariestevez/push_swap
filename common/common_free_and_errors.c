/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_free_and_errors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:40:09 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/07 22:02:15 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_exit(t_stack *stack)
{
	free_struct(stack, 0);
	exit(0);
}

void	free_struct(t_stack *stack, int sort_switch)
{
	free(stack->a);
	if (sort_switch == 1)
		free(stack->b);
	if (stack)
		free(stack);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
