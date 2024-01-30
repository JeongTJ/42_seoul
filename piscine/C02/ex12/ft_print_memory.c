/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 20:09:12 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/23 21:06:36 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putaddr(void *addr)
{
	char	add[16];
	int		idx;
	long	ad;

	ad = (long)addr;
	idx = 15;
	while (idx >= 0)
	{
		add[idx] = (char)(ad % 16 + '0');
		if (add[idx] > '9')
			add[idx] = add[idx] - '9' + 'a' - 1;
		ad /= 16;
		idx--;
	}
	write(1, add, 16);
	write(1, ": ", 2);
}

void	ft_put_ascii_code(char c, unsigned int size, unsigned int cnt)
{
	char	code[2];

	code[1] = (char)((unsigned char)c % 16 + '0');
	if (code[1] > '9')
		code[1] = code[1] - '9' + 'a' - 1;
	code[0] = (char)((unsigned char)c / 16 + '0');
	if (code[0] > '9')
		code[0] = code[0] - '9' + 'a' - 1;
	if (cnt < size)
		write(1, code, 2);
	else
		write(1, "  ", 2);
	if (cnt % 2 == 1)
		write(1, " ", 1);
}

void	ft_put_temp(char *temp, unsigned int size, unsigned int cnt)
{
	if (cnt % 16 != 15)
		return ;
	if (size <= cnt)
	{
		write(1, temp, size % 16);
		write(1, "\n", 1);
	}
	else
	{
		write(1, temp, 16);
		write(1, "\n", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	cnt;
	char			*str;
	char			temp[16];

	str = (char *)addr;
	cnt = 0;
	while (cnt < ((size - 1) / 16 + 1) * 16)
	{
		if (cnt < size)
		{
			temp[cnt % 16] = '.';
			if (32 <= *str && *str <= 126)
				temp[cnt % 16] = *str;
			if (cnt % 16 == 0)
				ft_putaddr(str);
		}
		ft_put_ascii_code(*str, size, cnt);
		ft_put_temp(temp, size, cnt);
		str++;
		cnt++;
	}
	return (addr);
}
