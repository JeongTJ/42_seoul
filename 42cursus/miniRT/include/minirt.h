/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:49:06 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/23 14:52:02 by tajeong          ###   ########.fr       */
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
t_list		*get_entity(t_list *entites, t_entity_type type);

/* parse_entity1.c */
t_list	*make_ambient(char *line, int idx);
t_list	*make_camera(char *line, int idx);
t_list	*make_light(char *line, int idx);

/* parse_entity2.c */
t_list	*make_sphere(char *line, int idx);
t_list	*make_plane(char *line, int idx);
t_list	*make_cylinder(char *line, int idx);

/* parse_valid_check1.c */
void		check_ambient(t_list *node);
void		check_camera(t_list *node);
void		check_light(t_list *node);

/* parse_valid_check2.c */
void		check_sphere(t_list *node);
void		check_plane(t_list *node);
void		check_cylinder(t_list *node);

#endif
