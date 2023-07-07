/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:33:46 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/07 23:59:24 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	order_stack(t_stack *stack, char *operation)
{
	if (ft_strncmp(operation, "pa\n", 3) == 0)
		push_a_checker(stack);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		push_b_checker(stack);
	else if (ft_strncmp(operation, "sa\n", 3) == 0)
		swap_a(stack);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		swap_b(stack);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ss_checker(stack);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		rotate_a(stack);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rotate_b(stack);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rr_checker(stack);
	else
		reverse_rotate_or_error(stack, operation);
}

void	reverse_rotate_or_error(t_stack *stack, char *operation)
{
	if (ft_strncmp(operation, "rra\n", 4) == 0)
		reverse_rotate_a(stack);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		reverse_rotate_b(stack);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		rrr_checker(stack);
	else
	{
		free_struct(stack, 1);
		free(operation);
		ft_error();
	}
}

void	checker(t_stack *stack)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation != 0)
	{
		order_stack(stack, operation);
		free(operation);
		operation = get_next_line(0);
	}
	if (!operation && check_order_a(stack) == 0 && stack->size_b == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 0;
	if (argc <= 2)
	{
		if (argc == 2 && validate_argument(argv) == 0)
			ft_error();
		exit(0);
	}
	if (validate_argument(argv) == 0)
		ft_error();
	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size_a = argc - 1;
	stack->a = (int *)malloc(sizeof(int) * (stack->size_a));
	while (argv[i + 1])
	{
		stack->a[i] = check_atoli(argv[i + 1]);
		i++;
	}
	stack->b = (int *)malloc(sizeof(int) * stack->size_a);
	stack->size_b = 0;
	checker(stack);
	free_struct(stack, 1);
	return (0);
}
