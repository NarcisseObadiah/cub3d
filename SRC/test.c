#include <stdio.h>
#include <ctype.h>
#include <string.h>
# define FLAG_1 (1 << 0) // 0000001
# define FLAG_2 (1 << 1) // 0000010
# define FLAG_3 (1 << 2) // 0000100
# define FLAG_4 (1 << 3) // 0001000
# define FLAG_5 (1 << 4) // 0010000
# define FLAG_6 (1 << 5) // 0100000
# define FLAG_7 (1 << 6) // 1000000


// int	string_to_int(char *str, int *output)
// {
// 	int	i;
// 	int	j;
// 	int	sign;

// 	sign = 0;
// 	*output = 0;
// 	i = 0;
// 	j = 0;
// 	while (str[i] && isspace(str[i]))
// 		i++;
// 	if (str[i] == '+')
// 	{
// 		sign = 1;
// 		i++;
// 	}
// 	else if (str[i] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	while (str[i + j] && isdigit(str[i + j]))
// 		*output = (*output * 10) + (str[i + j++] - '0');
// 	*output *= (sign + (sign == 0));
// 	if (!j && i == strlen(str))
// 		return (-1);
// 	return (i + j);
// }

// int	get_rgb(int (*val)[3], char *str)
// {
// 	int		i;
// 	char	*tmp;

// 	tmp = str;
// 	i = string_to_int(tmp, &(*val)[0]);
// 	if (!i || *(tmp + i) != ',' || (*val)[0] < 0 || (*val)[0] > 255)
// 		return (tmp - str);
// 	tmp += i + 1;
// 	i = string_to_int(tmp, &(*val)[1]);
// 	if (!i || *(tmp + i) != ',' || (*val)[1] < 0 || (*val)[1] > 255)
// 		return (tmp - str);
// 	tmp += i + 1;
// 	i = string_to_int(tmp, &(*val)[2]);
// 	if (!i || (*val)[2] < 0 || (*val)[2] > 255)
// 		return (tmp - str);
// 	tmp += i;
// 	while (*tmp && isspace(*tmp) && *tmp != '\n')
// 		tmp++;
// 	if (*tmp != '\0' && *tmp != '\n')
// 		return (tmp - str);
// 	return (0);
// }

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


int main() {
    char *path;
    char *str = "    This_is_a_test_path";
    int result = get_path(&path, str);
    if (result == 1) {
        printf("Path: \"%s\"\n", path);
    } else {
        printf("Error: Invalid path format\n");
    }
    return 0;
}