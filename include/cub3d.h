/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:26:53 by mobadiah          #+#    #+#             */
/*   Updated: 2024/03/25 16:13:41 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdbool.h>
# define FOV 0.66
# define ROT 0.02
# define MV	0.02
#define MAP_HEIGHT 5
#define MAX_LINE_LENGTH 10

typedef struct s_vectors
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_map_data
{
	char			**map;
	char			**raw;
	char			*texture[4];
	short			floor[3];
	short			ceil[3];
	unsigned short	height;
	unsigned short	width;
}	t_map_data;

//utils
void	ft_error(char *str);
void	open_file(char *file, int *fd, char **content);
void	ft_free(char **str);

//parsing
void	get_raw(char *file, t_map_data *map_data);
void	check_params(t_map_data	*map_data, char params[6][4]);
void	get_textures_path(t_map_data *map_data, char paths[4][4]);
void	check_valid_rgb(t_map_data *map_data);


// typedef struct s_gane_data
// {
// 	mlx_t		*mlx;
// 	mlx_image_t	*img;
// 	t_vector	vectors[4];
// 	t_map_data	map_data;
// }	t_game_data;

#endif
