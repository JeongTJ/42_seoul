/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ex03.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 22:52:12 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/06 14:01:52 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EX03_H
# define FT_EX03_H
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>
# include <fcntl.h>
# include <stdlib.h>

char	**ft_init(void);
int		ft_hexdump(char **file, char ***buff, int *size, int mod);
void	ft_repeat(int argc, char **argv, int mod);
void	ft_no_file(int mod);
int		ft_strcmp(char *s1, char *s2);
int		ft_is_c(char *str);
int		print_error(char *error_msg, char *command, char *file);
int		ft_strlen(char *str);
void	ft_end_of_file(char *str, int size, int mod);
void	ft_print_buff(char ***buff, int size, int mod);
void	ft_print_memory(char *str, int size, int len, int mod);
void	ft_print_last(char *str, int len);
void	ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_int_to_hex(int size, int mod);
char	*ft_char_to_hex(char c);

#endif
