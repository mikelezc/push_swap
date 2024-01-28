/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:00:53 by mlezcano          #+#    #+#             */
/*   Updated: 2024/01/28 21:28:15 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_negative(int *n, int *negative, int *aux)
{
	if (*n == -2147483648)
	{
		*n = *n + 1;
		*negative = -1;
		*aux = 1;
		*n = *n * -1;
	}
	else if (*n < 0)
	{
		*negative = -1;
		*n = *n * -1;
		*aux = 0;
	}
	else if (*n >= 0)
	{
		*negative = 1;
		*aux = 0;
	}
}

static int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static void	ft_writeintchar(char *str, int size, int n, int aux)
{
	while (n > 9)
	{
		str[size--] = (n % 10) + '0' + aux;
		n = n / 10;
		aux = 0;
	}
	str[size] = n + '0';
}

char	*ft_itoa(int n)
{
	int		negative;
	int		aux;
	int		size;
	char	*str;

	ft_negative(&n, &negative, &aux);
	size = ft_intlen(n);
	if (negative == -1)
	{
		str = malloc((size + 2) * sizeof(char));
		if (!str)
			return (0);
		size++;
		str[0] = '-';
	}
	else
	{
		str = malloc((size + 1) * sizeof(char));
		if (!str)
			return (0);
	}
	str[size--] = '\0';
	ft_writeintchar(str, size, n, aux);
	return (str);
}
/*
int main(void)
{
	printf("%s",ft_itoa(12346));

	return (0);
}*/
