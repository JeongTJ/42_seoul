/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_type.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:49:06 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 07:38:35 by tajeong          ###   ########.fr       */
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

typedef struct s_ambient
{
	t_color			color;
	double			lighting_ratio;
}	t_ambient;

typedef struct s_camera
{
	t_coor			coor;
	t_coor			vec;
	double			fov;
}	t_camera;

typedef struct s_light
{
	t_coor			coor;
	double			brightness_ratio;
	t_color			color;
}	t_light;

typedef struct s_sphere
{
	t_coor			coor;
	double			radius;
	t_color			color;
}	t_sphere;

typedef struct s_plane
{
	t_coor			coor;
	t_coor			vec;
	t_color			color;
}	t_plane;

typedef struct s_cylinder
{
	t_coor			coor;
	t_coor			vec;
	double			radius;
	double			height;
	t_color			color;
}	t_cylinder;

typedef struct s_entity
{
	t_entity_type	type;
	void			*content;
}	t_entity;

typedef struct s_info
{
	t_var	var;
	t_image	image;
	t_list	*entites;
	int		height;
	int		width;
}	t_info;

#endif
