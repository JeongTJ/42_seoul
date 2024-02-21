/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:49:06 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/22 08:24:43 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minirt_include.h"
# include "minirt_type.h"

/* hooks.c */
int			destroy_exit(t_info *info);
int			key_hook_f(int key, t_info *info);

/* parse.c */
int			parse(int argc, char *filename, t_info *info);

/* parse_list.c */
t_entity	*ft_entitynew(void *content, t_entity_type type);
void		ft_atod(char *str, int *idx, double *a, char *error_massage);
void		oneline_parsing(char *line, t_info *info);

/* utils.c */
void		error_manager(char *error_massage);

/* parse_entity1.c */
t_entity	*make_ambient(char *line);
t_entity	*make_camera(char *line);
t_entity	*make_light(char *line);

/* parse_entity2.c */
t_entity	*make_sphere(char *line);
t_entity	*make_plane(char *line);
t_entity	*make_cylinder(char *line);

/* parse_valid_check1.c */
void		check_ambient(t_list *node);
void		check_camera(t_list *node);
void		check_light(t_list *node);

/* parse_valid_check2.c */
void		check_sphere(t_list *node);
void		check_plane(t_list *node);
void		check_cylinder(t_list *node);

#endif
