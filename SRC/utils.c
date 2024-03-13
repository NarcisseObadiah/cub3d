/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 04:20:24 by mobadiah          #+#    #+#             */
/*   Updated: 2024/03/13 16:33:29 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putstr(str);
}

int	is_valid(char c)
{
	return ((c == '0') || (c == '1') || (c == 'N')
		|| (c == 'S') || (c == 'E') || (c == 'W')
		|| (c == ' ') || (c == '\n'));
}
//function to create a node  to save each
//line of the map in a linked list

t_map_node	*create_node(char **line)
{
	char		*new_line;
	t_map_node	*new_node;

	new_node = (t_map_node *)malloc(sizeof(t_map_node));
	if (!new_node)
		return (NULL);
	new_node->map_line = *line;
	new_node->len = strlen(*line);
	new_node->next = NULL;
	return (new_node);
}

//function to add a node to the linked list

void	add_node(t_map_node **head, char **line)
{
	t_map_node	*current_node;
	t_map_node	*new_node;

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

// int main() {
//     char *map_str = strdup("11011r11\n10E11\n10101");
//     t_map_node *map = NULL;
//     int result = get_map(&map, map_str);
//     printf ("result =  %d\n", result);
//     if (result == 0)
//     {
//         printf("Map created successfully\n");
//         t_map_node *current = map;
//         while (current != NULL)
//         {
//             printf("%s, len = %zu \n", current->map_line, current->len);
//             current = current->next;
//         }
//     }
//     else
//         printf("Failed to create map\n");
//     // Free the memory allocated by strdup
//     free(map_str);
//     return 0;
// }
