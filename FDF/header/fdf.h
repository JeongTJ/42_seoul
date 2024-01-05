/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/05 19:56:24 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080
// # define DELTA 10000
# define KEY_ESC 53
# define ON_DESTROY 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_SUM 69
# define KEY_SUB 78
# define KEY_L_S_BRACKETS 33
# define KEY_R_S_BRACKETS 53
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8

typedef struct s_data
{
	double	x;
	double	y;
	double	z;
	double	t;
	double	r;
	double	g;
	double	b;
	int		color;
}	t_data;

typedef struct s_angle
{
	double	alpha;
	double	beta;
	double	gamma;
}	t_angle;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_info
{
	t_vars	vars;
	t_image	image;
	t_data	**data;
	t_data	**image_data;
	t_angle	angle;
	int		row_size;
	int		col_size;
	int		zoom_level;
}	t_info;



void	fdf_draw_reactangle(t_image *img, t_data s_data, int width, int height);
void	fdf_draw_line(t_image *img, t_data s_data, t_data e_data);
void	fdf_draw_triangle(t_image *img, t_data s_data, \
							t_data m_data, t_data e_data);
void	fdf_draw_circle(t_image *img, t_data center_data, int size);

void	fdf_draw_image_data(t_info *info);
void	fdf_move_data(t_info *info, int keycode);
void	fdf_move_one_data(t_info *info, t_data *image_data, int keycode, \
							int move_scalse);
void	fdf_move_init(t_info *info);

void	fdf_parsing(t_info *info, char *file);
void	fdf_set_data_size(t_info *info, t_list *data_lst);
void	fdf_init_info_data(t_info *info);
void	fdf_input_data(t_info *info, t_list *data_lst);
int		fdf_atoi_base(char *str, char *base);

void	fdf_int_to_trgb(t_data *data);
void	fdf_trgv_to_int(t_data *data);

int		fdf_is_drawable(t_data data);

void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	fdf_init_image_data(t_info *info);
void	fdf_projection(t_info *info);
void	fdf_cal_projection(t_info *info, t_data *image_data, t_data *data);
void	fdf_rotate(t_info *info, int keycode);

void	fdf_data_to_image_data(t_info *info);
#endif
