/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 21:48:07 by mhufflep          #+#    #+#             */
/*   Updated: 2021/03/26 23:33:02 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_window(t_all *all)
{
	all->mlx = mlx_init();
	if (!all->mlx)
		throw_parse_error(ERR_MLX_WIN_FAIL, 0);
	init_screen_size(all);
	if (all->screen == 0)
	{
		all->win = mlx_new_window(all->mlx, all->map->w, all->map->h, "cub3D");
		if (!all->win)
			throw_parse_error(ERR_MLX_WIN_FAIL, 0);
	}
}

void	init_img(t_all *all, t_img *img)
{
	img->img = mlx_new_image(all->mlx, all->map->w, all->map->h);
	if (!img->img)
		throw_parse_error(ERR_MLX_IMG_FAIL, 0);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
	if (!img->addr)
		throw_parse_error(ERR_MLX_IMG_FAIL, 0);
}

void	init_texture(void *mlx, char *path, t_texture *t)
{
	t_img *img;

	img = &t->img; 
	img->img = mlx_xpm_file_to_image(mlx, path, &t->w, &t->h);
	if (!img->img)
		throw_parse_error(ERR_MLX_TXT_FAIL, path);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->len, &img->end);
	if (!img->addr)
		throw_parse_error(ERR_MLX_TXT_FAIL, path);
}

void	init_anim_texture(t_all *all, t_texture *txt)
{
	int i;
	char *file;
	char *num;
	char *path;
	char arr[5];
	
	i = 0;

	while (i < 5)
	{
		num = ft_itoa(i);
		file = ft_strjoin(num, ".xpm");
		path = ft_strjoin(all->map->WP_path, file);
		init_texture(all->mlx, path, &txt[i]);
		free(num);
		free(file);
		free(path);
		i++;
	}
}

void	init_textures(t_all *all)
{
	init_texture(all->mlx, all->map->NO_path, &all->no);
	init_texture(all->mlx, all->map->SO_path, &all->so);
	init_texture(all->mlx, all->map->WE_path, &all->we);
	init_texture(all->mlx, all->map->EA_path, &all->ea);
	init_texture(all->mlx, all->map->sprite, &all->s1);
	if (all->map->bonus)
	{
		init_texture(all->mlx, all->map->AS_path, &all->s2);
		init_texture(all->mlx, all->map->FT_path, &all->flr);
		init_texture(all->mlx, all->map->SK_path, &all->sky);

		init_anim_texture(all, all->wpn);
		// init_texture(all->mlx, "textures/oblivion/bow0.xpm", &(all->wpn[0]));
		// init_texture(all->mlx, "textures/oblivion/bow1.xpm", &(all->wpn[1]));
		// init_texture(all->mlx, "textures/oblivion/bow2.xpm", &(all->wpn[2]));
		// init_texture(all->mlx, "textures/oblivion/bow3.xpm", &(all->wpn[3]));
		// init_texture(all->mlx, "textures/oblivion/bow4.xpm", &(all->wpn[4]));
		
		// init_texture(all->mlx, all->map->WF_path, &all->fire);
	}
}

void	init_screen_size(t_all *all)
{
	#ifdef LINUX
		mlx_get_screen_size(all->mlx, &all->screen_w, &all->screen_h);
	#else
		mlx_get_screen_size(&all->screen_w, &all->screen_h);
	#endif
	if (all->screen == 0)
	{
		if (all->map->h > all->screen_h)
			all->map->h = all->screen_h;
		if (all->map->w > all->screen_w)
			all->map->w = all->screen_w;
	}
	else
	{
		if (all->map->h > 20000)
			all->map->h = 20000;
		if (all->map->w > 20000)
			all->map->w = 20000;
	}
}