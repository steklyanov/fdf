#ifndef FDF_HEADER
# define FDF_HEADER

#include "minilibx_macos/mlx.h"
#include "libft/libft.h"
#include <unistd.h>

#define IMAGE_WIDTH 1000
#define IMAGE_HEIGHT 1000
#define SIZE_LEN 1000

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
void		draw_line(t_map *map, int x1, int y1, int x2, int y2, char *image_data);
void    put_point_to_image(char *image_data, int x, int y, int color);
void		draw_map(t_map *map, char *image_data);


#endif