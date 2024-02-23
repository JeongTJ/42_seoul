/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:49:06 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/23 15:16:20 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPE_H
# define MINIRT_TYPE_H

# define WIDTH 1920
# define HEIGHT 1080

typedef enum e_keys
{
	KEY_ESC = 53
}	t_keys;

typedef enum e_event
{
	KEYPRESS = 2,
	KEYRELEASE,
	BUTTONPRESS,
	BUTTONRELEASE,
	MOTIONNOTIFY,
	ENTERNOTIFY,
	LEAVENOTIFY,
	FOCUSIN,
	FOCUSOUT,
	KEYMAPNOTIFY,
	EXPOSE,
	GRAPHICSEXPOSE,
	NOEXPOSE,
	VISIBILITYNOTIFY,
	CREATENOTIFY,
	DESTROYNOTIFY,
	UNMAPNOTIFY,
	MAPNOTIFY,
	MAPREQUEST,
	REPARENTNOTIFY,
	CONFIGURENOTIFY,
	CONFIGUREREQUEST,
	GRAVITYNOTIFY,
	RESIZEREQUEST,
	CIRCULATENOTIFY,
	CIRCULATEREQUEST,
	PROPERTYNOTIFY,
	SELECTIONCLEAR,
	SELECTIONREQUEST,
	SELECTIONNOTIFY,
	COLORMAPNOTIFY,
	CLIENTMESSAGE,
	MAPPINGNOTIFY,
	GENERICEVENT,
	LASTEVENT
}	t_event;

typedef enum e_entity_type
{
	AMBIENT = 0,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_entity_type;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}	t_var;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_coor
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_coor;

typedef struct s_color
{
	int		color;
	double	t;
	double	r;
	double	g;
	double	b;
}	t_color;

typedef struct s_entity
{
	t_entity_type	type;
	t_coor			coor;
	t_coor			vec;
	t_color			color;
	double			radius;
	double			height;
	double			fov;
	double			brightness_ratio;
	double			lighting_ratio;
}	t_entity;

typedef struct s_info
{
	t_var		var;
	t_image		image;
	t_list		*entites;
	t_list		*ambient;
	t_list		*camera;
	t_list		*light;
	int			height;
	int			width;
	double		**m_a;
	double		**m_b;
	double		**m_c;
}	t_info;


#endif
