/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narcisse <narcisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:21:07 by mobadiah          #+#    #+#             */
/*   Updated: 2024/03/08 00:00:03 by narcisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/cub3d.h"

#include <ctype.h> /// goto .h
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define FLAG_1 (1 << 0)
#define FLAG_2 (1 << 1)
#define FLAG_3 (1 << 2)
#define FLAG_4 (1 << 3)
#define FLAG_5 (1 << 4)
#define FLAG_6 (1 << 5)
#define FLAG_7 (1 << 6)

typedef struct s_data
{
	char* path[4];
	int f[3];
	int c[3];
	char** map; // change to linked list
} t_data; 


typedef struct map_node
{
	char *map_line;
	struct map_node *next;
} t_map_node;

 //function to create a node  to save each
 // line of the map in a linked list
t_map_node *create_node(char *line)
{

	char *new_line;
	t_map_node *new_node;

	new_node = (t_map_node *)malloc(sizeof(t_map_node));
	if (!new_node)
		return(0);
	new_node->map_line = strdup(line);
	if (!new_node->map_line)
	{
		free(new_node);
		return (0);
	}
	new_line = strchr(new_node->map_line, "\n");
	if (new_line != NULL)
		*new_line = '\0';
	new_node->next = NULL;
	return (new_node);
}


//function to add a node to the linked list
void add_node(t_map_node **head, char *line)
{	
	t_map_node *current_node;
	t_map_node *new_node ; 

	new_node = create_node(line);
	if (*head == NULL)
		*head = new_node;
	else
	{
		current_node = *head;
		while (current_node->next != NULL)
			current_node = current_node->next;
	}
	current_node->next = new_node;
}

int get_map(t_map_node **map, char *str)
{
	// set the map
	// check
	// |__closed  (flood fill)
	// |__missing char
	// |__invalid char
	
	*map = NULL;

	char *line_start;
	char *ptr;
	
	*line_start = str;
	*ptr = str;
	while (*ptr != '\0')
	{
		if (*ptr == '\n')
		{
			*ptr != '\0'; //replace newline with null  terminate character
			add_node(map, line_start); //add line to the linked list
			line_start = ptr + 1; //Move to the next line
		}
		ptr++;
	}
	//Add the last line (if any) to the linked list
	if (line_start < ptr)
		add_node(map, line_start);
	return (0);
}



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
 
int get_rgb(t_data *data, char *str) // (int **val, char *str) // check
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

int get_path(char **path, char *str)
{
	int it;
	char *tmp;

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

int checker(t_data* data, char *line)
{
	while (line && *line && isspace(*line))
		line++;
	if (!(*line))
		return (0);
	if (!strncmp(line, "NO ", 3) && get_path(data->path[0], line + 3)) // norm
		return (FLAG_1);
	if (!strncmp(line, "SO ", 3) && get_path(data->path[1], line + 3)) // norm
		return (FLAG_2);
	if (!strncmp(line, "WE ", 3) && get_path(data->path[2], line + 3)) // norm
		return (FLAG_3);
	if (!strncmp(line, "EA ", 3) && get_path(data->path[3], line + 3)) // norm
		return (FLAG_4);
	if (!strncmp(line, "F ", 2) && get_path(data->f, line + 2)) // norm
		return (FLAG_5);
	if (!strncmp(line, "C ", 2) && get_path(data->c, line + 2)) // norm
		return (FLAG_6);
	return (FLAG_7);
}

int init(t_data* data, char *str)
{
	int flag;
	int ch_flag;
	char *tmp;

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
				;// error
			flag ^= ch_flag; // xor flag = flag <xor> ch_flag
			tmp = str;
		}
		if ((flag & FLAG_1) && (flag & FLAG_2) && (flag & FLAG_3) && (flag & FLAG_4) && (flag & FLAG_5) && (flag & FLAG_6))
			break;
		str++;
	}
	if (get_map(data->map, tmp))
		;// error
	return (); // good
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

