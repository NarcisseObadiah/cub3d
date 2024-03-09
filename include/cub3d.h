/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobadiah <mobadiah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:26:53 by mobadiah          #+#    #+#             */
/*   Updated: 2024/03/09 19:13:40 by mobadiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FLAG_1 (1 << 0)
# define FLAG_2 (1 << 1)
# define FLAG_3 (1 << 2)
# define FLAG_4 (1 << 3)
# define FLAG_5 (1 << 4)
# define FLAG_6 (1 << 5)
# define FLAG_7 (1 << 6)

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>

typedef struct s_data
{
	char		*path[4];
	int			f[3];
	int			c[3];
}	t_data;

typedef struct map_node
{
	char			*map_line;
	size_t			len;
	struct map_node	*next;
}	t_map_node;

//utils

int			is_valid(char c);
void		ft_error(char *str);
t_map_node	*create_node(char **line);
void		add_node(t_map_node **head, char **line);

#endif
