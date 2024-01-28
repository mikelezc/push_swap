/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:14:36 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 13:54:52 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->a_len == 0 || stack->a_len == 1)
		return ;
	i = 0;
	tmp = stack->a[i];
	i++;
	while (i < stack->a_len)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = tmp;
	ft_printf("ra\n");
}

void	rb(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->b_len == 0 || stack->b_len == 1)
		return ;
	i = 0;
	tmp = stack->b[i];
	i++;
	while (i < stack->b_len)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	ft_printf("rb\n");
}

void	rr(t_stacks *stack)
{
	int	tmp;
	int	i;

	if (stack->a_len == 0 || stack->a_len == 1
		|| (stack->b_len == 0 || stack->b_len == 1))
		return ;
	i = 0;
	tmp = stack->a[i];
	while (++i < stack->a_len)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = tmp;
	i = 0;
	tmp = stack->b[i];
	while (++i < stack->b_len)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = tmp;
	ft_printf("rr\n");
}
