/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmyshko <vmyshko@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:21:53 by vmyshko           #+#    #+#             */
/*   Updated: 2024/03/25 17:23:25 by vmyshko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "MLX42.h"

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void ft_hook(void* param);
void ft_randomize(void* param);
#endif