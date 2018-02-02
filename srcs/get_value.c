/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:34:38 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/31 02:39:35 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_sphere_value(t_coef *m, char **scene, int i)
{
	while (ft_strequ(scene[i], "SPHERE"))
	{
		if (ft_strequ(scene[i + 1], "\tnew :\n") == 0)
		{
			check_list(m);
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, 1));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, 4));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, 4));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, 4));
			m->objs->rayon = ft_atof(ft_strsub(scene[i + 6], 10, 4));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 7], 6, 4));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 8], 6, 4));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 9], 6, 4));
		}
		m->nb_mail++;
		m->objs->num_obj = m->nb_mail;
		i += 10;
		if (ft_strequ(scene[i], "\t------\n") == 0)
			break ;
	}
}

void	get_cylindre_value(t_coef *m, char **scene, int i)
{
	while (ft_strequ(scene[i], "CYLINDRE"))
	{
		if (ft_strequ(scene[i + 1], "\tnew :\n") == 0)
		{
			check_list(m);
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, 1));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, 4));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, 4));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, 4));
			m->objs->rayon = ft_atof(ft_strsub(scene[i + 6], 10, 4));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 7], 6, 4));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 8], 6, 4));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 9], 6, 4));
		}
		m->nb_mail++;
		m->objs->num_obj = m->nb_mail;
		i += 10;
		if (ft_strequ(scene[i], "\t------\n") == 0)
			break ;
	}
}

void	get_plan_value(t_coef *m, char **scene, int i)
{
	while (ft_strequ(scene[i], "PLAN"))
	{
		if (ft_strequ(scene[i + 1], "\tnew :\n") == 0)
		{
			check_list(m);
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, 1));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, 4));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, 4));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, 4));
			m->objs->nrml.x = ft_atof(ft_strsub(scene[i + 6], 13, 4));
			m->objs->nrml.y = ft_atof(ft_strsub(scene[i + 7], 13, 4));
			m->objs->nrml.z = ft_atof(ft_strsub(scene[i + 8], 13, 4));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 9], 6, 4));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 10], 6, 4));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 11], 6, 4));
		}
		m->nb_mail++;
		m->objs->num_obj = m->nb_mail;
		i += 12;
		if (ft_strequ(scene[i], "\t------\n") == 0)
			break ;
	}
}

void	get_cone_value(t_coef *m, char **scene, int i)
{
	while (ft_strequ(scene[i], "CONE"))
	{
		if (ft_strequ(scene[i + 1], "\tnew :\n") == 0)
		{
			check_list(m);
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, 1));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, 4));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, 4));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, 4));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 6], 6, 4));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 7], 6, 4));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 8], 6, 4));
		}
		m->nb_mail++;
		m->objs->num_obj = m->nb_mail;
		i += 9;
		if (ft_strequ(scene[i], "\t------\n") == 0)
			break ;
	}
}
