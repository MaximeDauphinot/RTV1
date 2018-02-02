/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdauphin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:49:28 by mdauphin          #+#    #+#             */
/*   Updated: 2018/01/31 13:30:41 by mdauphin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define SPHERE 1
# define PLAN 2
# define CONE 3
# define CYLINDRE 4
# define SPOT 5
# define BLUE 0x0051FF
# define RED 0xFF0000
# define GREEN 0x46FF00
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREY 0xC7C7C7
# define YELLOW 0xF0FB00
# define ORANGE 0xF7C600
# define PI 3,141592653589793
# define ResX 1280
# define ResY 720
# define HelpX 800
# define HelpY 800
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2

typedef struct		s_draw
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				sl;
	int				endian;
	int				bpp;
}					t_draw;

typedef struct		s_help
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				sl;
	int				endian;
	int				bpp;
}					t_help;


typedef struct		s_repere
{
	double			x;
	double			y;
	double			z;
}					t_repere;

typedef struct		s_lumos
{
	t_repere		LightPos;
	t_repere		color;
	t_repere		LightDir;
	double			Coefdiff;
	double			LumosAmbiante;
	double			radius;
}					t_lumos;

typedef struct		s_obj
{
	int				num_obj;
	int				type;
	t_repere		pos; //Centre
	t_repere		intsct; //Intersection
	t_repere		nrml; //Normale
	t_repere		color; //Color
	double			CD; //Coefdiff
	double			CA; //Coefamb
	double			rayon;
	double			angle;
	double 			t;
	struct s_obj	*next;
	struct s_obj	*prev;
}					t_obj;

typedef struct		s_camera
{
	t_repere		RayRebond;
	t_repere		CamPos; // position de la camera
	t_repere		CameraLookAt; //point regarde
	t_repere		UpVec; // vecteur hauteur
	t_repere		VecDir; // direction du vecteur directeur unitaire de la camera
	t_repere		RightVec; // vecteur droit
	t_repere		VecDirRay; // rayon principal
	double			ViewPlaneWidth; // largeur du plan
	double			ViewPlaneHeight; // hauteur du plan
	double			ViewPlaneDist; // distance du viewplane a la camera
	t_repere		ViewPlaneUpLeft; // position du coin en haut a gauche
}					t_camera;

typedef struct		s_coef
{
	t_draw			mlx;
	t_camera		ray;
	t_obj			*objs;
	t_obj			*tmp_objs;
	t_lumos			light;
	int				nb_mail;
	t_help			help;
	int				pixx;
	int				pixy;
	int				open;
}					t_coef;

void				init_struct(t_coef *m);
int					ft_keyhook(int key, t_coef *m);
int					redcross(void);
void				put_pxl(t_coef *m, int x, int y, unsigned int color);
void				viewplane(t_coef *m);
void				IntersectSphere(t_coef *m);
void				Intersectplan(t_coef *m);
void				IntersectCylindre(t_coef *m);
void				IntersectCone(t_coef *m);
double				dotproduct_vector(t_repere *target, t_repere *target2);
double				rgbtohexa(int r, int g, int b);
void				norm_vector(t_repere *target);
t_repere			mult_vector(t_repere *target, t_repere *target2);
t_repere			div_vector(t_repere *target, t_repere *target2);
t_repere			add_vector(t_repere *target, t_repere *target2);
t_repere			sous_vector(t_repere *target, t_repere *target2);
t_repere			op_by_double_vector(t_repere *target, double n, char *o);
t_repere			crossproduct_vector(t_repere *target, t_repere *target2);
void				help(t_coef *m);
void				init_help(t_coef *m);
void				color_win_help(t_coef *m);
void				closehelp(t_coef *m);
void				help_title(t_coef *m);
void				print_logo(t_coef *m);
void				get_sphere_value(t_coef *m, char **scene, int i);
void				get_cylindre_value(t_coef *m, char **scene, int i);
void				get_plan_value(t_coef *, char **scene, int i);
void				get_cone_value(t_coef *m, char **scene, int i);
int					check_list(t_coef *m);
int					find_obj(t_coef *m, char **scene);
void				reboot_list(t_coef *m);
void				reboot_fast(t_coef *m);
int					init_list(t_obj **obj);
char				**ft_get_file(char *file);
void				print_list(t_coef *m);

#endif
