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

void            ft_pridumat_name(char *str, t_map *map);
int			    ft_abs(int a);
void		    draw_line(t_map *map, int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr);


#endif