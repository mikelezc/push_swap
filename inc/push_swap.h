/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 11:08:58 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:13:05 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	a_len;
	int	b_len;
}	t_stacks;

# define ASC 0
# define DES 1

//push_swap(main)
void	push_swap(char **argv, int free_flg);
void	free_str_array(char **str_array);
int		ps_plus_alone(char *str);

//Check
int		ps_arr_len(char **argv);
void	ps_error_msg(int *stack);
int		ps_atoi_lim(char *str, int *stack);
void	ps_is_repeat(int *stack, int size);
int		ps_is_sorted(int *pile, int size, int order);

//sort_small
int		ps_sort(t_stacks *stack, int size);
void	ps_sort_three_a(t_stacks *s);

//sort_big
int		ps_quick_sort_a(t_stacks *stack, int size, int counter);
int		ps_quick_sort_b(t_stacks *stack, int len, int counter);

//sort_big_utils

void	ps_sort_small_a(t_stacks *stack, int len);
int		ps_sort_small_b(t_stacks *stack, int len);
int		ps_find_pivot(int *pivot, int *stack, int size);
void	ps_bubble_sort(int *tmp_stack, int size);
int		ps_push(t_stacks *stack, int len, int operation);

//movements
void	sa(t_stacks *stack);
void	sb(t_stacks *stack);
void	ss(t_stacks *stack);
void	ra(t_stacks *stack);
void	rb(t_stacks *stack);
void	rr(t_stacks *stack);
void	rra(t_stacks *stack);
void	rrb(t_stacks *stack);
void	rrr(t_stacks *stack);
void	pb(t_stacks *stack);
void	pa(t_stacks *stack);

#endif