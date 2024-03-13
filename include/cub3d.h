/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:26:53 by mobadiah          #+#    #+#             */
/*   Updated: 2024/03/13 15:06:36 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FLAG_1 (1 << 0) // 0000001
# define FLAG_2 (1 << 1) // 0000010
# define FLAG_3 (1 << 2) // 0000100
# define FLAG_4 (1 << 3) // 0001000
# define FLAG_5 (1 << 4) // 0010000
# define FLAG_6 (1 << 5) // 0100000
# define FLAG_7 (1 << 6) // 1000000

// '&'        conditions
// '^' or '|' to set ur values

// # include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>

typedef struct map_node
{
	char			*map_line;
	size_t			len;
	struct map_node	*next;
}	t_map_node;

typedef struct s_data
{
	char		*path[4];
	int			f[3];
	int			c[3];
	t_map_node	*map;
}	t_data;

//utils

int			is_valid(char c);
void		ft_error(char *str);
t_map_node	*create_node(char **line);
void		add_node(t_map_node **head, char **line);

#endif
