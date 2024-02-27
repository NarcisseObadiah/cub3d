/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykerdel <ykerdel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:21:07 by mobadiah          #+#    #+#             */
/*   Updated: 2024/02/27 21:07:02 by ykerdel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/cub3d.h"

#include <ctype.h> /// goto .h
#include <string.h>
#include <stdio.h>

typedef struct s_data
{
	int f[3];
	int c[3];
} t_data; 

int string_to_int(char* str, int* output) {
    int i;
    int j;
    int sign;

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



// int main() {
//     char input[] = "    32";
//     int  result;
// 	t_data data;
	
//     int ret = get_rgb(&data, "1,2,3");
// 	dprintf(2, "ret = %d\n", ret);
// 	printf("r = %d\n", data.f[0]);
// 	printf("g = %d\n", data.f[1]);
// 	printf("b = %d\n", data.f[2]);
	
//     return 0;
// }
