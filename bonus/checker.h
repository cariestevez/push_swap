/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cestevez <cestevez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:33:59 by cestevez          #+#    #+#             */
/*   Updated: 2023/07/07 22:29:03 by cestevez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../src/push_swap.h"

// void	parse_string(char **argv, t_stack **stack);
void	parse_list(char **argv, t_stack *stack);

void	ss_checker(t_stack *stack);
void	rr_checker(t_stack *stack);
void	rrr_checker(t_stack *stack);
void	push_a_checker(t_stack *stack);
void	push_b_checker(t_stack *stack);

void	checker(t_stack *stack);

#endif