/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 05:05:57 by ydang             #+#    #+#             */
/*   Updated: 2016/11/02 07:25:19 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	itoa_isneg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
}

char	*ft_itoa(int n)
{
	int		tmp;
	int		len;
	int		neg;
	char	*s;

	if (n == -2147483648)
		return ("-2147483648");
	tmp = n;
	len = 2;
	neg = 0;
	itoa_isneg(&n, &neg);
	while (tmp /= 10)
		len++;
	len += neg;
	if ((s = (char*)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	s[--len] = '\0';
	while (len--)
	{
		s[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
