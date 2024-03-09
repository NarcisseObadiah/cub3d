/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:21:07 by mobadiah          #+#    #+#             */
/*   Updated: 2024/03/09 22:57:43 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	string_to_int(char *str, int *output)
{
	int	i;
	int	j;
	int	sign;

	sign = 0;
	*output = 0;
	i = 0;
	j = 0;
	while (str[i] && isspace(str[i]))
		i++;
	if (str[i] == '+')
	{
		sign = 1;
		i++;
	}
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i + j] && isdigit(str[i + j]))
		*output = (*output * 10) + (str[i + j++] - '0');
	*output *= (sign + (sign == 0));
	if (!j && i == strlen(str))
		return (-1);
	return (i + j);
}

// (int **val, char *str) // check      val[10, 1, 0]

int get_rgb(t_data *data, char *str)
{
	int		i;
	char	*tmp;
	tmp = str;
	i = string_to_int(tmp, &data->f[0]);
	if (!i || *(tmp + i) != ',' || data->f[0] < 0 || data->f[0] > 255)
		return (tmp - str); /// error
	tmp += i + 1;
	i = string_to_int(tmp, &data->f[1]);
	if (!i || *(tmp + i) != ',' || data->f[1] < 0 || data->f[1] > 255)
		return (tmp - str); /// error
	tmp += i + 1;
	i = string_to_int(tmp, &data->f[2]);
	if (!i || data->f[2] < 0 || data->f[2] > 255)
		return (tmp - str); /// error
	tmp += i;
	while (*tmp && isspace(*tmp) && *tmp != '\n')
		tmp++;
	if (*tmp != '\0' && *tmp != '\n')
		return (tmp - str); /// error
	return (-1); /// rgb should
}

//function to get the path 
int	get_path(char *path, char *str)
{
	int		it;
	char	*tmp;

	it = 0;
	while (str[it] && !isspace(str[it]))
		it++;
	tmp = str + it;
	while (str[it] && isspace(str[it]))
		it++;
	if (str[it])
		return (0);
	*tmp = 0;
	*path = str;
	return (1);
}

//checker function to check and return the proper flag
int	checker(t_data *data, char *line)															path["./path1","path2","path3","path4"]
																										[0]		[1]		[2]    [3]
																										
																								f[10, 23, 0]
																								c[2, 34, 234]
{
	while (line && *line && isspace(*line))
		line++;
	if (!(*line))
		return (0);
	if (!ft_strncmp(line, "NO ", 3) && get_path(data->path[0], line + 3))
		return (FLAG_1);
	if (!ft_strncmp(line, "SO ", 3) && get_path(data->path[1], line + 3))
		return (FLAG_2);
	if (!ft_strncmp(line, "WE ", 3) && get_path(data->path[2], line + 3))
		return (FLAG_3);
	if (!ft_strncmp(line, "EA ", 3) && get_path(data->path[3], line + 3))
		return (FLAG_4);
	if (!ft_strncmp(line, "F ", 2) && get_path(data->f, line + 2))
		return (FLAG_5);
	if (!ft_strncmp(line, "C ", 2) && get_path(data->c, line + 2))
		return (FLAG_6);
	return (FLAG_7);
}

// int	checker(t_data *data, char *line)
// {
// 	while (line && *line && isspace(*line))
// 		line++;
// 	if (!(*line))
// 		return (0);
// 	if (!ft_strncmp(line, "NO ", 3) && get_path(data->path[0], line + 3))
// 		return (FLAG_1);
// 	if (!ft_strncmp(line, "SO ", 3) && get_path(data->path[1], line + 3))
// 		return (FLAG_2);
// 	if (!ft_strncmp(line, "WE ", 3) && get_path(data->path[2], line + 3))
// 		return (FLAG_3);
// 	if (!ft_strncmp(line, "EA ", 3) && get_path(data->path[3], line + 3))
// 		return (FLAG_4);
// 	if (!ft_strncmp(line, "F ", 2) && get_path(data->f, line + 2))
// 		return (FLAG_5);
// 	if (!ft_strncmp(line, "C ", 2) && get_path(data->c, line + 2))
// 		return (FLAG_6);
// 	return (FLAG_7);
// }

//function to get the map by using a linked list
//which saved each readed line in a node, then put it in the linked list
//before pointing to the next line

int	get_map(t_map_node **map, char *str)
{
	char	*line_start;
	char	*ptr;

	line_start = 0;
	ptr = str;
	*map = NULL;
	while (*ptr != '\0')
	{
		if (*ptr == '\n')
		{
			*ptr = '\0';
			add_node(map, &line_start);
			line_start = ptr + 1;
		}
		else if (!is_valid(*ptr))
			return (-1);
		ptr++;
	}
	add_node(map, &line_start);
	return (0);
}

// int main() {
//     char input[] = "    32349822";
//     int  result;
// 	t_data data;
//     int ret = get_rgb(&data, "1,2,3");
// 	dprintf(2, "ret = %d\n", ret);
// 	printf("r = %d\n", data.f[0]);
// 	printf("g = %d\n", data.f[1]);
// 	printf("b = %d\n", data.f[2]);
//     return 0;
// }