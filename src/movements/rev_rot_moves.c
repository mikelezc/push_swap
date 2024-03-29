/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:14:06 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 13:54:44 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->a_len == 0 || stack->a_len == 1)
		return ;
	i = stack->a_len - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	ft_printf("rra\n");
}

void	rrb(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->b_len == 0 || stack->b_len == 1)
		return ;
	i = stack->b_len - 1;
	tmp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->a_len == 0 || stack->a_len == 1
		|| (stack->b_len == 0 || stack->b_len == 1))
		return ;
	i = stack->a_len - 1;
	tmp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	i = stack->b_len - 1;
	tmp = stack->b[i];
	while (i--)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = tmp;
	ft_printf("rrr\n");
}
