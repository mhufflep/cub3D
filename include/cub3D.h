/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:49:35 by mhufflep          #+#    #+#             */
/*   Updated: 2021/04/01 03:51:28 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* standard headers */
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <math.h>
# define _USE_MATH_DEFINES

#include <pthread.h>
#include <semaphore.h> 
#include <sys/wait.h>


# include "mlx.h"
# include "libft.h"
# include "error.h"
# include "events.h"
# include "keycodes.h"
# include "settings.h"
# include "structures.h"

/* engine.c */
int 	start_engine(t_map *map, int mode);
int		stop_engine(void *ptr);


int		calculate_floor_color(t_all *all, int y);
int		calculate_skybox_color(t_all *all, int y);

/* Check input arguments */
int		check_save_arg(int argc, char **argv);
int		check_extension(t_map *map, const char *ext);
int		check_file_path(t_map *map, char *ext);

/* Check scene file */
void	parse_scene_file(t_map *prm, char *path);
int		parse_prm(t_map *map);
int		parse_map(t_map *map);
int		map_to_list(t_map *map);
void	map_validate(t_map *map);
int		map_getline(t_map *map);
void	parse_identify_line(t_map *map);
int		is_prm_complete(t_map *map);
void	print_status(char *title, char *name, char *status);
void	check_portal(t_map *map);
/* Errors.c */
char*	get_error_msg(t_error code);
void	throw_parse_error(t_error msg, char *add);
void	throw_engine_error(t_all *all, t_error msg, char *add);
void	print_error(char *msg, t_track *track, char *add);

/* get_next_line */
int		get_next_line(int fd, char **line);

/* arrays.c */
void	arr_delete(char **arr);
void	arr_fill(char **arr, t_list *lst);
void	arr_create(char ***arr, int rows, int cols);
int		arr_replace(char **arr, char to_replace, char replacer);

/* map.c */
void	free_map(t_map *map);
void	set_defaults(t_map *map);
t_map	*get_map(t_map *map);

/* flood fill */
int		flood_fill(char **arr, int x, int y);
void	flood_fill_iter(char **arr, int x, int y);
void	player_check(int count, int row, int col);


/* raycasting.c */
void	start_main_loop(t_all *all);
void    draw_walls(t_all *all);
int		render(t_all *all);


/* init.c */
void	init_all(t_all *all);
void	init_coord(t_all *all);
void	init_images(t_all *all);
void	init_window(t_all *all);
void	init_textures(t_all *all);
void	init_screen_size(t_all *all);
void	init_img(t_all *all, t_img *img);
void	init_v_dbls(t_all *all, int i, int j);
void	init_texture(t_all *all, char *path, t_texture *t);

void	init_bonus_flags(t_all *all);
void	init_shadow_params(t_all *all);


/* vector.c */
void    v_dbl_init(t_v_dbl *vect, double x, double y);
void	v_int_init(t_v_int *vect, int x, int y);
double  vector_mlp(t_v_dbl *v1, t_v_dbl *v2);
double  vector_len(t_v_dbl *v);
double  vector_angle(t_v_dbl *v1, t_v_dbl *v2);
void	vector_rotate(t_v_dbl *v, double angle);

/* key_action.c */
void	init_keys(t_all* all);
int		key_action(t_all *all);
int		key_release(int keycode, t_all *all);
int		key_press(int keycode, t_all *all);

/* engine_move.c */
void	rotate(t_all *all, int sign, double angle);
void	move(t_all *all, t_v_dbl *base, int sign);

/* colors.c */
int		color_make_lighter(double perc, int color);
int		color_make_darker(double perc, int color);
int		color_from_txt(t_texture *txt, int x, int y);
int		color_negative(int color);
int		color_from_prm(t_clr *clr);


/* angle_radian.c */
double	get_radian(double angle);
double	get_angle(double radian);


/* save */
void    make_screenshot(t_all *all);
void	bitmap_header(t_all *all, int fd);
void	bitmap_info_header(t_all *all, int fd);
char	*bitmap_check_exist(void);

void	init_sprites(t_all *all);
int		draw_all(t_all *all);
void	draw_background(t_all *all, int x);
void    fire(t_all *all);



/* music */
int     music_start(t_all *all, pid_t *x, char *filename, char *volume);
void    init_music(t_all *all, void *f(void *));
void*   init_music_fork(void * prm);
void*   init_wsound_fork(void * prm);
void*   init_sound_fork(void * prm);
void*   init_csound_fork(void * prm);

/* free */
void    free_all(t_all *all);


void	change_pos(t_all *all, char t);
void	remove_sprite(t_all *all, int x, int y);

#endif