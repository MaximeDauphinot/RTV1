/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:23:48 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/08 15:41:28 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		rgbtohexa(int r, int g, int b)
{
	double	color;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void		put_pxl(t_coef *m, int x, int y, unsigned int color)
{
	int		i;

	if (x < ResX && x >= 0 && y < ResY && y >= 0)
	{
		i = (x * 4) + (y * m->mlx.sl);
		m->mlx.data[i] = color;
		m->mlx.data[++i] = color >> 8;
		m->mlx.data[++i] = color >> 16;
	}
}

void	color_win_help(t_coef * m)
{
	int x;
	int y;

	x = 0;
	while (x <= HelpX)
	{
		y = 0;
		while (y <= HelpY)
		{
			mlx_pixel_put(m->help.mlx, m->help.win, x, y, WHITE);
			y++;
		}
		x++;
	}
}
