/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:53:04 by mobadiah          #+#    #+#             */
/*   Updated: 2024/02/10 20:48:40 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_background(t_image *map, int array[10][13]);
void	render_block(t_image *map, int x_pos, int y_pos);
void	render_player(t_image *player, int player_x, int player_y);


int	main()
{
	t_image	map;

	map = (t_image){};
	int array [10][13] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	map.mlx = mlx_init(50 * 13, 50 * 10, "minimap", true);
	map.background = mlx_new_image(map.mlx, 50 * 13, 50 * 10);
	mlx_image_to_window(map.mlx, map.background, 0, 0);
	render_background(&map, array);
	mlx_loop(map.mlx);
	return (0);
}

void	render_background(t_image *map, int array[10][13])
{
	int	x_pos;
	int	y_pos;
	int	i;
	int	j;

	i = -1;
	y_pos = 0;
	while (++i < 10)
	{
		j = -1;
		x_pos = 0;
		while (++j < 13)
		{
			if (array[i][j] == 1)
				render_block(map, x_pos, y_pos);
			else if (array[i][j] == 2)
				render_player(map, x_pos, y_pos);
			x_pos += 50;
		}
		y_pos += 50;
	}
}

void	render_block(t_image *map, int x_pos, int y_pos)
{
	int	i;
	int	j;

	i = x_pos;
	while (++i < x_pos + 50)
	{
		j = y_pos;
		while (++j < y_pos + 50)
			mlx_put_pixel(map->background, i, j, 0x00FF00FF);
	}
}

void	render_player(t_image *player, int player_x, int player_y)
{
	mlx_texture_t	*player_temp;

	printf("hihi hoho\n");
	player_temp = mlx_load_png("./SRC/player.png");
	player->player = mlx_texture_to_image(player->mlx, player_temp);
	mlx_delete_texture(player_temp);
	mlx_image_to_window(player->mlx, player->player, player_x, player_y);
}

// void	move_player_hook(mlx_key_data_t keydata, void *data)
// {
// 	t_image	*img;

// 	img = (t_image *) data;
// 	if (mlx_is_key_down(img->mlx, ))
// }
