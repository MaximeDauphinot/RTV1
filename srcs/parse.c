/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 02:19:17 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/31 13:57:45 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char	**ft_get_file(char *file)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*keep;
	char	**result;

	ret = 0;
	tmp = ft_strnew(1);
	keep = ft_strnew(0);
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	while ((ret = read(fd, tmp, 1)) > 0)
		keep = ft_strjoin_clean(&keep, &tmp);
	if (!(result = ft_strsplit(keep, '\n')))
		return (NULL);
	ft_strdel(&tmp);
	ft_strdel(&keep);
	if ((close(fd)) == -1)
		return (NULL);
	return (result);
}

int	init_list(t_obj **obj)
{
	t_coef *m;

	if (!(*obj = (t_obj *)malloc(sizeof(t_obj))))
			return (-1);
	(*obj)->prev = NULL;
	(*obj)->next = NULL;
	(*obj)->num_obj = 0;
	(*obj)->pos.x = 0;
	(*obj)->pos.y = 0;
	(*obj)->pos.z = 0;
	(*obj)->intsct.x = 0;
	(*obj)->intsct.y = 0;
	(*obj)->intsct.z = 0;
	(*obj)->nrml.x = 0;
	(*obj)->nrml.y = 0;
	(*obj)->nrml.z = 0;
	(*obj)->color.x = 0;
	(*obj)->color.y = 0;
	(*obj)->color.z = 0;
	(*obj)->CA = 0;
	(*obj)->CD = 0;
	(*obj)->rayon = 0;
	(*obj)->angle = 0;
	(*obj)->t = 0;
	return (0);
}

int		check_list(t_coef *m)
{
	if (m->nb_mail != 0)
	{
		m->tmp_objs = m->objs;
		init_list(&m->objs->next);
		m->objs = m->objs->next;
		m->objs->prev = m->tmp_objs;
	}
	else if (m->nb_mail == 0)
	{
		if ((m->objs = (t_obj *)malloc(sizeof(t_obj))) != NULL)
		{	
			m->objs->prev = NULL;
			m->objs->next = NULL;
		}
	}
	return (0);
}

int 	ft_check(char **str, int i, int j, int k)
{
	int a;

	a = 0;
	while (str[i + j][k++] != '\n')
		a++;
	return (a);
}

void	reboot_list(t_coef *m)
{
	while (m->objs->prev != NULL)
		m->objs = m->objs->prev;
	m->tmp_objs = m->objs;
}

void	reboot_fast(t_coef *m)
{
	m->objs = m->tmp_objs;
}

int		find_obj(t_coef *m, char **scene)
{
	int		i;

	i = 0;
	m->nb_mail = 0;
	while (scene[i])
	{
		if (ft_strequ(scene[i], "SPHERE"))
		{
			get_sphere_value(m, scene, i);
		}
		else if (ft_strequ(scene[i], "CYLINDRE"))
		{
			get_cylindre_value(m, scene, i);
		}
		else if (ft_strequ(scene[i], "PLAN"))
		{
			get_plan_value(m, scene, i);
		}
		else if (ft_strequ(scene[i], "CONE"))
		{
			get_cone_value(m, scene, i);
		}
		else if (ft_strequ(scene[i], "SPOT"))
		{
			get_spot_value(m, scene, i);
		}
		i++;
	}
	return (0);
}
