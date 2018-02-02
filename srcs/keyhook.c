/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:59:17 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/22 18:11:59 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*void 	choose_obj(t_coef *m, int key)
{
	int  i; 
	if (key == 18)
		i = 1;
	else if (key == 19)
		i = 2;
	else if (key == 20)
		i = 3;
	else if (key == 21)
		i = 4;
	else if (key == 23)
		i = 5;
	else if (key == 22)
		i = 6;
	while (m->objs->num_obj != i)
}*/

int		ft_keyhook(int key, t_coef *m)
{
	//printf("%d\n", key);
	if (key == 53)
	{
		exit(EXIT_SUCCESS);
	}/*
	else if (key == 18 || key == 19 || key == 20
		|| key == 21 || key == 23 || key == 22 || key == 26 || key == 28)
	{
		reboot_fast(m);
		choose_obj(m, key);
	}
	printf("%d\n", key);

*/
	return (0);

}
/*int		ft_keyhook2(int key, t_coef *m)
{
	//printf("%d\n", key);
	if (key == 53)
	{
		closehelp(m);
	}
	return (0);
}

void	help(t_coef *m)
{
	if (m->open == 0)
	{
		m->open = 1;
		init_help(m);
		color_win_help(m);
		help_title(m);
		print_logo(m);
		mlx_key_hook(m->help.win, ft_keyhook2, m);
		mlx_loop(m->help.mlx);
	}
	else
		closehelp(m);

}

void	closehelp(t_coef *m)
{
	m->open = 0;
	mlx_clear_window(m->help.mlx, m->help.win);
	mlx_destroy_window(m->help.mlx, m->help.win);
}*/

int		redcross(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
