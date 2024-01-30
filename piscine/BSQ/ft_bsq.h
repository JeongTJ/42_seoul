/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:48:57 by tajeong           #+#    #+#             */
/*   Updated: 2023/08/09 18:22:48 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_position
{
	int		x;
	int		y;
	int		x_size;
	int		y_size;
	char	*e_o_f;
}	t_position;

char	*ft_strdup(char *str);
char	**ft_split(char *str, char *charset);
char	*ft_split_init(char *str, char *charset);
char	*ft_file_input(char *file);
char	*ft_std_input(void);

int		ft_find_char(char c, char *str);
int		ft_strlen(char *str);
int		ft_split_cnt(char *str, char *charset);
int		ft_is_valid(char **board);
int		ft_small_atoi(char *str);
int		ft_is_vaild_square(char **board, t_position *coor, int size);
int		ft_biggest_square(char **board, t_position *coor, int size);

void	ft_strcpy(char *dest, char *src);
void	ft_board_fill(char **board, t_position *coor, int size);
void	print_error(char *error_msg);
void	print_board(char **board, int x_size, int y_size);

#endif
