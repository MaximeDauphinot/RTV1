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
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, ft_check(scene, i, 2, 9)));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, ft_check(scene, i, 3, 12)));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, ft_check(scene, i, 4, 12)));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, ft_check(scene, i, 5, 12)));
			m->objs->rayon = ft_atof(ft_strsub(scene[i + 6], 10, ft_check(scene, i, 6, 10)));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 7], 6, ft_check(scene, i, 7, 6)));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 8], 6, ft_check(scene, i, 8, 6)));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 9], 6, ft_check(scene, i, 9, 6)));
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
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, ft_check(scene, i, 2, 9)));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, ft_check(scene, i, 3, 12)));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, ft_check(scene, i, 4, 12)));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, ft_check(scene, i, 5, 12)));
			m->objs->rayon = ft_atof(ft_strsub(scene[i + 6], 11, ft_check(scene, i, 6, 11)));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 7], 6, ft_check(scene, i, 7, 6)));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 8], 6, ft_check(scene, i, 8, 6)));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 9], 6, ft_check(scene, i, 9, 6)));
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
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, ft_check(scene, i, 2, 9)));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, ft_check(scene, i, 3, 12)));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, ft_check(scene, i, 4, 12)));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, ft_check(scene, i, 5, 12)));
			m->objs->nrml.x = ft_atof(ft_strsub(scene[i + 6], 13, ft_check(scene, i, 6, 13)));
			m->objs->nrml.y = ft_atof(ft_strsub(scene[i + 7], 13, ft_check(scene, i, 7, 13)));
			m->objs->nrml.z = ft_atof(ft_strsub(scene[i + 8], 13, ft_check(scene, i, 8, 13)));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 9], 6, ft_check(scene, i, 9, 6)));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 10], 6, ft_check(scene, i, 10, 6)));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 11], 6, ft_check(scene, i, 11, 6)));

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
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, ft_check(scene, i, 2, 9)));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, ft_check(scene, i, 3, 12)));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, ft_check(scene, i, 4, 12)));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, ft_check(scene, i, 5, 12)));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 6], 6, ft_check(scene, i, 6, 6)));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 7], 6, ft_check(scene, i, 7, 6)));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 8], 6, ft_check(scene, i, 8, 6)));
		}
		m->nb_mail++;
		m->objs->num_obj = m->nb_mail;
		i += 9;
		if (ft_strequ(scene[i], "\t------\n") == 0)
			break ;
	}
}

void	get_spot_value(t_coef *m, char **scene, int i)
{
	while (ft_strequ(scene[i], "SPOT"))
	{
		if (ft_strequ(scene[i + 1], "\tnew :\n") == 0)
		{
			check_list(m);
			m->objs->type = ft_atoi(ft_strsub(scene[i + 2], 9, ft_check(scene, i, 2, 9)));
			m->objs->pos.x = ft_atof(ft_strsub(scene[i + 3], 12, ft_check(scene, i, 3, 12)));
			m->objs->pos.y = ft_atof(ft_strsub(scene[i + 4], 12, ft_check(scene, i, 4, 12)));
			m->objs->pos.z = ft_atof(ft_strsub(scene[i + 5], 12, ft_check(scene, i, 5, 12)));
			m->objs->CA = ft_atof(ft_strsub(scene[i + 6], 20, ft_check(scene, i, 6, 20)));
			m->objs->CD = ft_atof(ft_strsub(scene[i + 7], 18, ft_check(scene, i, 7, 18)));
			m->objs->rayon = ft_atof(ft_strsub(scene[i + 8], 10, ft_check(scene, i, 8, 10)));
			m->objs->color.x = ft_atof(ft_strsub(scene[i + 9], 6, ft_check(scene, i, 9, 6)));
			m->objs->color.y = ft_atof(ft_strsub(scene[i + 10], 6, ft_check(scene, i, 10, 6)));
			m->objs->color.z = ft_atof(ft_strsub(scene[i + 11], 6, ft_check(scene, i, 11, 6)));
		}
		m->nb_mail++;
		m->objs->num_obj = m->nb_mail;
		i += 12;
		if (ft_strequ(scene[i], "\t------\n") == 0)
			break ;
	}
}
