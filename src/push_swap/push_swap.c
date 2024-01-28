/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:08:05 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 18:59:16 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_str_array(char **str_array)
{
	int	i;

	i = 0;
	if (str_array)
	{
		while (str_array[i])
			free(str_array[i++]);
		free(str_array);
	}
}

void	push_swap(char **argv, int free_flg)
{
	int			i;
	int			len;
	t_stacks	stack;

	i = -1;
	len = ps_arr_len(argv);
	stack.a = malloc(len * sizeof(int));
	if (!stack.a)
		return ;
	stack.a_len = len;
	stack.b = malloc(len * sizeof(int));
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.b_len = 0;
	while (++i < len)
		stack.a[i] = ps_atoi_lim(argv[i], stack.a);
	ps_is_repeat(stack.a, len);
	ps_sort(&stack, len);
	free(stack.a);
	free(stack.b);
	if (free_flg)
		free_str_array(argv);
}

void	leaks(void)
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	int	free_flg;

	free_flg = 0;
	atexit(leaks);
	if (!(1 == argc || (2 == argc && !argv[1][0])))
	{
		argv++;
		if (argc == 2)
		{
			argv = ft_split(*argv, ' ');
			free_flg = 1;
		}
		push_swap(argv, free_flg);
		return (0);
	}
	return (0);
}
