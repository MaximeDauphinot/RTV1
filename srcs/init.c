/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:11:20 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/08 16:30:51 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	init_light(t_coef *m)
{
	m->light.LightPos.x = 5.0;
	m->light.LightPos.y = 5.0;
	m->light.LightPos.z = 40.0;
	m->light.Coefdiff = 0.4;
	m->light.LumosAmbiante = 0.35;
	m->light.color.x = 255;
	m->light.color.y = 255;
	m->light.color.z = 255;
	m->light.radius = 2;
}

static void	init_camera(t_coef *m)
{
	t_repere	tmp;
	t_repere	tmp2;
	t_repere	tmp3;
	t_repere	tmp4;

	//vecteur unitaire directeur
	m->ray.VecDir = sous_vector(&m->ray.CameraLookAt, &m->ray.CamPos);
	norm_vector(&m->ray.VecDir);
	//vecteur droit
	m->ray.RightVec = crossproduct_vector(&m->ray.VecDir, &m->ray.UpVec);
	norm_vector(&m->ray.RightVec);
	//point en haut a gauche
	tmp  = op_by_double_vector(&m->ray.VecDir, m->ray.ViewPlaneDist, "*");
	tmp2 = op_by_double_vector(&m->ray.UpVec, (m->ray.ViewPlaneHeight /
				(float)2), "*");
	tmp3 = op_by_double_vector(&m->ray.RightVec, (m->ray.ViewPlaneWidth/
				(float)2), "*");
	tmp4 = add_vector(&tmp, &tmp2);
	tmp = add_vector(&m->ray.CamPos, &tmp4);
	m->ray.ViewPlaneUpLeft = sous_vector(&tmp, &tmp3);
	norm_vector(&m->ray.ViewPlaneUpLeft);
}


static void	init_image(t_coef *m)
{
	m->mlx.img = mlx_new_image(m->mlx.mlx, ResX, ResY);
	m->mlx.data = mlx_get_data_addr(m->mlx.img, &m->mlx.bpp, &m->mlx.sl,
			&m->mlx.endian);
}

static void	init_help_image(t_coef *m)
{
	m->help.img = mlx_new_image(m->help.mlx, HelpX, HelpY);
	m->help.data = mlx_get_data_addr(m->help.img, &m->help.bpp, &m->help.sl,
			&m->help.endian);
}

void		init_help(t_coef *m)
{
	m->help.mlx = mlx_init();
	m->help.win = mlx_new_window(m->help.mlx, HelpX, HelpY, "HELP");
	init_help_image(m);
}

void	init_struct(t_coef *m)
{
	m->mlx.mlx = mlx_init();
	m->mlx.win = mlx_new_window(m->mlx.mlx, ResX, ResY, "RTV1");
	m->ray.CamPos.x = 0.0;
	m->ray.CamPos.y = 0.0;
	m->ray.CamPos.z = 0.0;
	m->ray.CameraLookAt.x = 0.0;
	m->ray.CameraLookAt.y = 0.0;
	m->ray.CameraLookAt.z = 20.0;
	m->ray.UpVec.x = 0.0;
	m->ray.UpVec.y = 1.0;
	m->ray.UpVec.z = 0.0;
	m->ray.ViewPlaneDist = 1.0;
	m->ray.ViewPlaneHeight = 0.5;
	m->ray.ViewPlaneWidth = 0.85;
	m->pixx = 1;
	m->pixy = 1;
	m->open = 0;
	init_camera(m);
	init_light(m);
	init_image(m);
}
