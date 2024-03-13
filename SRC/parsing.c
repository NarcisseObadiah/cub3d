/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:21:07 by mobadiah          #+#    #+#             */
/*   Updated: 2024/03/13 21:27:41 by mobadiah         ###   ########.fr       */
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
	while (str[i] && isspace(str[i])) /// create is space function
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
	while (str[i + j] && ft_isdigit(str[i + j]))
		*output = (*output * 10) + (str[i + j++] - '0');
	*output *= (sign + (sign == 0));
	if (!j && i == ft_strlen(str))
		return (-1);
	return (i + j);
}

int	get_rgb(int (*val)[3], char *str)
{
	int		i;
	char	*tmp;
	tmp = str;
	i = string_to_int(tmp, val[0]);
	if (!i || *(tmp + i) != ',' || *val[0] < 0 || *val[0] > 255)
		return (tmp - str);
	tmp += i + 1;
	i = string_to_int(tmp, val[1]);
	if (!i || *(tmp + i) != ',' || *val[1] < 0 || *val[1] > 255)
		return (tmp - str);
	tmp += i + 1;
	i = string_to_int(tmp, val[2]);
	if (!i || *val[2] < 0 || *val[2] > 255)
		return (tmp - str);
	tmp += i;
	while (*tmp && isspace(*tmp) && *tmp != '\n')
		tmp++;
	if (*tmp != '\0' && *tmp != '\n')
		return (tmp - str);
	return (-1);
}

int	get_path(char **path, char *str)
{
	int		it;
	char	*tmp;

	it = 0;
	while (str[it] && isspace(str[it]))
		it++;
	tmp = str + it;
	while (str[it] && !isspace(str[it]))
		it++;
	tmp += it;
	while (str[it] && isspace(str[it]))
		it++;
	if (str[it])
		return (0);
	*tmp = 0;
	*path = str;
	return (1);
}

//checker function to check and return the proper flag
int	checker(t_data *data, char *line)
{
	int	len;
	while (line && *line && isspace(*line))
		line++;
	if (!(*line))
		return (0); // empty
	if (!ft_strncmp(line, "NO ", 3) && get_path(&data->path[0], line + 3))
		return (FLAG_1);
	if (!ft_strncmp(line, "SO ", 3) && get_path(&data->path[1], line + 3))
		return (FLAG_2);
	if (!ft_strncmp(line, "WE ", 3) && get_path(&data->path[2], line + 3))
		return (FLAG_3);
	if (!ft_strncmp(line, "EA ", 3) && get_path(&data->path[3], line + 3))
		return (FLAG_4);
	if (!ft_strncmp(line, "F ", 2))
	{
		len = get_rgb(&data->f, line + 2);
		if (len == ft_strlen(line + 2))
			return (FLAG_5);
	}
	if (!ft_strncmp(line, "C ", 2))
	{
		len = get_rgb(&data->c, line + 2);
		if (len == ft_strlen(line + 2))
			return (FLAG_6);
	}
	return (FLAG_7); // error
}

int	init(t_data*data, char	*str)
{
	int		flag;
	int		ch_flag;
	char	*tmp;

	flag = 0;
	ch_flag = 0;
	tmp = str;
	while (str && *str)
	{
		if (*str == '\n')
		{
			*(str++) = 0;
			ch_flag = checker(data, tmp);
			if ((ch_flag & FLAG_7) || (flag & ch_flag))
				return (-1);
			flag ^= ch_flag;
			tmp = str;
		}
		if ((flag & FLAG_1) && (flag & FLAG_2) && (flag & FLAG_3)
			&& (flag & FLAG_4) && (flag & FLAG_5) && (flag & FLAG_6))
			break ;
		str++;
	}
	if (!((flag & FLAG_1) && (flag & FLAG_2) && (flag & FLAG_3)
			&& (flag & FLAG_4) && (flag & FLAG_5) && (flag & FLAG_6)))
		return (-1);
	if (get_map(data->map, tmp))
		return (-1);
	return (0);
}


// int	floodfield(t_data *data, )

//function to get the map by using a linked list
//which saved each readed line in a node, then put it in the linked list
//before pointing to the next line

int	get_map(t_map_node **map, char *str)
{
	char	*line_start;
	char	*ptr;
	int		plyer_count;

	line_start = 0;
	ptr = str;
	*map = NULL;
	plyer_count = 0;

	if (!str)
		return (-1);
	while (*ptr != '\0')
	{
		if (!is_valid(*ptr))
			return (-1);
		if (*ptr == 'N' || *ptr == 'E' || *ptr == 'W' || *ptr == 'S')
			plyer_count++;
		if (*ptr == '\n')
		{
			*ptr = '\0';
			add_node(map, &line_start);
			line_start = ptr + 1;
		}
		ptr++;
	}
	if (plyer_count != 1)
		return (-1);
	add_node(map, &line_start);
	flood_fill
	return (0);
}

int main()
{
    int rgb[3];
    char *str = "100,50,200\n";
    int result = get_rgb(&rgb, str);
    if (result != -1)
    {
        printf("RGB values: %d, %d, %d\n", rgb[0], rgb[1], rgb[2]);
    }
    else
    {
        printf("Error parsing RGB values\n");
    }
    return 0;
}
// int main() {
//     char *input = strdup("3234982 ");
// 	char *test;
//     int ret = get_path(&test, input);
// 	dprintf(2, "ret = %d\n", ret);
// 	dprintf(2, "test = <%s>\n", test);
//     return 0;
// }