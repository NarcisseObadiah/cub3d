
#include <ctype.h> /// goto .h
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct map_node
{
	char *map_line;
    size_t len;
	struct map_node *next;
} t_map_node; 

int is_valid(char c)
{
    return ((c == '0') || (c == '1') || (c == 'N') || 
            (c == 'S') || (c == 'E') || (c == 'O'));
}

t_map_node *create_node(char **line)
{
    char *new_line;
    t_map_node *new_node;

    new_node = (t_map_node *)malloc(sizeof(t_map_node));
    if (!new_node)
        return(0);
    new_node->map_line = *line;
    new_node->len = strlen(*line);
    return (new_node);
}

//function to add a node to the linked list

void add_node(t_map_node **head, char **line)
{	
	t_map_node *current_node;
	t_map_node *new_node;

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
    char *line_start;
    char *ptr;
    
    *map = NULL; 
    line_start = str;
    ptr = str;
    while (*ptr != '\0')
    {
        // if (!is_valid(*ptr))
        //     return(-1);
        if (*ptr == '\n')
        {
            *ptr = '\0'; //replace newline with null  terminate character
            add_node(map, &line_start); //add line to the linked list
            line_start = ptr + 1; //Move to the next line
        }
        ptr++;
    }
    //Add the last line (if any) to the linked list
    if (line_start < ptr)
        add_node(map, &line_start);
    return (0);
}

int main() {
    char *map_str = strdup("11111\n10E11\n10101");
    t_map_node *map = NULL;
    
    int result = get_map(&map, map_str);
    printf ("result =  %d\n", result);
    if (result == 0)
    {
        printf("Map created successfully\n");
        t_map_node *current = map;
        while (current != NULL)
        {
            printf("%s\n", current->map_line);
            current = current->next;
        }
    }
    else
        printf("Failed to create map\n");
    return 0;
}