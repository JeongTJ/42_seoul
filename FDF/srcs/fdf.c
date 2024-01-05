/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/05 20:39:29 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/fdf.h"

void	check_leak(void)
{
	system("leaks fdf");
}

//원하는 좌표에 해당하는 주소에 color값을 넣는 함수
void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (!(0 <= x && x < WIDTH && 0 <= y && y < HEIGHT))
		return ;
	dst = image->addr + \
	(y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_clear_image(t_image *image)
{
	int	col;
	int	row;

	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			my_mlx_pixel_put(image, col, row, 0x0);
			col++;
		}
		row++;
	}
}

int	key_hook(int keycode, t_info *info)
{
	ft_printf("keycode %d\n", keycode);
	if (keycode == KEY_SUM || keycode == KEY_SUB || \
		keycode == KEY_W || keycode == KEY_A || \
		keycode == KEY_S || keycode == KEY_D)
		fdf_move_data(info, keycode);
	else if (keycode == 15)
		fdf_move_init(info);
	else if (keycode == KEY_Z || keycode == KEY_X || keycode == KEY_C)
	{
		fdf_rotate(info, keycode);
		fdf_projection(info);
		fdf_move_init(info);
	}
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window(info->vars.mlx, info->vars.win);
		exit(0);
	}
	my_mlx_clear_image(&info->image);
	fdf_draw_image_data(info);
	mlx_put_image_to_window(info->vars.mlx, info->vars.win, \
							info->image.img, 0, 0);
	return (0);
}

int	fdf_close(t_info *info)
{
	mlx_destroy_window(info->vars.mlx, info->vars.win);
	exit(0);
	return (0);
}


void	fdf_init(t_info *info, char *file)
{
	fdf_parsing(info, file);
	info->vars.mlx = mlx_init();
	info->vars.win = mlx_new_window(info->vars.mlx, \
									WIDTH, HEIGHT, "Hellow World!");
	info->image.img = mlx_new_image(info->vars.mlx, \
									WIDTH, HEIGHT);
	info->image.addr = mlx_get_data_addr(info->image.img, \
								&info->image.bits_per_pixel, \
								&info->image.line_length, &info->image.endian);
	fdf_init_image_data(info);
	info->zoom_level = 1;
	info->angle.alpha = 0;
	info->angle.beta = 0;
	info->angle.gamma = 0;
	fdf_projection(info);
	fdf_move_init(info);
}

void	fdf_init_image_data(t_info *info)
{
	t_data	*one_image_line;
	int		col;
	int		row;

	row = 0;
	info->image_data = ft_calloc(info->row_size, sizeof(t_data *));
	if (info->image_data == NULL)
		exit(EXIT_FAILURE);
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			one_image_line = ft_calloc(info->col_size, sizeof(t_data));
			if (one_image_line == NULL)
				exit(EXIT_FAILURE);
			info->image_data[row] = one_image_line;
			col++;
		}
		row++;
	}
}


void	fdf_data_to_image_data(t_info *info)
{
	int		col;
	int		row;

	row = 0;
	while (row < info->row_size)
	{
		col = 0;
		while (col < info->col_size)
		{
			info->image_data[row][col].x = info->data[row][col].x;
			info->image_data[row][col].y = info->data[row][col].y;
			info->image_data[row][col].z = info->data[row][col].z;
			info->image_data[row][col].color = info->data[row][col].color;
			info->image_data[row][col].t = info->data[row][col].t;
			info->image_data[row][col].r = info->data[row][col].r;
			info->image_data[row][col].g = info->data[row][col].g;
			info->image_data[row][col].b = info->data[row][col].b;
			col++;
		}
		row++;
	}
	fdf_move_init(info);
}

int	main(int argc, char **argv)
{
	t_info	info;

	// atexit(check_leak);

	fdf_init(&info, argv[1]);
	if (argc == 1)
		argv[0] = argv[0];
	for (int i = 0; i < info.row_size; i++)
	{
		for (int j = 0; j < info.col_size; j++)
		{
			fdf_int_to_trgb(&info.data[i][j]);
			fdf_int_to_trgb(&info.image_data[i][j]);
		}
	}

	fdf_draw_image_data(&info);
	mlx_put_image_to_window(info.vars.mlx, info.vars.win, info.image.img, 0, 0);
	mlx_key_hook(info.vars.win, key_hook, &info);
	mlx_hook(info.vars.win, ON_DESTROY, 0, fdf_close, &info);
	mlx_loop(info.vars.mlx);
	return (0);
}
