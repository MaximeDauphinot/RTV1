/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:52:14 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/08 17:19:04 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*int		loop_hook(t_coef *m)
{
	mlx_hook(m->mlx.win, 17, 0L, redcross, m);
	mlx_key_hook(m->mlx.win, ft_keyhook, m);
	//viewplane(m);
	mlx_hook(m->mlx.win, KEY_PRESS, KEY_PRESS_MASK, (void *)ft_keyhook, m);
	//mlx_put_image_to_window(m->mlx.mlx, m->mlx.win, m->mlx.img, 0, 0);
	return (0);
}*/

int		main(int ac, char **av)
{
	t_coef m;
	char **tmp;
	int	i;

	i = 0;
	if (ac != 2)
		ft_putendl("Usage: ./RTV1 <filename.txt>");
	tmp = malloc(sizeof(av[1] + 1));
	tmp = ft_get_file(av[1]);
	find_obj(&m, tmp);
	reboot_list(&m);
	print_list(&m);
	init_struct(&m);
	viewplane(&m);
	mlx_hook(m.mlx.win, 17, 0L, redcross, &m);
	//mlx_key_hook(m.mlx.win, ft_keyhook, &m);
	//mlx_hook(m.mlx.win, KEY_PRESS, KEY_PRESS_MASK, (void *)ft_keyhook, &m);
	//mlx_loop_hook(m.mlx.mlx, loop_hook, &m);
	mlx_loop(m.mlx.mlx);
	free(tmp);
	return (0);
}
