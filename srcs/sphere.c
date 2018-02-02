/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:57:22 by mdauphin          #+#    #+#             */
/*   Updated: 2017/12/18 18:41:06 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		IntersectSphere(t_coef *m)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
	double	t;

	a = pow(m->ray.VecDirRay.x, 2) + pow(m->ray.VecDirRay.y, 2) +
		pow(m->ray.VecDirRay.z, 2);
	b = 2 * (m->ray.VecDirRay.x * (m->ray.CamPos.x - m->objs->pos.x)
			+ m->ray.VecDirRay.y * (m->ray.CamPos.y - m->objs->pos.y)
			+ m->ray.VecDirRay.z *
			(m->ray.CamPos.z - m->objs->pos.z));
	c = (pow((m->ray.CamPos.x - m->objs->pos.x), 2) +
		pow((m->ray.CamPos.y - m->objs->pos.y), 2) +
		pow((m->ray.CamPos.z - m->objs->pos.z), 2)) -
		pow(m->objs->rayon, 2);
	delta = (b * b - 4 * a * c);
	if (delta > 0)
	{
		t1 = (-b + sqrt(delta)) / 2 * a;
		t2 = (-b - sqrt(delta)) / 2 * a;
		if (t1 < t2)
			t = t1;
		else
			t = t2;
	}
	else if (delta == 0)
		t = (-b / 2 * a);
	else if (delta < 0)
		t = -1;
	m->objs->t = t;
}

void		IntersectCylindre(t_coef *m)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
	double	t;

	a = pow(m->ray.VecDirRay.x, 2) + pow(m->ray.VecDirRay.z, 2);/* +
		pow(m->ray.VecDirRay.z, 2);*/
	b = 2 * (m->ray.VecDirRay.x * (m->ray.CamPos.x - m->objs->pos.x)
			+ m->ray.VecDirRay.y * (m->ray.CamPos.y - m->objs->pos.y)
			+ m->ray.VecDirRay.z *
			(m->ray.CamPos.z - m->objs->pos.z));
	c = (pow((m->ray.CamPos.x - m->objs->pos.x), 2) +
		pow((m->ray.CamPos.y - m->objs->pos.y), 2) +
		pow((m->ray.CamPos.z - m->objs->pos.z), 2)) -
		pow(m->objs->rayon/ 1.5, 2);
	delta = (b * b - 4 * a * c);
	if (delta > 0)
	{
		t1 = (-b + sqrt(delta)) / 2 * a;
		t2 = (-b - sqrt(delta)) / 2 * a;
		if (t1 < t2)
			t = t1;
		else
			t = t2;
	}
	else if (delta == 0)
		t = (-b / 2 * a);
	else if (delta < 0)
		t = -1;
	m->objs->t = t;
}

void		Intersectplan(t_coef *m)
{
	double	x;
	double	y;
	double	z;
	double	d;
	double	t;

	x = m->ray.CamPos.x - m->objs->pos.x;
	y = m->ray.CamPos.y - m->objs->pos.y;
	z = m->ray.CamPos.z - m->objs->pos.z;
	d = m->objs->pos.x + m->objs->pos.y + m->objs->pos.z;

	t = -((x * m->objs->nrml.x + y * m->objs->nrml.y +
			z * m->objs->nrml.z + d) / (m->objs->nrml.x *
				m->ray.VecDirRay.x + m->objs->nrml.y * m->ray.VecDirRay.y +
				m->objs->nrml.z * m->ray.VecDirRay.z));
	m->objs->t = t;
}

void		IntersectCone(t_coef *m)
{
	double	a;
	double	b;
	double	c;
	double	new_z;
	double	delta;
	double	t1;
	double	t2;
	double	t;

	new_z = 0.7 * m->ray.VecDirRay.y;
	a = pow(m->ray.VecDirRay.z, 2) + pow(m->ray.VecDirRay.x, 2) - pow(new_z, 2);
	b = 2 * ((m->ray.VecDirRay.z * (m->ray.CamPos.z - m->objs->pos.z))
			+ (m->ray.VecDirRay.x * (m->ray.CamPos.x - m->objs->pos.x))
			- (m->ray.CamPos.y - new_z * m->objs->pos.y));
	c = pow((m->ray.CamPos.z - m->objs->pos.z), 2) +
		pow((m->ray.CamPos.x - m->objs->pos.x), 2) -
		pow((m->ray.CamPos.y - m->objs->pos.y), 2);/* -
		pow(m->tube.radius/ 1.5, 2);*/
	delta = (b * b - 4 * a * c);
	if (delta > 0)
	{
		t1 = (-b + sqrt(delta)) / 2 * a;
		t2 = (-b - sqrt(delta)) / 2 * a;
		if (t1 < t2)
			t = t1;
		else
			t = t2;
	}
	else if (delta == 0)
		t = (-b / 2 * a);
	else if (delta < 0)
		t = -1;
	m->objs->t = t;
}
