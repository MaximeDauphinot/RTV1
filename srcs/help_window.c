/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:44:39 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/09 13:31:48 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	help_title(t_coef *m)
{
	int	x;
	int	y;

	x = 0;
	while (x <= HelpX)
	{
		y = 100;
		while(y <= 102)
		{
			mlx_pixel_put(m->help.mlx, m->help.win, x, y, BLACK);
			y++;
		}
		x++;
	}
}

void	print_logo(t_coef *m)
{
	int	a;
	int	b;
	void *img;

	a = 100;
	b = 100;
	img = mlx_xpm_file_to_image(m->help.mlx, "./pics/42.xpm", &a, &b);
	mlx_put_image_to_window(m->help.mlx, m->help.win, img, 700, 0);
}

/*void	42_logo(t_coef *m)
{
	int	x;
	int	y;

	x = 0;
	while (x <= HelpX)
	{
		y = 100;
		while(y <= 102)
		{
			mlx_pixel_put(m->help.mlx, m->help.win, x, y, BLACK);
			y++;
		}
		x++;
	}
}*/
