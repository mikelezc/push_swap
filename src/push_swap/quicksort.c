/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:11:31 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/26 13:12:29 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_quicksort_3(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		ps_sort_three_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			sa(stack, OPT);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				sa(stack, OPT);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ps_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				sa(stack, OPT);
			else if (len++)
				pa(stack, OPT);
		}
	}
}

int	ft_sort_small_b(t_stacks *s, int len)
{
	if (len == 1)
		pa(s, OPT);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			sb(s, OPT);
		while (len--)
			pa(s, OPT);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				sa(s, OPT);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1])
				|| (len == 3 && s->b[0] > s->b[2]))
				len = ps_push(s, len, 1);
			else
				sb(s, OPT);
		}
	}
	return (0);
}

int	ft_get_mediane(int *pivot, int *stack, int size)
{
	int		*tmp_stack;
	int		i;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	ps_sort_tmp(tmp_stack, size);
	*pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

int	ft_quicksort_b(t_stacks *stack, int len, int counter)
{
	int	pivot;
	int	items;

	if (!counter && ps_is_sorted(stack->b, len, DESCENDING) == 1)
		while (len--)
			pa(stack, OPT);
	if (len <= 3)
	{
		ft_sort_small_b(stack, len);
		return (1);
	}
	items = len;
	if (!ft_get_mediane(&pivot, stack->b, len))
		return (0);
	while (len != items / 2)
	{
		if (stack->b[0] >= pivot && len--)
			pa(stack, OPT);
		else if (++counter)
			rb(stack, OPT);
	}
	while (items / 2 != stack->size_b && counter--)
		rrb(stack, OPT);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
}

int	ft_quicksort_a(t_stacks *stack, int len, int counter)
{
	int	pivot;
	int	items;

	if (ps_is_sorted(stack->a, len, ASCENDING) == 1)
		return (1);
	items = len;
	if (len <= 3)
	{
		ft_quicksort_3(stack, len);
		return (1);
	}
	if (!counter && !ft_get_mediane(&pivot, stack->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (stack->a[0] < pivot && (len--))
			pb(stack, OPT);
		else if (++counter)
			ra(stack, OPT);
	}
	while (items / 2 + items % 2 != stack->size_a && counter--)
		rra(stack, OPT);
	return (ft_quicksort_a(stack, items / 2 + items % 2, 0)
		&& ft_quicksort_b(stack, items / 2, 0));
	return (1);
}
