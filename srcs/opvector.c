/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opvector.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:20:39 by mdauphin          #+#    #+#             */
/*   Updated: 2017/11/28 11:27:49 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_repere	mult_vector(t_repere *target, t_repere *target2)
{
	t_repere	new;

	new.x = target->x * target2->x;
	new.y = target->y * target2->y;
	new.z = target->z * target2->z;
	return (new);
}

t_repere	div_vector(t_repere *target, t_repere *target2)
{
	t_repere	new;

	new.x = target->x / target2->x;
	new.y = target->y / target2->y;
	new.z = target->z / target2->z;
	return (new);
}

t_repere	add_vector(t_repere *target, t_repere *target2)
{
	t_repere	new;

	new.x = target->x + target2->x;
	new.y = target->y + target2->y;
	new.z = target->z + target2->z;
	return (new);
}

t_repere	sous_vector(t_repere *target, t_repere *target2)
{
	t_repere	new;

	new.x = target->x - target2->x;
	new.y = target->y - target2->y;
	new.z = target->z - target2->z;
	return (new);
}

t_repere	crossproduct_vector(t_repere *target, t_repere *target2)
{
	t_repere	new;

	new.x = (target->y * target2->z) + (target->z * target2->y);
	new.y = (target->x * target2->z) + (target->z * target2->x);
	new.z = (target->y * target2->x) + (target->x * target2->y);
	return (new);
}

t_repere	op_by_double_vector(t_repere *target, double n, char *o)
{
	t_repere	new;

	new.x = 0;
	new.y = 0;
	new.z = 0;
	if (ft_strcmp(o, "*") == 0)
	{
		new.x = target->x * n;
		new.y = target->y * n;
		new.z = target->z * n;
	}
	else if (ft_strcmp(o, "/") == 0)
	{
		new.x = target->x / n;
		new.y = target->y / n;
		new.z = target->z / n;
	}
	else if (ft_strcmp(o, "-") == 0)
	{
		new.x = target->x - n;
		new.y = target->y - n;
		new.z = target->z - n;
	}
	else if (ft_strcmp(o, "+") == 0)
	{
		new.x = target->x + n;
		new.y = target->y + n;
		new.z = target->z + n;
	}
	return (new);
}

double		dotproduct_vector(t_repere *target, t_repere *target2)
{
	double	cos;

	cos = target->x * target2->x + target->y * target2->y +
		target->z * target2->z;
	return (cos);
}

void	norm_vector(t_repere *target)
{
	double		longueur;
	t_repere	new;

	new.x = pow(target->x, 2);
	new.y = pow(target->y, 2);
	new.z = pow(target->z, 2);
	longueur = sqrt(new.x + new.y + new.z);
	target->x = target->x / longueur;
	target->y = target->y / longueur;
	target->z = target->z / longueur;
}
