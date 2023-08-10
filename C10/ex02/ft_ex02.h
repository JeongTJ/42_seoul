/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:24:06 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 14:01:27 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EX02_H
# define FT_EX02_H
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <fcntl.h>
# include <stdlib.h>

int		print_error(char *error_msg, char *command, char *file);
int		ft_tail(char **argv, int N, int idx, int *flag);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_init(int size);
void	print_tail(int flag, char *file);
int		print_not_file(int N);

#endif
