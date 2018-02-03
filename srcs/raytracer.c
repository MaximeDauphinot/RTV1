/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:16:41 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/08 17:32:14 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	light(t_coef *m)
{
	//double		color;
	double		cos;
	t_repere	rgb;

	if (m->objs->type != 3)
		m->objs->nrml = sous_vector(&m->objs->intsct, &m->objs->pos);
	m->light.LightDir = sous_vector(&m->light.LightPos, &m->objs->intsct);
	norm_vector(&m->objs->nrml);
	norm_vector(&m->light.LightDir);
	cos = dotproduct_vector(&m->light.LightDir, &m->objs->nrml);
	if (cos > 0)
	{
		rgb.x = m->objs->color.x * m->light.Coefdiff;
		rgb.y = m->objs->color.y * m->light.Coefdiff;
		rgb.z = m->objs->color.z * m->light.Coefdiff;
		rgb.x += m->light.color.x * cos * m->light.Coefdiff;
		rgb.y += m->light.color.y * cos * m->light.Coefdiff;
		rgb.z += m->light.color.z * cos * m->light.Coefdiff;
		return (rgbtohexa(rgb.x, rgb.y, rgb.z));
	}
	return (rgbtohexa(m->objs->color.x * m->light.LumosAmbiante,
				m->objs->color.y * m->light.LumosAmbiante, m->objs->color.z *
				m->light.LumosAmbiante));
}

static void	calc_ray(t_coef *m, int x, int y)
{
	double		Xindent;
	double		Yindent;
	t_repere	tmp;
	t_repere	tmp2;
	t_repere	tmp3;
	t_repere	tmp4;

	Xindent = m->ray.ViewPlaneWidth / (float)ResX;
	Yindent = m->ray.ViewPlaneHeight / (float)ResY;
	//Rayon lance en x y z
	tmp = op_by_double_vector(&m->ray.RightVec, (Xindent * x), "*");
	tmp2 = op_by_double_vector(&m->ray.UpVec, (Yindent * y), "*");
	tmp3 = sous_vector(&tmp, &tmp2);
	m->ray.VecDirRay = add_vector(&m->ray.ViewPlaneUpLeft, &tmp3);
	norm_vector(&m->ray.VecDirRay);
}

static void	fill_px(t_coef *m, int x, int y, int couleur)
{
	int		i;
	int		j;

	j = y;
	while (j < y + m->pixx)
	{
		i = x;
		while (i < x + m->pixx)
			put_pxl(m, i++, j, couleur);
		j++;
	}
}

static void	sort_obj(t_coef *m)
{
	if (m->objs->type == 1)
	{
		IntersectSphere(m);
	}
	else if (m->objs->type == 2)
	{
		IntersectCylindre(m);
	}
	else if (m->objs->type == 3)
	{
		Intersectplan(m);
	}
	else if (m->objs->type == 4)
	{
		IntersectCone(m);
	}
	else if (m->objs->type == 5)
	{
		IntersectSphere(m);
	}
}

void 	calc_intersect(t_coef *m)
{
	t_repere tmp;

	tmp = op_by_double_vector(&m->ray.VecDirRay, m->objs->t, "*");
	m->objs->intsct = add_vector(&m->ray.CamPos, &tmp);
}

/*static double	is_shadow(t_coef *m)
{
  t_repere	tmp;
  t_repere	tmp2;
  int 		couleur;


  tmp2 = m->ray.VecDirRay;
  m->ray.VecDirRay = sous_vector(&m->light.LightPos, &m->objs->intsct);
  tmp = m->ray.CamPos;
  m->ray.CamPos = m->objs->pos;
  sort_obj(m);
  if (m->objs->t >= 0)
  {
	m->ray.VecDirRay = tmp2;	
	m->ray.CamPos = tmp;
	couleur = 0x00;
	fill_px(m, x, y, couleur);
  }
  else
  {
  	m->ray.VecDirRay = tmp2;
  	m->ray.CamPos = tmp;
  	return (light(m));
  }
}*/
 
void 	check_dist(t_coef *m, int num_mail, int x, int y)
{
	double 		couleur;

	reboot_fast(m);
	while (m->objs->num_obj != num_mail)
		m->objs = m->objs->next;
	if (m->objs->t >= 0)
	{
		couleur = light(m);
		fill_px(m, x, y, couleur);
	}
	else
		fill_px(m, x, y, BLACK);
}

void	viewplane(t_coef *m)
{
	int			x;
	int			y;
	double		tmp;
	int 		num_mail;

	while (y < ResY)
	{
		x = 0;
		while (x < ResX)
		{
			tmp = 9999;
			reboot_fast(m);
			while (m->objs)
			{
				sort_obj(m);
				calc_ray(m, x, y);
				calc_intersect(m);
				if (m->objs->t >= 0 && m->objs->t <= tmp)
				{
					tmp = m->objs->t;
					num_mail = m->objs->num_obj;
				}
				m->objs = m->objs->next;		
			}
			check_dist(m, num_mail, x, y);
			x += m->pixx;
		}
		y += m->pixx;
	}
	mlx_put_image_to_window(m->mlx.mlx, m->mlx.win, m->mlx.img, 0, 0);
	mlx_string_put(m->mlx.mlx, m->mlx.win, 10, 10, 0xFFFFFF, "Press 'h' for help");
}
