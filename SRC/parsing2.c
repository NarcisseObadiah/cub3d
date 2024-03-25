/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 05:14:41 by mobadiah          #+#    #+#             */
/*   Updated: 2024/03/25 16:18:17 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// function to get the  beginning of the  map or his ending

short	get_begin_or_end(t_map_data *map_data)
{
	unsigned short	i;
	unsigned short	j;
	int				found_one;

	i = 0;
	while (map_data->raw[i])
	{
		j = 0;
		found_one = 0;
		while (map_data->raw[i][j] == ' ' || map_data->raw[i][j] == '1')
		{
			if (found_one == 0 && map_data->raw[i][j] == '1')
				found_one = 1;
			j++;
		}
		if (found_one == 1 && map_data->raw[i][j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

// typedef unsigned short t_ushort;


// short	get_begin_or_end(t_map_data *map_data)
// {
// 	static t_ushort	i;
// 	t_ushort		j;
// 	bool			has_one;

// 	has_one = false;
// 	while (map_data->raw[i])
// 	{
// 		j = 0;
// 		while (map_data->raw[i][j] == ' ' || map_data->raw[i][j] == '1')
// 		{
// 			if (has_one == false && map_data->raw[i][j] == '1')
// 				has_one = true;
// 			j++;
// 		}
// 		if (has_one && map_data->raw[i][j] == '\0')
// 			return (i++);
// 		i++;
// 	}
// 	return (-1);
// }

void check_openings(t_map_data *map_data) {
    short i, j;

    // Check if map_data is NULL
    if (map_data == NULL || map_data->height <= 0) {
        ft_error("Invalid map data");
    }

    // Check map boundaries
    for (i = 0; i < map_data->height; i++) {
        if (map_data->map[i] == NULL || strlen(map_data->map[i]) < map_data->width - 1) {
            ft_error("Invalid map data: Row length mismatch");
        }

        if (map_data->map[i][0] != '1' || map_data->map[i][map_data->width - 2] != '1') {
            ft_error("Invalid map data: Map not surrounded by walls");
        }
    }

    // Check for openings in the middle of the map
    for (i = 1; i < map_data->height - 1; i++) {
        for (j = 1; j < map_data->width - 2; j++) {
            printf("Checking cell (%d, %d)\n", i, j); // Print statement for debugging
            if (map_data->map[i][j] == '0' &&
                (map_data->map[i - 1][j] == ' ' ||
                 map_data->map[i][j - 1] == ' ' ||
                 map_data->map[i + 1][j] == ' ' ||
                 map_data->map[i][j + 1] == ' ')) {
                ft_error("Invalid map data: Map has openings");
            }
        }
    }
}



int main() {
    // Example map data
    char *map_data[MAP_HEIGHT] = {
        "11111",
        "10001",
        "10101",
        "10001",
        "11111"
    };

    // Initialize map data structure
    t_map_data data;
    data.height = MAP_HEIGHT;
    for (int i = 0; i < MAP_HEIGHT; i++) {
        data.map[i] = map_data[i];
    }

    // Test check_openings function
    check_openings(&data);

    printf("Map is valid\n");

    return 0;
}