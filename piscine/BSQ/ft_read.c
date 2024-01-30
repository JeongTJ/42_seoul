/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:00:17 by inryu             #+#    #+#             */
/*   Updated: 2023/08/09 20:40:31 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	clear_buffer(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		buffer[i] = '\0';
		i++;
	}
}

char	*ft_file_input(char *file)
{
	int		fd;
	char	*buff;
	int		r;
	int		size;

	size = 512;
	while (1)
	{
		size *= 2;
		fd = open(file, 0);
		if (fd == -1)
			return (0);
		buff = (char *)malloc(sizeof(char) * (size + 1));
		if (!buff)
			return (0);
		clear_buffer(buff, size);
		r = read(fd, buff, size);
		close(fd);
		if (r != size)
			break ;
		free(buff);
	}
	return (buff);
}

char	*double_malloc(char *buff)
{
	int		size;
	char	*res;

	size = ft_strlen(buff);
	size *= 2;
	res = (char *)malloc(sizeof(char) * (size));
	if (!res)
		return (0);
	clear_buffer(res, size);
	ft_strcpy(res, buff);
	free(buff);
	return (res);
}

char	*ft_std_input(void)
{
	char	*buff;
	char	*temp;
	int		idx;
	int		temp_size;

	idx = 0;
	temp = (char *)malloc(sizeof(char) * (1));
	buff = (char *)malloc(sizeof(char) * (1024));
	clear_buffer(buff, 1024);
	while (1)
	{
		temp_size = read(0, temp, 1);
		if (!temp_size)
			break ;
		buff[idx++] = temp[0];
		if (ft_strlen(buff) == idx)
			buff = double_malloc(buff);
		if (!buff)
			return (0);
	}
	free(temp);
	return (buff);
}
