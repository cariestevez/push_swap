/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:36:23 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/08 00:01:33 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *stack)
{
	if (stack->size_a == 2)
		sa(stack);
	else
		sort_three(stack);
}

void	sort_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2])
	{
		if (stack->a[2] > stack->a[0])
		{
			sa(stack);
			ra(stack, 0);
		}
		else
			rra(stack, 0);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2])
	{
		if (stack->a[2] > stack->a[0])
			sa(stack);
		else
			ra(stack, 0);
	}
	else
	{
		ra(stack, 0);
		sa(stack);
	}
}

//calculates the best combo of stack rotations for each number
//and saves the cheapest
//rotates the two stacks to receive the cheapest
//pushes the cheapest
//checks if lowest num is already in last possition
//or if stack has to be rotated
void	big_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack->size_a > 3)
	{
		calculate_moves_ab(stack, stack->size_a);
		count_rotations_ab(stack->cheapest_in_a, stack->new_index_b, stack);
		move_together(stack);
		push_b(stack);
	}
	if (check_order_a(stack) != 0)
		sort_three(stack);
	while (stack->size_b != 0)
	{
		calculate_moves_ba(stack, stack->size_b);
		count_rotations_ba(stack->cheapest_in_b, stack->new_index_a, stack);
		move_together(stack);
		push_a(stack);
	}
	reorganize_a(stack);
}

void	push_swap(t_stack *stack)
{
	int	i;

	i = 0;
	if (check_order_a(stack) != 0)
	{
		if (stack->size_a <= 3)
		{
			small_sort(stack);
			free_struct(stack, 0);
		}
		else
		{
			stack->b = (int *)malloc(sizeof(int) * stack->size_a);
			if (!stack->b)
				exit(1);
			stack->size_b = 0;
			push_b(stack);
			push_b(stack);
			big_sort(stack);
			free_struct(stack, 1);
		}
	}
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
	stack->a = (int *)malloc(sizeof(int) * stack->size_a);
	while (argv[i + 1])
	{
		stack->a[i] = check_atoli(argv[i + 1]);
		i++;
	}
	if (check_order_a(stack) == 0)
		free_exit(stack);
	push_swap(stack);
	return (0);
}
