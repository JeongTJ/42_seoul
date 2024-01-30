/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 19:12:11 by tajeong           #+#    #+#             */
/*   Updated: 2023/07/23 21:37:36 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_make_hex_table(char *str)
{
	char	idx;

	idx = '0';
	while (idx <= '9')
		*str++ = idx++;
	idx = 'a';
	while (idx <= 'f')
		*str++ = idx++;
}

void	ft_putstr_non_printable(char *str)
{
	char			hex_code[16];
	unsigned char	extends_ascii;

	ft_make_hex_table(hex_code);
	while (1)
	{
		extends_ascii = (unsigned char)*str;
		if (*str == '\0')
			break ;
		if (32 <= extends_ascii && extends_ascii <= 126)
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex_code[extends_ascii / 16]);
			ft_putchar(hex_code[extends_ascii % 16]);
		}
		str++;
	}
}
