/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/16 16:38:04 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>

# define WIDTH 400
# define HEIGHT 400
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_Q 12
# define KEY_W 13
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_SUM 24
# define KEY_SUB 27
# define KEY_0 29
# define KEY_ESC 53
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define KEYPRESS 2
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ON_DESTROY 17

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
	t_data	**rotate_data;
	t_data	**image_data;
	t_data	*axis;
	t_data	*rotate_axis;
	t_data	*image_axis;
	t_data	*box;
	t_data	*rotate_box;
	t_data	*image_box;
	t_data	curr_coor;
	t_angle	angle;
	int		row_size;
	int		col_size;
	int		zoom_level;
	double	dx;
	double	dy;
	double	dz;
	int		flag;
}	t_info;

/* fdf_axis */
void	fdf_init_axis(t_info *info);
void	fdf_make_rotate_axis(t_info *info);
void	fdf_axis_projection(t_info *info);
void	fdf_draw_image_axis(t_info *info);

/* fdf_box */
void	fdf_init_box(t_info *info);
void	fdf_make_rotate_box(t_info *info);
void	fdf_box_projection(t_info *info);
void	fdf_draw_image_box(t_info *info);

/* fdf_circle */
void	fdf_circle(t_info *info);
void	fdf_circle2(t_info *info);

/* fdf_draw1 */
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	fdf_draw_line(t_image *image, t_data s_data, t_data e_data);
void	my_mlx_clear_image(t_image *image);
void	fdf_draw_image_data(t_info *info);

/* fdf_rotate */
void	fdf_rotate_alpha(t_data *rotate_data, double angle);
void	fdf_rotate_beta(t_data *rotate_data, double angle);
void	fdf_rotate_gamma(t_data *rotate_data, double angle);
void	fdf_projection(t_info *info);
void	fdf_cal_projection(t_info *info, t_data *rotate_data);

/* fdf_draw2 */
void	fdf_cal_image_data(t_info *info, \
							t_data *rotate_data, t_data *image_data);
void	fdf_make_image_data(t_info *info);
void	fdf_make_rotate_data(t_info *info);

/* fdf_hook1 */
int		key_hook(int keycode, t_info *info);
int		mouse_hook(int mouse, int x, int y, t_info *info);
int		auto_rotate(t_info *info);
int		fdf_mouse_tracking(int x, int y, t_info *info);

/* fdf_hook2 */
int		fdf_close(t_info *info);

/* fdf_key_move */
void	fdf_key_move(int keycode, t_info *info, int movement);
void	fdf_move_init(t_info *info);
void	fdf_rotate(t_info *info, int keycode, double dangle);

/* fdf_parsing */
void	fdf_parsing(t_info *info, char *file);

/* fdf_utils */
void	fdf_int_to_trgb(t_data *data);
void	fdf_trgv_to_int(t_data *data);
int		fdf_is_drawable(t_data data);
void	fdf_color_init(t_info *info);

/* fdf_init */
void	fdf_init(t_info *info, char *file);

#endif
