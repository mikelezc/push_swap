/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:00:03 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 13:01:56 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_push(t_stacks *stack, int len, int operation)
{
	if (operation == 0)
		pb(stack);
	else
		pa(stack);
	len--;
	return (len);
}

int	ps_sort_small_b(t_stacks *stack, int len)
{
	if (len == 1)
		pa(stack);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack);
		while (len--)
			pa(stack);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				sa(stack);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1])
				|| (len == 3 && stack->b[0] > stack->b[2]))
				len = ps_push(stack, len, 1);
			else
				sb(stack);
		}
	}
	return (0);
}

void	ps_sort_small_a(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ps_sort_three_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ps_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack);
			else if (len++)
				pa(stack);
		}
	}
}

void	ps_bubble_sort(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ps_find_pivot(int *pivot, int *stack, int len)
{
	int		*tmp_stack;
	int		i;

	tmp_stack = (int *)malloc(len * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < len)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	ps_bubble_sort(tmp_stack, len);
	*pivot = tmp_stack[len / 2];
	free(tmp_stack);
	return (1);
}
