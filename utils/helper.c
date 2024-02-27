/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:21:07 by mobadiah          #+#    #+#             */
/*   Updated: 2024/02/27 20:26:21 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


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



// int main() {
//     char input[] = "    32";
//     int  result;
//     int ret = string_to_int(input, &result);
// dprintf(2, "ret = %d\n", ret);
// 	if (ret == -1) {
//         printf("No input.\n");
// 	}
//     else if (ret != strlen(input)){
//         printf("Conversion failed.\n");
//     }
//     else {
//         printf("Conversion successful. Result: %d\n", result);
// 	}
//     return 0;
// }
