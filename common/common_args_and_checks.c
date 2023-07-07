/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_args_and_checks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:34:30 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/07 23:38:23 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	check_atoli(char *arg)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	number = 0;
	if (arg[i] == '-' || arg[i] == '+')
	{
		if (arg[i] == '-')
			sign *= -1;
		i++;
	}
	while (arg[i] >= 48 && arg[i] <= 57)
	{
		number = number * 10 + (arg[i] - 48);
		i++;
	}
	if (arg[i] && (arg[i] < 48 || arg[i] > 57))
		return (-3333333333);
	if (number * sign > 2147483647 || number * sign < -2147483648)
		return (-3333333333);
	return (number * sign);
}

int	validate_argument(char **argv)
{
	int			i;
	int			j;
	long int	x;
	long int	y;

	i = 1;
	while (argv[i])
	{
		x = check_atoli(argv[i]);
		if (x == -3333333333)
			return (0);
		j = i + 1;
		while (argv[j])
		{
			y = check_atoli(argv[j]);
			if (x == y || y == -3333333333)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_order_a(t_stack *stack)
{
	int	i;

	i = stack->size_a - 1;
	while (i > 0)
	{
		if (stack->a[i] < stack->a[i - 1])
			return (1);
		i--;
	}
	return (0);
}
