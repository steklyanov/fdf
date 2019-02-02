#ifndef FDF_HEADER
# define FDF_HEADER

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <unistd.h>

typedef struct  s_point
{
    int         x;
    int         y;
    int         z;
    int         color;
}               t_point;


// typedef struct  s_map
// {
//     int         **line;
// };

typedef struct  s_map
{
    int         count_col;
    int         count_line;
    int         **line;
}               t_map;

int         *ft_pridumat_name(char *str);

#endif