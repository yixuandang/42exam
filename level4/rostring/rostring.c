/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 16:16:05 by ydang             #+#    #+#             */
/*   Updated: 2016/10/22 16:25:38 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		issp(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

int		main(int argc, char **argv)
{
	int		i;
	int		start;
	int		slen;

	if (argc > 1)
	{
		start = 0;
		while (issp(argv[1][start]) && argv[1][start] != '\0')
			start++;
		slen = 0;
		while (!issp(argv[1][start + slen]))
			slen++;
		i = start + slen;
		while (argv[1][i] != '\0')
		{
			while (issp(argv[1][i]) && argv[1][i] != '\0')
				i++;
			if (argv[1][i] == '\0')
				break ;
			if (argc == 0)
				write(1, " ", 1);
			argc = 0;
			while (!issp(argv[1][i]))
				write(1, argv[1] + i++, 1);
		}
		if (slen && argc == 0)
			write(1, " ", 1);
		write(1, argv[1] + start, slen);
	}
	write(1, "\n", 1);
	return (0);
}
