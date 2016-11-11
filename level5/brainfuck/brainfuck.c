/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:31:33 by ydang             #+#    #+#             */
/*   Updated: 2016/11/11 15:44:09 by ydang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*initmem(void)
{
	int		sizetab;
	int		i;
	char	*mem;

	sizetab = 5000;
	i = 0;
	mem = (char*)malloc(sizeof(char) * sizetab + 1);
	while (i < sizetab)
	{
		mem[i] = 0;
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

int		isbf(char c)
{
	if (c == '+' || c == '-' || c == '<' || c == '>' || c == '[' || c == ']' || c == '.')
		return (1);
	return (0);
}

void	brainfuck(char *code, char *mem)
{
	int		c;
	int		i;
	int		loop;

	c = 0;
	i = 0;
	while (code[c])
	{
		if (isbf(code[c]))
		{
			if (code[c] == '>')
				i++;
			if (code[c] == '<')
				i--;
			if (code[c] == '.')
				ft_putchar(mem[i]);
			if (code[c] == '+')
				mem[i]++;
			if (code[c] == '-')
				mem[i]--;
			if (code[c] == ']')
			{
				loop = 1;
				while (loop)
				{
					c--;
					if (code[c] == ']')
						loop++;
					if (code[c] == '[')
						loop--;
				}
				c--;
			}
			if (code[c] == '[')
			{
				if (mem[i] == 0)
				{
					loop = 1;
					while (loop)
					{
						c++;
						if (code[c] == '[')
							loop++;
						else if (code[c] == ']')
							loop--;
					}
				}
			}
		}
		c++;
	}
}

int		main(int argc, char **argv)
{
	char	*mem;

	if (argc == 2)
	{
		mem = initmem();
		brainfuck(argv[1], mem);
	}
	else
		write(1, "\n", 1);
	return (0);
}
