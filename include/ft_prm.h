/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhufflep <mhufflep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 06:02:52 by mhufflep          #+#    #+#             */
/*   Updated: 2021/02/12 19:36:40 by mhufflep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRM_H
# define FT_PRM_H

# define R_MAX_LEN 6

typedef struct		s_prm
{
	unsigned int 	r_width;
	unsigned int 	r_height;
	char			*NO_texture;
	char			*SO_texture;
	char			*WE_texture;
	char			*EA_texture;
}					t_prm;

#endif