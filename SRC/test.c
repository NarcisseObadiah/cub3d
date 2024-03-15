#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

# define FLAG_1 (1 << 0) // 0000001
# define FLAG_2 (1 << 1) // 0000010
# define FLAG_3 (1 << 2) // 0000100
# define FLAG_4 (1 << 3) // 0001000
# define FLAG_5 (1 << 4) // 0010000
# define FLAG_6 (1 << 5) // 0100000
# define FLAG_7 (1 << 6) // 1000000


typedef struct map_node
{
	char			*map_line;
	size_t			len;
	struct map_node	*next;
}	t_map_node;

int	is_valid(char c)
{
	return ((c == '0') || (c == '1') || (c == 'N')
		|| (c == 'S') || (c == 'E') || (c == 'W')
		|| (c == ' ') || (c == '\n'));
}

t_map_node	*create_node(char **line)
{
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
	if (head == NULL) // segf
	{

		*head = new_node;
dprintf(2, "test\n");
	}
	else
	{
		current_node = *head;
		while (current_node->next != NULL)
			current_node = current_node->next;
	}
	current_node->next = new_node;
}

int	get_map(t_map_node **map, char *str)
{
	char	*line_start;
	char	*ptr;
	int		plyer_count;
	int		coord[2];

	line_start = str;
	ptr = str;
	map = NULL;
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
	// fill(map, x, y, get_size(map));
	//flood_fill
	return (0);
}


int main() {
    char *map_str =strdup (
"111\n1W1\n111");

    t_map_node *map = NULL;
    if (get_map(&map, map_str) != 0) {
        printf("Error: Invalid map.\n");
        return 1;
    }

    // Print the map to verify it's correctly read
    t_map_node *current_node = map;
    while (current_node != NULL) {
        printf("%s\n", current_node->map_line);
        current_node = current_node->next;
    }

    return 0;
}
