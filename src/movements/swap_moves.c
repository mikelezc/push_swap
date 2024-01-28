/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:15:16 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 13:54:59 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stacks *stack)
{
	int	tmp;

	if (stack->a_len == 0 || stack->a_len == 1)
		return ;
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	ft_printf("sa\n");
}

void	sb(t_stacks *stack)
{
	int	tmp;

	if (stack->b_len == 0 || stack->b_len == 1)
		return ;
	tmp = 0;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	ft_printf("sb\n");
}

void	ss(t_stacks *stack)
{
	int	tmp;

	if (stack->a_len == 0 || stack->a_len == 1
		|| (stack->b_len == 0 || stack->b_len == 1))
		return ;
	tmp = 0;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	ft_printf("ss\n");
}
